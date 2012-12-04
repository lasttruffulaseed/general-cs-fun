using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MemPagerSim
{
    public partial class frmMemPagerSim : Form
    {
        public frmMemPagerSim()
        {
            InitializeComponent();
        }

        /*
         * Process each line in the reference input text
         * Running the algo for each!
         * Output to results pane
         */
        private void btnRun_Click(object sender, EventArgs e)
        {
            String[] lines = txtSequence.Lines;
            String html = htmlStart();
            bool blankRepeats = chkRpts.Checked;

            foreach (String reference in lines)
            {
                PagingSequencer sequencer = new PagingSequencer(reference, blankRepeats);

                html += sequencer.runAsHtmlReport(false);
            }

            html += htmlEnd();

            browser.DocumentText=html;
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            openFileDlg.ShowDialog();
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private String htmlStart()
        {
            return "<html><body><style>.bf{border:1px solid #114; background-color: #ccf;}</style>";
        }

        private String htmlEnd()
        {
            return "</body></html>";
        }

        // load file contents into the sequences text box */
        private void openFileDlg_FileOk(object sender, CancelEventArgs e)
        {
            StreamReader rdr = new StreamReader(openFileDlg.OpenFile());
            String input;
            List<String> lines = new List<String>();
            int linecount = 0;

            while ( ((input=rdr.ReadLine())!=null) && (linecount<10) ) 
            {
                lines.Add(input);
                linecount++;
            }
            txtSequence.Lines = lines.ToArray();
            rdr.Close();
        }
    }
}
