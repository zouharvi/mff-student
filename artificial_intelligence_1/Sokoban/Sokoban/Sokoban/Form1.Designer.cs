namespace Sokoban
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
			this.button1 = new System.Windows.Forms.Button();
			this.leftButton = new System.Windows.Forms.Button();
			this.upBotton = new System.Windows.Forms.Button();
			this.downButton = new System.Windows.Forms.Button();
			this.rightButton = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.Solvebutton = new System.Windows.Forms.Button();
			this.ShowSolutionbutton = new System.Windows.Forms.Button();
			this.ShowSolutiontimer = new System.Windows.Forms.Timer(this.components);
			this.solvingLabel = new System.Windows.Forms.Label();
			this.SeedtextBox = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.saveMap_saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			this.Save_button = new System.Windows.Forms.Button();
			this.Load_button = new System.Windows.Forms.Button();
			this.LoadMap_openFileDialog = new System.Windows.Forms.OpenFileDialog();
			this.checkBox1 = new System.Windows.Forms.CheckBox();
			this.checkBox2 = new System.Windows.Forms.CheckBox();
			this.checkBox3 = new System.Windows.Forms.CheckBox();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			this.SuspendLayout();
			// 
			// pictureBox1
			// 
			this.pictureBox1.Location = new System.Drawing.Point(13, 13);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(813, 559);
			this.pictureBox1.TabIndex = 0;
			this.pictureBox1.TabStop = false;
			// 
			// button1
			// 
			this.button1.Enabled = true;
			this.button1.Location = new System.Drawing.Point(13, 601);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(116, 43);
			this.button1.TabIndex = 1;
			this.button1.Text = "Generate random";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// leftButton
			// 
			this.leftButton.Location = new System.Drawing.Point(329, 617);
			this.leftButton.Name = "leftButton";
			this.leftButton.Size = new System.Drawing.Size(34, 23);
			this.leftButton.TabIndex = 2;
			this.leftButton.Text = "<-";
			this.leftButton.UseVisualStyleBackColor = true;
			this.leftButton.Click += new System.EventHandler(this.leftButton_Click);
			// 
			// upBotton
			// 
			this.upBotton.Location = new System.Drawing.Point(369, 588);
			this.upBotton.Name = "upBotton";
			this.upBotton.Size = new System.Drawing.Size(34, 23);
			this.upBotton.TabIndex = 3;
			this.upBotton.Text = "^";
			this.upBotton.UseVisualStyleBackColor = true;
			this.upBotton.Click += new System.EventHandler(this.upBotton_Click);
			// 
			// downButton
			// 
			this.downButton.Location = new System.Drawing.Point(369, 617);
			this.downButton.Name = "downButton";
			this.downButton.Size = new System.Drawing.Size(34, 23);
			this.downButton.TabIndex = 4;
			this.downButton.Text = "v";
			this.downButton.UseVisualStyleBackColor = true;
			this.downButton.Click += new System.EventHandler(this.downButton_Click);
			// 
			// rightButton
			// 
			this.rightButton.Location = new System.Drawing.Point(409, 617);
			this.rightButton.Name = "rightButton";
			this.rightButton.Size = new System.Drawing.Size(34, 23);
			this.rightButton.TabIndex = 5;
			this.rightButton.Text = "->";
			this.rightButton.UseVisualStyleBackColor = true;
			this.rightButton.Click += new System.EventHandler(this.rightButton_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(486, 588);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(35, 13);
			this.label1.TabIndex = 6;
			this.label1.Text = "label1";
			// 
			// Solvebutton
			// 
			this.Solvebutton.Location = new System.Drawing.Point(740, 586);
			this.Solvebutton.Name = "Solvebutton";
			this.Solvebutton.Size = new System.Drawing.Size(86, 23);
			this.Solvebutton.TabIndex = 7;
			this.Solvebutton.Text = "Solve";
			this.Solvebutton.UseVisualStyleBackColor = true;
			this.Solvebutton.Click += new System.EventHandler(this.Solvebutton_Click);
			// 
			// ShowSolutionbutton
			// 
			this.ShowSolutionbutton.Location = new System.Drawing.Point(740, 615);
			this.ShowSolutionbutton.Name = "ShowSolutionbutton";
			this.ShowSolutionbutton.Size = new System.Drawing.Size(86, 23);
			this.ShowSolutionbutton.TabIndex = 8;
			this.ShowSolutionbutton.Text = "Show solution";
			this.ShowSolutionbutton.UseVisualStyleBackColor = true;
			this.ShowSolutionbutton.Click += new System.EventHandler(this.ShowSolutionbutton_Click);
			// 
			// ShowSolutiontimer
			// 
			this.ShowSolutiontimer.Tick += new System.EventHandler(this.ShowSolutiontimer_Tick);
			// 
			// solvingLabel
			// 
			this.solvingLabel.AutoSize = true;
			this.solvingLabel.Location = new System.Drawing.Point(489, 626);
			this.solvingLabel.Name = "solvingLabel";
			this.solvingLabel.Size = new System.Drawing.Size(0, 13);
			this.solvingLabel.TabIndex = 9;
			// 
			// SeedtextBox
			// 
			this.SeedtextBox.Location = new System.Drawing.Point(197, 624);
			this.SeedtextBox.Name = "SeedtextBox";
			this.SeedtextBox.Size = new System.Drawing.Size(100, 20);
			this.SeedtextBox.TabIndex = 10;
			this.SeedtextBox.Text = "3629";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(156, 627);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(33, 13);
			this.label2.TabIndex = 11;
			this.label2.Text = "seed:";
			// 
			// saveMap_saveFileDialog
			// 
			this.saveMap_saveFileDialog.DefaultExt = "sok";
			this.saveMap_saveFileDialog.Filter = "Sokoban maps|*.sok";
			this.saveMap_saveFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.saveMap_saveFileDialog_FileOk);
			// 
			// Save_button
			// 
			this.Save_button.Location = new System.Drawing.Point(222, 578);
			this.Save_button.Name = "Save_button";
			this.Save_button.Size = new System.Drawing.Size(75, 23);
			this.Save_button.TabIndex = 12;
			this.Save_button.Text = "Save";
			this.Save_button.UseVisualStyleBackColor = true;
			this.Save_button.Click += new System.EventHandler(this.Save_button_Click);
			// 
			// Load_button
			// 
			this.Load_button.Location = new System.Drawing.Point(141, 578);
			this.Load_button.Name = "Load_button";
			this.Load_button.Size = new System.Drawing.Size(75, 23);
			this.Load_button.TabIndex = 13;
			this.Load_button.Text = "Load";
			this.Load_button.UseVisualStyleBackColor = true;
			this.Load_button.Click += new System.EventHandler(this.Load_button_Click);
			// 
			// LoadMap_openFileDialog
			// 
			this.LoadMap_openFileDialog.DefaultExt = "sok";
			this.LoadMap_openFileDialog.FileName = "openFileDialog1";
			this.LoadMap_openFileDialog.Filter = "Sokoban Maps|*.sok|xsb files|*.xsb";
			this.LoadMap_openFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.LoadMap_openFileDialog_FileOk);
			// 
			// checkBox1
			// 
			this.checkBox1.AutoSize = true;
			this.checkBox1.Location = new System.Drawing.Point(555, 578);
			this.checkBox1.Name = "checkBox1";
			this.checkBox1.Size = new System.Drawing.Size(120, 17);
			this.checkBox1.TabIndex = 14;
			this.checkBox1.Text = "Dead end detection";
			this.checkBox1.UseVisualStyleBackColor = true;
			this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this.checkBox2.AutoSize = true;
			this.checkBox2.Checked = true;
			this.checkBox2.CheckState = System.Windows.Forms.CheckState.Checked;
			this.checkBox2.Location = new System.Drawing.Point(555, 601);
			this.checkBox2.Name = "checkBox2";
			this.checkBox2.Size = new System.Drawing.Size(111, 17);
			this.checkBox2.TabIndex = 15;
			this.checkBox2.Text = "Advanced solving";
			this.checkBox2.UseVisualStyleBackColor = true;
			this.checkBox2.CheckedChanged += new System.EventHandler(this.checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this.checkBox3.AutoSize = true;
			this.checkBox3.Location = new System.Drawing.Point(555, 624);
			this.checkBox3.Name = "checkBox3";
			this.checkBox3.Size = new System.Drawing.Size(115, 17);
			this.checkBox3.TabIndex = 16;
			this.checkBox3.Text = "Symmetry breaking";
			this.checkBox3.UseVisualStyleBackColor = true;
			this.checkBox3.CheckedChanged += new System.EventHandler(this.checkBox3_CheckedChanged);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(854, 656);
			this.Controls.Add(this.checkBox3);
			this.Controls.Add(this.checkBox2);
			this.Controls.Add(this.checkBox1);
			this.Controls.Add(this.Load_button);
			this.Controls.Add(this.Save_button);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.SeedtextBox);
			this.Controls.Add(this.solvingLabel);
			this.Controls.Add(this.ShowSolutionbutton);
			this.Controls.Add(this.Solvebutton);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.rightButton);
			this.Controls.Add(this.downButton);
			this.Controls.Add(this.upBotton);
			this.Controls.Add(this.leftButton);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.pictureBox1);
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button leftButton;
        private System.Windows.Forms.Button upBotton;
        private System.Windows.Forms.Button downButton;
        private System.Windows.Forms.Button rightButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Solvebutton;
        private System.Windows.Forms.Button ShowSolutionbutton;
        private System.Windows.Forms.Timer ShowSolutiontimer;
        private System.Windows.Forms.Label solvingLabel;
        private System.Windows.Forms.TextBox SeedtextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.SaveFileDialog saveMap_saveFileDialog;
        private System.Windows.Forms.Button Save_button;
        private System.Windows.Forms.Button Load_button;
        private System.Windows.Forms.OpenFileDialog LoadMap_openFileDialog;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox checkBox2;
		private System.Windows.Forms.CheckBox checkBox3;
	}
}

