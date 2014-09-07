namespace renderdocui.Windows.Dialogs
{
    partial class PixelHistorTree
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.parent = new System.Windows.Forms.Panel();
            this.render = new System.Windows.Forms.Panel();
            this.parent.SuspendLayout();
            this.SuspendLayout();
            // 
            // parent
            // 
            this.parent.AutoScroll = true;
            this.parent.Controls.Add(this.render);
            this.parent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.parent.Location = new System.Drawing.Point(0, 0);
            this.parent.Name = "parent";
            this.parent.Size = new System.Drawing.Size(292, 273);
            this.parent.TabIndex = 0;
            // 
            // render
            // 
            this.render.BackColor = System.Drawing.Color.White;
            this.render.Location = new System.Drawing.Point(0, 0);
            this.render.Name = "render";
            this.render.Size = new System.Drawing.Size(3000, 4000);
            this.render.TabIndex = 0;
            this.render.Paint += new System.Windows.Forms.PaintEventHandler(this.render_Paint);
            // 
            // PixelHistorTree
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 273);
            this.Controls.Add(this.parent);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PixelHistorTree";
            this.Text = "Pixel HistorTree";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.PixelHistorTree_FormClosed);
            this.parent.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel parent;
        private System.Windows.Forms.Panel render;
    }
}