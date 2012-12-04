namespace MemPagerSim
{
    partial class frmMemPagerSim
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMemPagerSim));
            this.browser = new System.Windows.Forms.WebBrowser();
            this.btnLoad = new System.Windows.Forms.Button();
            this.txtPrompt = new System.Windows.Forms.TextBox();
            this.btnRun = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtSequence = new System.Windows.Forms.TextBox();
            this.btnEnd = new System.Windows.Forms.Button();
            this.chkRpts = new System.Windows.Forms.CheckBox();
            this.openFileDlg = new System.Windows.Forms.OpenFileDialog();
            this.SuspendLayout();
            // 
            // browser
            // 
            this.browser.Location = new System.Drawing.Point(328, 31);
            this.browser.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.browser.MinimumSize = new System.Drawing.Size(26, 27);
            this.browser.Name = "browser";
            this.browser.Size = new System.Drawing.Size(537, 446);
            this.browser.TabIndex = 1;
            // 
            // btnLoad
            // 
            this.btnLoad.Font = new System.Drawing.Font("Comic Sans MS", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLoad.Location = new System.Drawing.Point(213, 148);
            this.btnLoad.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(99, 32);
            this.btnLoad.TabIndex = 2;
            this.btnLoad.Text = "load!";
            this.btnLoad.UseVisualStyleBackColor = true;
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // txtPrompt
            // 
            this.txtPrompt.Location = new System.Drawing.Point(12, 9);
            this.txtPrompt.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txtPrompt.Multiline = true;
            this.txtPrompt.Name = "txtPrompt";
            this.txtPrompt.ReadOnly = true;
            this.txtPrompt.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.txtPrompt.Size = new System.Drawing.Size(300, 181);
            this.txtPrompt.TabIndex = 3;
            this.txtPrompt.Text = resources.GetString("txtPrompt.Text");
            // 
            // btnRun
            // 
            this.btnRun.Font = new System.Drawing.Font("Comic Sans MS", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRun.Location = new System.Drawing.Point(12, 425);
            this.btnRun.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(99, 32);
            this.btnRun.TabIndex = 5;
            this.btnRun.Text = "run!";
            this.btnRun.UseVisualStyleBackColor = true;
            this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(325, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 18);
            this.label4.TabIndex = 4;
            this.label4.Text = "Results:";
            // 
            // txtSequence
            // 
            this.txtSequence.Location = new System.Drawing.Point(12, 188);
            this.txtSequence.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txtSequence.Multiline = true;
            this.txtSequence.Name = "txtSequence";
            this.txtSequence.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.txtSequence.Size = new System.Drawing.Size(300, 191);
            this.txtSequence.TabIndex = 3;
            this.txtSequence.Text = "F,3,0,1,2,3,2,3,0,4,5,2,3,1,4,3,2,6,3,2,1,2\r\nO,3,0,1,2,3,2,3,0,4,5,2,3,1,4,3,2,6," +
    "3,2,1,2\r\nL,3,0,1,2,3,2,3,0,4,5,2,3,1,4,3,2,6,3,2,1,2";
            // 
            // btnEnd
            // 
            this.btnEnd.Font = new System.Drawing.Font("Comic Sans MS", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnEnd.Location = new System.Drawing.Point(213, 425);
            this.btnEnd.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnEnd.Name = "btnEnd";
            this.btnEnd.Size = new System.Drawing.Size(99, 32);
            this.btnEnd.TabIndex = 6;
            this.btnEnd.Text = "exit!";
            this.btnEnd.UseVisualStyleBackColor = true;
            this.btnEnd.Click += new System.EventHandler(this.btnEnd_Click);
            // 
            // chkRpts
            // 
            this.chkRpts.AutoSize = true;
            this.chkRpts.Location = new System.Drawing.Point(12, 396);
            this.chkRpts.Name = "chkRpts";
            this.chkRpts.Size = new System.Drawing.Size(160, 22);
            this.chkRpts.TabIndex = 7;
            this.chkRpts.Text = "show repeats as blank";
            this.chkRpts.UseVisualStyleBackColor = true;
            // 
            // openFileDlg
            // 
            this.openFileDlg.DefaultExt = "dat";
            this.openFileDlg.FileName = "lab2.dat";
            this.openFileDlg.Filter = "data files|*.dat,*.txt|all files|*.*";
            this.openFileDlg.Title = "Pick a sequence file!";
            this.openFileDlg.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDlg_FileOk);
            // 
            // frmMemPagerSim
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(877, 490);
            this.Controls.Add(this.chkRpts);
            this.Controls.Add(this.btnEnd);
            this.Controls.Add(this.btnRun);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtSequence);
            this.Controls.Add(this.btnLoad);
            this.Controls.Add(this.browser);
            this.Controls.Add(this.txtPrompt);
            this.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.Name = "frmMemPagerSim";
            this.Text = "Virtual Memory Paging";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.WebBrowser browser;
        private System.Windows.Forms.Button btnLoad;
        private System.Windows.Forms.TextBox txtPrompt;
        private System.Windows.Forms.Button btnRun;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtSequence;
        private System.Windows.Forms.Button btnEnd;
        private System.Windows.Forms.CheckBox chkRpts;
        private System.Windows.Forms.OpenFileDialog openFileDlg;

    }
}

