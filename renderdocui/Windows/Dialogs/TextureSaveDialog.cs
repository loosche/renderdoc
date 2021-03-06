﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.IO;
using System.Text;
using System.Windows.Forms;
using renderdoc;

namespace renderdocui.Windows.Dialogs
{
    public partial class TextureSaveDialog : Form
    {
        public TextureSaveDialog()
        {
            InitializeComponent();

            fileFormat.Items.Clear();

            string filter = "";

            foreach (var ft in (FileType[])Enum.GetValues(typeof(FileType)))
            {
                fileFormat.Items.Add(ft.ToString());

                if (filter.Length > 0) filter += "|";
                filter += String.Format("{0} Files (*.{1})|*.{1}", ft.ToString(), ft.ToString().ToLower(Application.CurrentCulture));
            }
            
            saveTexDialog.Filter = filter;

            //if (tex.format == null)
            {
                tex.format = new ResourceFormat();
                tex.format.compCount = 4;
                tex.width = tex.height = 128;
                tex.depth = 1;
                tex.arraysize = 6;
                tex.cubemap = true;
                tex.msSamp = 2;
                tex.mips = 5;
                tex.numSubresources = tex.arraysize * tex.mips;
            }
        }

        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == Keys.Escape)
            {
                DialogResult = DialogResult.Cancel;
                this.Close();
                return true;
            }
            if (keyData == Keys.Enter)
            {
                ok_Click(this, null);
                return true;
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }

        public FetchTexture tex = new FetchTexture();
        public TextureSave saveData = new TextureSave();

        public string Filename
        {
            get
            {
                return filename.Text;
            }
        }

        private void TextureSaveDialog_Shown(object sender, EventArgs e)
        {
            jpegCompression.Value = saveData.jpegQuality;

            alphaMap.SelectedIndex = (int)saveData.alpha;

            blackPoint.Text = Formatter.Format(saveData.comp.blackPoint);
            whitePoint.Text = Formatter.Format(saveData.comp.whitePoint);

            mipSelect.Items.Clear();
            for (int i = 0; i < tex.mips; i++)
                mipSelect.Items.Add(i + " - " + Math.Max(1, tex.width >> i) + "x" + Math.Max(1, tex.height >> i));

            mipSelect.SelectedIndex = (saveData.mip >= 0 ? saveData.mip : 0);

            sampleSelect.Items.Clear();
            for (int i = 0; i < tex.msSamp; i++)
                sampleSelect.Items.Add(String.Format("Sample {0}", i));

            sampleSelect.SelectedIndex = (saveData.sample.sampleIndex == ~0U ? 0 : (int)saveData.sample.sampleIndex);

            if (saveData.sample.sampleIndex == ~0U)
            {
                resolveSamples.Checked = true;
            }
            else
            {
                oneSample.Checked = true;
            }

            String[] cubeFaces = { "X+", "X-", "Y+", "Y-", "Z+", "Z-" };

            UInt32 numSlices = (Math.Max(1, tex.depth) * tex.numSubresources) / tex.mips;

            sliceSelect.Items.Clear();

            for (UInt32 i = 0; i < numSlices; i++)
            {
                if (tex.cubemap)
                {
                    String name = cubeFaces[i % 6];
                    if (numSlices > 6)
                        name = string.Format("[{0}] {1}", (i / 6), cubeFaces[i % 6]); // Front 1, Back 2, 3, 4 etc for cube arrays
                    sliceSelect.Items.Add(name);
                }
                else
                {
                    sliceSelect.Items.Add("Slice " + i);
                }
            }

            sliceSelect.SelectedIndex = (saveData.slice.sliceIndex >= 0 ? saveData.slice.sliceIndex : 0);

            gridWidth.Maximum = tex.depth * tex.arraysize * tex.msSamp;

            mipGroup.Visible = (tex.mips > 1);

            sampleGroup.Visible = (tex.msSamp > 1);

            sliceGroup.Visible = (tex.depth > 1 || tex.arraysize > 1 || tex.msSamp > 1);

            if (saveData.destType != FileType.DDS)
            {
                cubeCruciform.Enabled = (tex.cubemap && tex.arraysize == 6);
                
                if (!oneSlice.Checked && !cubeCruciform.Enabled)
                    mapSlicesToGrid.Checked = true;
            }

            fileFormat.SelectedIndex = (int)saveData.destType;
        }

        private void fileFormat_SelectedIndexChanged(object sender, EventArgs e)
        {
            saveData.destType = (FileType)fileFormat.SelectedIndex;

            jpegCompression.Enabled = (saveData.destType == FileType.JPG);

            alphaLDRGroup.Visible = (saveData.destType != FileType.HDR && saveData.destType != FileType.DDS);

            bool noAlphaFormat = (saveData.destType == FileType.BMP || saveData.destType == FileType.JPG);

            alphaMap.Enabled = (tex.format.compCount == 4 && noAlphaFormat);

            alphaCol.Enabled = (saveData.alpha == AlphaMapping.BlendToColour && tex.format.compCount == 4 && noAlphaFormat);

            if (saveData.destType == FileType.DDS)
            {
                exportAllMips.Enabled = exportAllMips.Checked = true;
                exportAllSlices.Enabled = exportAllSlices.Checked = true;

                cubeCruciform.Enabled = cubeCruciform.Checked = false;
                gridWidth.Enabled = mapSlicesToGrid.Enabled = mapSlicesToGrid.Checked = false;
            }
            else
            {
                exportAllMips.Enabled = false;
                oneMip.Checked = oneSlice.Checked = true;
            }
        }

        private void jpegCompression_ValueChanged(object sender, EventArgs e)
        {
            saveData.jpegQuality = (int)jpegCompression.Value;
        }

        private void gridWidth_ValueChanged(object sender, EventArgs e)
        {
            saveData.slice.sliceGridWidth = (int)gridWidth.Value;
        }

        private void alphaMap_SelectedIndexChanged(object sender, EventArgs e)
        {
            saveData.alpha = (AlphaMapping)alphaMap.SelectedIndex;

            alphaCol.Enabled = (saveData.alpha == AlphaMapping.BlendToColour);
        }

        private void mipSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            saveData.mip = (int)mipSelect.SelectedIndex;
        }

        private void sampleSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            saveData.sample.sampleIndex = (uint)sampleSelect.SelectedIndex;
        }

        private void sliceSelect_SelectedIndexChanged(object sender, EventArgs e)
        {
            saveData.slice.sliceIndex = (int)sliceSelect.SelectedIndex;
        }

        private void alphaCol_Click(object sender, EventArgs e)
        {
            var res = colorDialog.ShowDialog();

            if (res == DialogResult.OK || res == DialogResult.Yes)
            {
                saveData.alphaCol = new FloatVector(
                        ((float)colorDialog.Color.R) / 255.0f,
                        ((float)colorDialog.Color.G) / 255.0f,
                        ((float)colorDialog.Color.B) / 255.0f);
            }
        }

        private void browse_Click(object sender, EventArgs e)
        {
            saveTexDialog.FilterIndex = fileFormat.SelectedIndex + 1;
            var res = saveTexDialog.ShowDialog();
            if (res == DialogResult.OK || res == DialogResult.Yes)
            {
                filename.Text = saveTexDialog.FileName;

                try
                {
                    string ext = Path.GetExtension(filename.Text).ToUpperInvariant().Substring(1); // trim . from extension

                    foreach (var ft in (FileType[])Enum.GetValues(typeof(FileType)))
                    {
                        if (ft.ToString().ToUpperInvariant() == ext)
                        {
                            fileFormat.SelectedIndex = (int)ft;
                            break;
                        }
                    }
                }
                catch (ArgumentException)
                {
                    // invalid path or similar
                }
            }
        }

        private void ok_Click(object sender, EventArgs e)
        {
            saveData.alpha = (AlphaMapping)alphaMap.SelectedIndex;

            if (saveData.alpha == AlphaMapping.BlendToCheckerboard)
            {
                saveData.alphaCol = new FloatVector(0.666f, 0.666f, 0.666f);
            }

            if (exportAllMips.Checked)
                saveData.mip = -1;
            else
                saveData.mip = (int)mipSelect.SelectedIndex;

            if (resolveSamples.Checked)
            {
                saveData.sample.sampleIndex = ~0U;
                saveData.sample.mapToArray = false;
            }
            else if (mapSampleArray.Checked)
            {
                saveData.sample.sampleIndex = 0;
                saveData.sample.mapToArray = true;
            }
            else
            {
                saveData.sample.sampleIndex = (uint)sampleSelect.SelectedIndex;
                saveData.sample.mapToArray = false;
            }

            if (!exportAllSlices.Checked)
            {
                saveData.slice.cubeCruciform = saveData.slice.slicesAsGrid = false;
                saveData.slice.sliceGridWidth = 1;
                saveData.slice.sliceIndex = (int)sliceSelect.SelectedIndex;
            }
            else
            {
                saveData.slice.sliceIndex = -1;
                if (cubeCruciform.Checked)
                {
                    saveData.slice.cubeCruciform = true;
                    saveData.slice.slicesAsGrid = false;
                    saveData.slice.sliceGridWidth = 1;
                }
                else
                {
                    saveData.slice.cubeCruciform = false;
                    saveData.slice.slicesAsGrid = true;
                    saveData.slice.sliceGridWidth = (int)gridWidth.Value;
                }
            }

            saveData.destType = (FileType)fileFormat.SelectedIndex;
            saveData.jpegQuality = (int)jpegCompression.Value;

            float.TryParse(blackPoint.Text, out saveData.comp.blackPoint);
            float.TryParse(whitePoint.Text, out saveData.comp.whitePoint);

            try
            {
                // use same path for non-existing path as invalid path
                if (!Directory.Exists(Path.GetDirectoryName(Filename)))
                    throw new ArgumentException();

                if (File.Exists(Filename))
                {
                    var res = MessageBox.Show(String.Format("{0} already exists.\nDo you want to replace it?", Path.GetFileName(Filename)), "Confirm Save Texture",
                                MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation, MessageBoxDefaultButton.Button2);

                    if (res != DialogResult.Yes)
                        return;
                }
            }
            catch(ArgumentException)
            {
                // invalid path or similar

                MessageBox.Show(String.Format("{0}\nPath does not exist.\nCheck the path and try again.", Filename), "Save Texture",
                                MessageBoxButtons.OK, MessageBoxIcon.Exclamation, MessageBoxDefaultButton.Button1);

                return;
            }

            // path is valid and either doesn't exist or user confirmed replacement
            DialogResult = DialogResult.OK;
            Close();
        }

        private void blackPoint_TextChanged(object sender, EventArgs e)
        {
            float.TryParse(blackPoint.Text, out saveData.comp.blackPoint);
        }

        private void whitePoint_TextChanged(object sender, EventArgs e)
        {
            float.TryParse(whitePoint.Text, out saveData.comp.whitePoint);
        }

        private bool recurse = false;

        // a horrible mess of functions to try and maintain valid combinations of options for different
        // filetypes etc. There might be a better way of doing this...

        private void exportAllMips_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            oneMip.Checked = !exportAllMips.Checked;
            mipSelect.Enabled = oneMip.Checked;
            recurse = false;
        }

        private void oneMip_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            exportAllMips.Checked = !oneMip.Checked;
            mipSelect.Enabled = oneMip.Checked;

            if (saveData.destType != FileType.DDS)
            {
                oneMip.Checked = true;
                exportAllMips.Checked = false;
                mipSelect.Enabled = true;
            }

            recurse = false;
        }

        private void mapSampleArray_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            if (mapSampleArray.Checked)
            {
                resolveSamples.Checked = oneSample.Checked = false;
            }
            else
            {
                resolveSamples.Checked = false;
                oneSample.Checked = true;
            }
            sampleSelect.Enabled = oneSample.Checked;
            recurse = false;
        }

        private void resolveSamples_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            if (resolveSamples.Checked)
            {
                mapSampleArray.Checked = oneSample.Checked = false;
            }
            else
            {
                mapSampleArray.Checked = false;
                oneSample.Checked = true;
            }
            sampleSelect.Enabled = oneSample.Checked;
            recurse = false;
        }

        private void oneSample_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            if (oneSample.Checked)
            {
                mapSampleArray.Checked = resolveSamples.Checked = false;
            }
            else
            {
                mapSampleArray.Checked = false;
                resolveSamples.Checked = true;
            }
            sampleSelect.Enabled = oneSample.Checked;
            recurse = false;
        }

        private void mapSlicesToGrid_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            if (mapSlicesToGrid.Checked)
            {
                cubeCruciform.Checked = false;
            }
            else if (saveData.destType != FileType.DDS)
            {
                oneSlice.Checked = true;
                exportAllSlices.Checked = false;
                cubeCruciform.Enabled = mapSlicesToGrid.Enabled = gridWidth.Enabled = false;
                sliceSelect.Enabled = true;
            }
            recurse = false;
            if (saveData.destType == FileType.DDS)
                gridWidth.Enabled = false;
            else
                gridWidth.Enabled = mapSlicesToGrid.Checked;
        }

        private void cubeCruciform_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            if (cubeCruciform.Checked)
            {
                mapSlicesToGrid.Checked = false;
            }
            else if (saveData.destType != FileType.DDS)
            {
                oneSlice.Checked = true;
                exportAllSlices.Checked = false;
                cubeCruciform.Enabled = mapSlicesToGrid.Enabled = gridWidth.Enabled = false;
                sliceSelect.Enabled = true;
            }
            recurse = false;
        }

        private void oneSlice_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            exportAllSlices.Checked = !oneSlice.Checked;
            if (saveData.destType == FileType.DDS)
            {
                mapSlicesToGrid.Enabled = gridWidth.Enabled = cubeCruciform.Enabled = false;
            }
            else
            {
                mapSlicesToGrid.Enabled = gridWidth.Enabled = !oneSlice.Checked;

                if (!oneSlice.Checked && !cubeCruciform.Checked)
                    mapSlicesToGrid.Checked = true;

                if (tex.cubemap && tex.arraysize == 6) cubeCruciform.Enabled = !oneSlice.Checked;
                else cubeCruciform.Enabled = false;
            }
            sliceSelect.Enabled = oneSlice.Checked;
            recurse = false;
        }

        private void exportAllSlices_CheckedChanged(object sender, EventArgs e)
        {
            if (recurse) return;
            recurse = true;
            oneSlice.Checked = !exportAllSlices.Checked;
            if (saveData.destType == FileType.DDS)
            {
                mapSlicesToGrid.Enabled = gridWidth.Enabled = cubeCruciform.Enabled = false;
            }
            else
            {
                mapSlicesToGrid.Enabled = gridWidth.Enabled = !oneSlice.Checked;

                if (!oneSlice.Checked && !cubeCruciform.Checked)
                    mapSlicesToGrid.Checked = true;

                if (tex.cubemap && tex.arraysize == 6) cubeCruciform.Enabled = !oneSlice.Checked;
                else cubeCruciform.Enabled = false;
            }
            sliceSelect.Enabled = oneSlice.Checked;
            recurse = false;
        }
    }
}
