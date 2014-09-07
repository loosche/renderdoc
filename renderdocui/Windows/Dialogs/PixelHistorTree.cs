using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;
using renderdocui.Code;
using renderdoc;
using System.Drawing.Drawing2D;

namespace renderdocui.Windows.Dialogs
{
    public partial class PixelHistorTree : DockContent
    {
        public class PixelTreeNode
        {
            public uint eventID = 0;

            public List<PixelTreeNode> sources = new List<PixelTreeNode>();

            public FetchTexture res = null;

            public int layer = 0;
            public int index = 0;

            public int globalindex = 0;
        };

        private PixelTreeNode root = null;
        private Core m_Core = null;

        public PixelHistorTree(Core c, PixelTreeNode n)
        {
            InitializeComponent();

            m_Core = c;
            root = n;

            maxlayer = SetLayers(root, 1);

            layers = new List<PixelTreeNode>[maxlayer+1];
            for (int i = 0; i <= maxlayer; i++)
                layers[i] = new List<PixelTreeNode>();

            AssignLayers(root);
            
            widestlayer = 0;
            for (int i = 0; i <= maxlayer; i++)
                widestlayer = Math.Max(widestlayer, layers[i].Count);
        }

        private List<PixelTreeNode>[] layers = null;
        private int widestlayer = 0;
        private int maxlayer = 0;
        private int globalindex = 0;

        private int SetLayers(PixelTreeNode node, int layer)
        {
            int ret = 0;

            if (node.sources.Count > 0) ret = layer;

            foreach (var s in node.sources)
            {
                s.layer = Math.Max(s.layer, layer);
                ret = Math.Max(ret, SetLayers(s, layer + 1));
            }

            return ret;
        }

        private void AssignLayers(PixelTreeNode node)
        {
            if (!layers[node.layer].Contains(node))
            {
                node.index = layers[node.layer].Count;
                if (node.globalindex == 0)
                {
                    node.globalindex = globalindex;
                    globalindex++;
                }
                
                layers[node.layer].Add(node);
            }

            foreach (var s in node.sources)
                AssignLayers(s);
        }

        private float GetHueForNode(int i)
        {
            int idx = ((i + 1) * 21) % 16; // space neighbouring colours reasonably distinctly
            return (float)(idx) / 16.0f;
        }

        // from https://gist.github.com/mjijackson/5311256
        private float CalcHue(float p, float q, float t)
        {
            if (t < 0) t += 1;
            if (t > 1) t -= 1;

            if (t < 1.0f / 6.0f)
                return p + (q - p) * 6.0f * t;

            if (t < 0.5f)
                return q;

            if (t < 2.0f / 3.0f)
                return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;

            return p;
        }

        private Color HSLColor(float h, float s, float l)
        {
            float r, g, b;

            if (s == 0)
            {
                r = g = b = l; // achromatic
            }
            else
            {
                var q = l < 0.5 ? l * (1 + s) : l + s - l * s;
                var p = 2 * l - q;
                r = CalcHue(p, q, h + 1.0f / 3.0f);
                g = CalcHue(p, q, h);
                b = CalcHue(p, q, h - 1.0f / 3.0f);
            }

            return Color.FromArgb(255, (int)(r * 255), (int)(g * 255), (int)(b * 255));
        }

        private bool writeToFile = false;

        private void render_Paint(object sender, PaintEventArgs e)
        {
            DoPaint(e.Graphics);

            if (writeToFile)
            {
                writeToFile = false;

                string fileName = "T:/tmp/PixelHistorTree_test.png";
                using (Bitmap bmp = new Bitmap(3000, 4000))
                {
                    using (Graphics graphic = Graphics.FromImage(bmp))
                    {
                        DoPaint(graphic);
                    }
                    bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                }
            }
        }

        private void DoPaint(Graphics g)
        {
            const int nodeWidth = 250;
            const int nodeHeight = 175;
            const int spaceWidth = 40;
            const int spaceHeight = 275;

            g.SmoothingMode = SmoothingMode.AntiAlias;

            Pen strokePen = new Pen(Brushes.Black, 4.0f);
            Font labelFont = new Font(FontFamily.GenericSerif, 14.0f, FontStyle.Bold);

            int totalWidth = (nodeWidth + spaceWidth) * widestlayer;

            var bottomcentres = new List<Point>[maxlayer+1];
            var topcentres = new List<Point>[maxlayer+1];
            for (int i = 0; i <= maxlayer; i++)
            {
                bottomcentres[i] = new List<Point>();
                topcentres[i] = new List<Point>();

                for (int w = 0; w < widestlayer; w++)
                {
                    bottomcentres[i].Add(new Point(0, 0));
                    topcentres[i].Add(new Point(0, 0));
                }
            }

            for (int hackhack = 0; hackhack < 2; hackhack++)
            {
                for (int l = maxlayer; l >= 0; l--)
                {
                    int layerwidth = layers[l].Count;

                    int x = spaceWidth;
                    int y = spaceHeight + (maxlayer - l) * (nodeHeight + spaceHeight);

                    if (layerwidth < widestlayer)
                    {
                        int extra = (nodeWidth + spaceWidth) * (widestlayer - layerwidth);

                        x += extra / 2;
                    }

                    for (int i = 0; i < layers[l].Count; i++)
                    {
                        if (hackhack == 1)
                        {
                            Color c = HSLColor(GetHueForNode(layers[l][i].globalindex), 1.0f, 0.75f);

                            using(Brush b = new SolidBrush(c))
                                g.FillRectangle(b, new Rectangle(x, y, nodeWidth, nodeHeight));
                            g.DrawRectangle(strokePen, new Rectangle(x, y, nodeWidth, nodeHeight));

                            StringFormat fmt = new StringFormat();

                            fmt.LineAlignment = StringAlignment.Far;
                            fmt.Alignment = StringAlignment.Center;

                            var rect = new RectangleF(x, y, nodeWidth, nodeHeight);
                            rect.Inflate(new SizeF(-4.0f, -4.0f));

                            string name = "";
                            if (layers[l][i].res != null)
                            {
                                if (layers[l][i].eventID == 0)
                                    name = layers[l][i].res.name;
                                else
                                    name = String.Format("{0} at EID {1}", layers[l][i].res.name, layers[l][i].eventID);
                            }
                            else
                            {
                                var draw = m_Core.GetDrawcall(m_Core.CurFrame, layers[l][i].eventID);

                                string drawname = draw.parent.name;

                                for (uint preveid = draw.eventID - 1; preveid > draw.previous.eventID; preveid--)
                                {
                                    var prevdraw = m_Core.GetDrawcall(m_Core.CurFrame, preveid);
                                    if (prevdraw != null)
                                    {
                                        drawname = prevdraw.name;
                                        break;
                                    }
                                }
                                name = String.Format("Contribution from EID {0} - {1}", layers[l][i].eventID, drawname);
                            }

                            g.DrawString(name, labelFont, Brushes.Black, rect, fmt);
                        }

                        bottomcentres[l][i] = new Point(x + nodeWidth / 2, y + nodeHeight + (int)(strokePen.Width*0.5f));
                        topcentres[l][i] = new Point(x + nodeWidth / 2, y - (int)(strokePen.Width*0.5f));

                        x += nodeWidth + spaceWidth;
                    }
                }

                if (hackhack == 0)
                {
                    for (int l = 0; l <= maxlayer; l++)
                    {
                        for (int i = 0; i < layers[l].Count; i++)
                        {
                            Point from = topcentres[l][i];

                            Color c = HSLColor(GetHueForNode(layers[l][i].globalindex), 1.0f, 0.75f);

                            Pen linePen = new Pen(c, 4.0f);
                            linePen.CustomStartCap = new AdjustableArrowCap(5, 5);

                            foreach (var s in layers[l][i].sources)
                            {
                                Point to = bottomcentres[s.layer][s.index];

                                g.DrawLine(linePen, from, to);
                            }

                            linePen.Dispose();
                        }
                    }
                }
            }

            strokePen.Dispose();
        }
    }
}
