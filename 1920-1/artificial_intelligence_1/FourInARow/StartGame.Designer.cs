namespace FourInARow
{
    partial class StartGame
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.RedMainComboBox = new System.Windows.Forms.ComboBox();
            this.BlueMainComboBox2 = new System.Windows.Forms.ComboBox();
            this.RedAddLabel = new System.Windows.Forms.Label();
            this.BlueAddLabel = new System.Windows.Forms.Label();
            this.RedAddComboBox = new System.Windows.Forms.ComboBox();
            this.BlueAddComboBox = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.SizeXcomboBox = new System.Windows.Forms.ComboBox();
            this.SizeYcomboBox = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Red player:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Blue player:";
            // 
            // RedMainComboBox
            // 
            this.RedMainComboBox.FormattingEnabled = true;
            this.RedMainComboBox.Items.AddRange(new object[] {
            "Random engine",
            "Monte Carlo engine",
            "Alpha-Beta engine",
            "Human",
            "Alpha-Beta engine EXPERIMENTAL"});
            this.RedMainComboBox.Location = new System.Drawing.Point(80, 46);
            this.RedMainComboBox.Name = "RedMainComboBox";
            this.RedMainComboBox.Size = new System.Drawing.Size(121, 21);
            this.RedMainComboBox.TabIndex = 2;
            this.RedMainComboBox.Text = "Monte Carlo engine";
            this.RedMainComboBox.SelectedIndexChanged += new System.EventHandler(this.RedMainComboBox_SelectedIndexChanged);
            // 
            // BlueMainComboBox2
            // 
            this.BlueMainComboBox2.FormattingEnabled = true;
            this.BlueMainComboBox2.Items.AddRange(new object[] {
            "Random engine",
            "Monte Carlo engine",
            "Alpha-Beta engine",
            "Human",
            "Alpha-Beta engine EXPERIMENTAL"});
            this.BlueMainComboBox2.Location = new System.Drawing.Point(80, 73);
            this.BlueMainComboBox2.Name = "BlueMainComboBox2";
            this.BlueMainComboBox2.Size = new System.Drawing.Size(121, 21);
            this.BlueMainComboBox2.TabIndex = 3;
            this.BlueMainComboBox2.Text = "Human";
            this.BlueMainComboBox2.SelectedIndexChanged += new System.EventHandler(this.BlueMainComboBox2_SelectedIndexChanged);
            // 
            // RedAddLabel
            // 
            this.RedAddLabel.AutoSize = true;
            this.RedAddLabel.Location = new System.Drawing.Point(207, 49);
            this.RedAddLabel.Name = "RedAddLabel";
            this.RedAddLabel.Size = new System.Drawing.Size(63, 13);
            this.RedAddLabel.TabIndex = 4;
            this.RedAddLabel.Text = "Simulations:";
            // 
            // BlueAddLabel
            // 
            this.BlueAddLabel.AutoSize = true;
            this.BlueAddLabel.Location = new System.Drawing.Point(207, 76);
            this.BlueAddLabel.Name = "BlueAddLabel";
            this.BlueAddLabel.Size = new System.Drawing.Size(0, 13);
            this.BlueAddLabel.TabIndex = 5;
            // 
            // RedAddComboBox
            // 
            this.RedAddComboBox.FormattingEnabled = true;
            this.RedAddComboBox.Items.AddRange(new object[] {
            "500",
            "1000",
            "2000",
            "3000",
            "4000",
            "5000",
            "7000",
            "9000",
            "11000",
            "15000",
            "25000"});
            this.RedAddComboBox.Location = new System.Drawing.Point(276, 46);
            this.RedAddComboBox.Name = "RedAddComboBox";
            this.RedAddComboBox.Size = new System.Drawing.Size(121, 21);
            this.RedAddComboBox.TabIndex = 6;
            this.RedAddComboBox.Text = "3000";
            // 
            // BlueAddComboBox
            // 
            this.BlueAddComboBox.Enabled = false;
            this.BlueAddComboBox.FormattingEnabled = true;
            this.BlueAddComboBox.Location = new System.Drawing.Point(276, 73);
            this.BlueAddComboBox.Name = "BlueAddComboBox";
            this.BlueAddComboBox.Size = new System.Drawing.Size(121, 21);
            this.BlueAddComboBox.TabIndex = 7;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(246, 115);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(186, 23);
            this.button1.TabIndex = 8;
            this.button1.Text = "Start";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 12);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(59, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Board size:";
            // 
            // SizeXcomboBox
            // 
            this.SizeXcomboBox.FormattingEnabled = true;
            this.SizeXcomboBox.Items.AddRange(new object[] {
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20"});
            this.SizeXcomboBox.Location = new System.Drawing.Point(80, 9);
            this.SizeXcomboBox.Name = "SizeXcomboBox";
            this.SizeXcomboBox.Size = new System.Drawing.Size(121, 21);
            this.SizeXcomboBox.TabIndex = 10;
            this.SizeXcomboBox.Text = "7";
            // 
            // SizeYcomboBox
            // 
            this.SizeYcomboBox.FormattingEnabled = true;
            this.SizeYcomboBox.Items.AddRange(new object[] {
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20"});
            this.SizeYcomboBox.Location = new System.Drawing.Point(210, 9);
            this.SizeYcomboBox.Name = "SizeYcomboBox";
            this.SizeYcomboBox.Size = new System.Drawing.Size(121, 21);
            this.SizeYcomboBox.TabIndex = 11;
            this.SizeYcomboBox.Text = "6";
            // 
            // StartGame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(636, 150);
            this.Controls.Add(this.SizeYcomboBox);
            this.Controls.Add(this.SizeXcomboBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.BlueAddComboBox);
            this.Controls.Add(this.RedAddComboBox);
            this.Controls.Add(this.BlueAddLabel);
            this.Controls.Add(this.RedAddLabel);
            this.Controls.Add(this.BlueMainComboBox2);
            this.Controls.Add(this.RedMainComboBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "StartGame";
            this.Text = "StartGame";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox RedMainComboBox;
        private System.Windows.Forms.ComboBox BlueMainComboBox2;
        private System.Windows.Forms.Label RedAddLabel;
        private System.Windows.Forms.Label BlueAddLabel;
        private System.Windows.Forms.ComboBox RedAddComboBox;
        private System.Windows.Forms.ComboBox BlueAddComboBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox SizeXcomboBox;
        private System.Windows.Forms.ComboBox SizeYcomboBox;
    }
}