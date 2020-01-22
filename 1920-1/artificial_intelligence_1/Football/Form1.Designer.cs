namespace Football
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.FirstTeamName_label = new System.Windows.Forms.Label();
            this.score_label = new System.Windows.Forms.Label();
            this.SecondTeamName_label = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(0, 36);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(974, 650);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Interval = 1;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // FirstTeamName_label
            // 
            this.FirstTeamName_label.AutoSize = true;
            this.FirstTeamName_label.Dock = System.Windows.Forms.DockStyle.Left;
            this.FirstTeamName_label.Location = new System.Drawing.Point(0, 0);
            this.FirstTeamName_label.Name = "FirstTeamName_label";
            this.FirstTeamName_label.Size = new System.Drawing.Size(47, 13);
            this.FirstTeamName_label.TabIndex = 1;
            this.FirstTeamName_label.Text = "labelggg";
            // 
            // score_label
            // 
            this.score_label.AutoSize = true;
            this.score_label.Dock = System.Windows.Forms.DockStyle.Left;
            this.score_label.Location = new System.Drawing.Point(47, 0);
            this.score_label.Name = "score_label";
            this.score_label.Size = new System.Drawing.Size(35, 13);
            this.score_label.TabIndex = 2;
            this.score_label.Text = "label2";
            // 
            // SecondTeamName_label
            // 
            this.SecondTeamName_label.AutoSize = true;
            this.SecondTeamName_label.Dock = System.Windows.Forms.DockStyle.Left;
            this.SecondTeamName_label.Location = new System.Drawing.Point(82, 0);
            this.SecondTeamName_label.Name = "SecondTeamName_label";
            this.SecondTeamName_label.Size = new System.Drawing.Size(35, 13);
            this.SecondTeamName_label.TabIndex = 3;
            this.SecondTeamName_label.Text = "label3";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(974, 646);
            this.Controls.Add(this.SecondTeamName_label);
            this.Controls.Add(this.score_label);
            this.Controls.Add(this.FirstTeamName_label);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label FirstTeamName_label;
        private System.Windows.Forms.Label score_label;
        private System.Windows.Forms.Label SecondTeamName_label;
    }
}

