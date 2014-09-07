/******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Baldur Karlsson
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

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
    public partial class PixelShadeGraph : DockContent
    {
        private const int nodeWidth = 250;
        private const int nodeHeight = 175;
        private const int spaceWidth = 40;
        private const int spaceHeight = 275;

        public class PixelTreeNode
        {
            public uint eventID = 0;

            public FetchDrawcall draw = null;

            public List<PixelTreeNode> sources = new List<PixelTreeNode>();

            public FetchTexture res = null;

            public int layer = 0;
            public int index = 0;

            public int globalindex = 0;
        };

        private PixelTreeNode root = null;
        private Core m_Core = null;
        private Point point = Point.Empty;

        public PixelShadeGraph(Core c, PixelTreeNode n, Point p)
        {
            InitializeComponent();

            m_Core = c;
            root = n;
            point = p;

            maxlayer = SetLayers(root, 1);

            layers = new List<PixelTreeNode>[maxlayer+1];
            for (int i = 0; i <= maxlayer; i++)
                layers[i] = new List<PixelTreeNode>();

            AssignLayers(root);
            
            widestlayer = 0;
            for (int i = 0; i <= maxlayer; i++)
                widestlayer = Math.Max(widestlayer, layers[i].Count);

            bottomcentres = new List<Point>[maxlayer + 1];
            topcentres = new List<Point>[maxlayer + 1];
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

            render.Size = new Size((nodeWidth + spaceWidth) * (widestlayer + 1), (nodeHeight + spaceHeight) * (maxlayer + 1));

            for (int i = 0; i < paintdata.Length; i++)
            {
                Color col = HSLColor(GetHueForNode(i, paintdata.Length), 1.0f, 0.75f);

                paintdata[i] = new PaintData();

                paintdata[i].b = new SolidBrush(col);

                paintdata[i].p = new Pen(col, 4.0f);
                paintdata[i].p.CustomStartCap = new AdjustableArrowCap(5, 5);
            }
        }

        private List<PixelTreeNode>[] layers = null;
        private List<Point>[] bottomcentres = null;
        private List<Point>[] topcentres = null;
        private bool filled = false;
        private int widestlayer = 0;
        private int maxlayer = 0;
        private int globalindex = 0;

        class PaintData
        {
            public Brush b = null;
            public Pen p = null;
        };

        PaintData[] paintdata = new PaintData[16];

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

                    node.draw = m_Core.GetDrawcall(m_Core.CurFrame, node.eventID);

                    globalindex++;
                }
                
                layers[node.layer].Add(node);
            }

            foreach (var s in node.sources)
                AssignLayers(s);
        }

        private float GetHueForNode(int i, int total)
        {
            int idx = ((i + 1) * 21) % total; // space neighbouring colours reasonably distinctly
            return (float)idx / (float)total;
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
            // mondo hack
            if (!filled)
                DoPaint(e.Graphics);

            DoPaint(e.Graphics);

            if (writeToFile)
            {
                writeToFile = false;

                string fileName = "ShadeGraph_export.png";
                using (Bitmap bmp = new Bitmap(render.Size.Width, render.Size.Height))
                {
                    using (Graphics graphic = Graphics.FromImage(bmp))
                    {
                        graphic.FillRectangle(Brushes.White, new Rectangle(0, 0, render.Size.Width, render.Size.Height));
                        DoPaint(graphic);
                    }
                    bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                }
            }
        }

        private void DoPaint(Graphics g)
        {
            g.SmoothingMode = SmoothingMode.AntiAlias;

            Pen strokePen = new Pen(Brushes.Black, 4.0f);
            Font labelFont = new Font(FontFamily.GenericSerif, 14.0f, FontStyle.Bold);

            StringFormat stringfmt = new StringFormat();

            stringfmt.LineAlignment = StringAlignment.Far;
            stringfmt.Alignment = StringAlignment.Center;

            g.DrawString(String.Format("Shade graph for {0} ({1}, {2}) - {3}x{4}",
                         root.res.name, point.X, point.Y, render.Size.Width, render.Size.Height),
                         labelFont, Brushes.Black, new PointF(0, 0));

            int totalWidth = (nodeWidth + spaceWidth) * widestlayer;

            if (filled)
            {
                for (int l = 0; l <= maxlayer; l++)
                {
                    for (int i = 0; i < layers[l].Count; i++)
                    {
                        Point from = topcentres[l][i];

                        foreach (var s in layers[l][i].sources)
                        {
                            Point to = bottomcentres[s.layer][s.index];

                            g.DrawLine(paintdata[layers[l][i].globalindex % paintdata.Length].p, from, to);
                        }
                    }
                }
            }

            for (int l = maxlayer; l >= 0; l--)
            {
                int layerwidth = layers[l].Count;

                int x = spaceWidth;
                int y = spaceHeight/2 + (maxlayer - l) * (nodeHeight + spaceHeight);

                if (layerwidth < widestlayer)
                {
                    int extra = (nodeWidth + spaceWidth) * (widestlayer - layerwidth);

                    x += extra / 2;
                }

                for (int i = 0; i < layers[l].Count; i++)
                {
                    g.FillRectangle(paintdata[layers[l][i].globalindex % paintdata.Length].b, new Rectangle(x, y, nodeWidth, nodeHeight));
                    g.DrawRectangle(strokePen, new Rectangle(x, y, nodeWidth, nodeHeight));

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
                        /*
                        string drawname = draw.parent.name;

                        for (uint preveid = draw.eventID - 1; preveid > draw.previous.eventID; preveid--)
                        {
                            var prevdraw = m_Core.GetDrawcall(m_Core.CurFrame, preveid);
                            if (prevdraw != null)
                            {
                                drawname = prevdraw.name;
                                break;
                            }
                        }*/
                        name = String.Format("Contribution from EID {0} - {1}", layers[l][i].eventID, layers[l][i].draw.name);
                    }

                    g.DrawString(name, labelFont, Brushes.Black, rect, stringfmt);

                    if (!filled)
                    {
                        bottomcentres[l][i] = new Point(x + nodeWidth / 2, y + nodeHeight + (int)(strokePen.Width * 0.5f));
                        topcentres[l][i] = new Point(x + nodeWidth / 2, y - (int)(strokePen.Width * 0.5f));
                    }

                    x += nodeWidth + spaceWidth;
                }
            }

            filled = true;

            strokePen.Dispose();
            stringfmt.Dispose();
        }

        private void PixelShadeGraph_FormClosed(object sender, FormClosedEventArgs e)
        {
            for (int i = 0; i < paintdata.Length; i++)
            {
                paintdata[i].b.Dispose();
                paintdata[i].p.Dispose();
            }
        }
    }
}
