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

namespace renderdocui.Windows.Dialogs
{
    public partial class PixelHistorTree : DockContent
    {
        public PixelHistorTree()
        {
            InitializeComponent();
        }

        private void render_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.Red, new Rectangle(250, 250, 500, 500));
        }
    }
}
