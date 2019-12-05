namespace TSP
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
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.button1 = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.NodesCount_textBox = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.Length_label = new System.Windows.Forms.Label();
			this.clusters_textBox = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.generateClusters_button = new System.Windows.Forms.Button();
			this.generateHybrid_button = new System.Windows.Forms.Button();
			this.ClustersAntiGreedy_button = new System.Windows.Forms.Button();
			this.CreateTreeButton = new System.Windows.Forms.Button();
			this.ShowNumberscheckBox = new System.Windows.Forms.CheckBox();
			this.Extern_button = new System.Windows.Forms.Button();
			this.Solve_button = new System.Windows.Forms.Button();
			this.engines_listBox = new System.Windows.Forms.ListBox();
			this.Load_button = new System.Windows.Forms.Button();
			this.Save_button = new System.Windows.Forms.Button();
			this.SaveInput_saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			this.LoadInput_openFileDialog = new System.Windows.Forms.OpenFileDialog();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			this.SuspendLayout();
			// 
			// pictureBox1
			// 
			this.pictureBox1.Location = new System.Drawing.Point(12, 12);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(882, 599);
			this.pictureBox1.TabIndex = 0;
			this.pictureBox1.TabStop = false;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(900, 54);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(194, 28);
			this.button1.TabIndex = 1;
			this.button1.Text = "Generate uniform";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(900, 30);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(41, 13);
			this.label1.TabIndex = 2;
			this.label1.Text = "Nodes:";
			// 
			// NodesCount_textBox
			// 
			this.NodesCount_textBox.Location = new System.Drawing.Point(947, 27);
			this.NodesCount_textBox.Name = "NodesCount_textBox";
			this.NodesCount_textBox.Size = new System.Drawing.Size(100, 20);
			this.NodesCount_textBox.TabIndex = 3;
			this.NodesCount_textBox.Text = "4";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(904, 598);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(43, 13);
			this.label2.TabIndex = 6;
			this.label2.Text = "Length:";
			// 
			// Length_label
			// 
			this.Length_label.AutoSize = true;
			this.Length_label.Location = new System.Drawing.Point(954, 598);
			this.Length_label.Name = "Length_label";
			this.Length_label.Size = new System.Drawing.Size(13, 13);
			this.Length_label.TabIndex = 7;
			this.Length_label.Text = "0";
			// 
			// clusters_textBox
			// 
			this.clusters_textBox.Location = new System.Drawing.Point(947, 124);
			this.clusters_textBox.Name = "clusters_textBox";
			this.clusters_textBox.Size = new System.Drawing.Size(100, 20);
			this.clusters_textBox.TabIndex = 11;
			this.clusters_textBox.Text = "4";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(900, 127);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(47, 13);
			this.label3.TabIndex = 10;
			this.label3.Text = "Clusters:";
			// 
			// generateClusters_button
			// 
			this.generateClusters_button.Location = new System.Drawing.Point(900, 151);
			this.generateClusters_button.Name = "generateClusters_button";
			this.generateClusters_button.Size = new System.Drawing.Size(194, 28);
			this.generateClusters_button.TabIndex = 9;
			this.generateClusters_button.Text = "Generate with clusters";
			this.generateClusters_button.UseVisualStyleBackColor = true;
			this.generateClusters_button.Click += new System.EventHandler(this.generateClusters_button_Click);
			// 
			// generateHybrid_button
			// 
			this.generateHybrid_button.Location = new System.Drawing.Point(900, 185);
			this.generateHybrid_button.Name = "generateHybrid_button";
			this.generateHybrid_button.Size = new System.Drawing.Size(194, 28);
			this.generateHybrid_button.TabIndex = 12;
			this.generateHybrid_button.Text = "Generate hybrid";
			this.generateHybrid_button.UseVisualStyleBackColor = true;
			this.generateHybrid_button.Click += new System.EventHandler(this.generateHybrid_button_Click);
			// 
			// ClustersAntiGreedy_button
			// 
			this.ClustersAntiGreedy_button.Location = new System.Drawing.Point(900, 219);
			this.ClustersAntiGreedy_button.Name = "ClustersAntiGreedy_button";
			this.ClustersAntiGreedy_button.Size = new System.Drawing.Size(194, 28);
			this.ClustersAntiGreedy_button.TabIndex = 13;
			this.ClustersAntiGreedy_button.Text = "Generate clusters anti-greedy";
			this.ClustersAntiGreedy_button.UseVisualStyleBackColor = true;
			this.ClustersAntiGreedy_button.Click += new System.EventHandler(this.ClustersAntiGreedy_button_Click);
			// 
			// CreateTreeButton
			// 
			this.CreateTreeButton.Location = new System.Drawing.Point(900, 537);
			this.CreateTreeButton.Name = "CreateTreeButton";
			this.CreateTreeButton.Size = new System.Drawing.Size(194, 23);
			this.CreateTreeButton.TabIndex = 15;
			this.CreateTreeButton.Text = "Create and show tree";
			this.CreateTreeButton.UseVisualStyleBackColor = true;
			this.CreateTreeButton.Click += new System.EventHandler(this.CreateTreeButton_Click);
			// 
			// ShowNumberscheckBox
			// 
			this.ShowNumberscheckBox.AutoSize = true;
			this.ShowNumberscheckBox.Location = new System.Drawing.Point(903, 88);
			this.ShowNumberscheckBox.Name = "ShowNumberscheckBox";
			this.ShowNumberscheckBox.Size = new System.Drawing.Size(96, 17);
			this.ShowNumberscheckBox.TabIndex = 16;
			this.ShowNumberscheckBox.Text = "Show numbers";
			this.ShowNumberscheckBox.UseVisualStyleBackColor = true;
			this.ShowNumberscheckBox.CheckedChanged += new System.EventHandler(this.ShowNumberscheckBox_CheckedChanged);
			// 
			// Extern_button
			// 
			this.Extern_button.Enabled = false;
			this.Extern_button.Location = new System.Drawing.Point(957, 563);
			this.Extern_button.Name = "Extern_button";
			this.Extern_button.Size = new System.Drawing.Size(137, 23);
			this.Extern_button.TabIndex = 17;
			this.Extern_button.Text = "Externí program";
			this.Extern_button.UseVisualStyleBackColor = true;
			this.Extern_button.Click += new System.EventHandler(this.Extern_button_Click);
			// 
			// Solve_button
			// 
			this.Solve_button.Location = new System.Drawing.Point(900, 508);
			this.Solve_button.Name = "Solve_button";
			this.Solve_button.Size = new System.Drawing.Size(194, 23);
			this.Solve_button.TabIndex = 18;
			this.Solve_button.Text = "Solve";
			this.Solve_button.UseVisualStyleBackColor = true;
			this.Solve_button.Click += new System.EventHandler(this.Solve_button_Click);
			// 
			// engines_listBox
			// 
			this.engines_listBox.FormattingEnabled = true;
			this.engines_listBox.Items.AddRange(new object[] {
            "Random engine",
            "Greedy engine",
            "Greedy Growing engine",
            "Spanning tree 2-approximation",
            "Optimal solver",
            "Star solver - no crossing",
            "HillClimbing",
            "GA"});
			this.engines_listBox.Location = new System.Drawing.Point(900, 303);
			this.engines_listBox.Name = "engines_listBox";
			this.engines_listBox.Size = new System.Drawing.Size(194, 199);
			this.engines_listBox.TabIndex = 20;
			// 
			// Load_button
			// 
			this.Load_button.Location = new System.Drawing.Point(900, 253);
			this.Load_button.Name = "Load_button";
			this.Load_button.Size = new System.Drawing.Size(95, 28);
			this.Load_button.TabIndex = 23;
			this.Load_button.Text = "Load input";
			this.Load_button.UseVisualStyleBackColor = true;
			this.Load_button.Click += new System.EventHandler(this.Load_button_Click);
			// 
			// Save_button
			// 
			this.Save_button.Location = new System.Drawing.Point(999, 253);
			this.Save_button.Name = "Save_button";
			this.Save_button.Size = new System.Drawing.Size(95, 28);
			this.Save_button.TabIndex = 24;
			this.Save_button.Text = "Save input";
			this.Save_button.UseVisualStyleBackColor = true;
			this.Save_button.Click += new System.EventHandler(this.Save_button_Click);
			// 
			// SaveInput_saveFileDialog
			// 
			this.SaveInput_saveFileDialog.InitialDirectory = "../.";
			this.SaveInput_saveFileDialog.RestoreDirectory = true;
			this.SaveInput_saveFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.SaveInput_saveFileDialog_FileOk);
			// 
			// LoadInput_openFileDialog
			// 
			this.LoadInput_openFileDialog.DefaultExt = "sav";
			this.LoadInput_openFileDialog.FileName = "openFileDialog1";
			this.LoadInput_openFileDialog.InitialDirectory = "./";
			this.LoadInput_openFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.LoadInput_openFileDialog_FileOk);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1106, 623);
			this.Controls.Add(this.Save_button);
			this.Controls.Add(this.Load_button);
			this.Controls.Add(this.engines_listBox);
			this.Controls.Add(this.Solve_button);
			this.Controls.Add(this.Extern_button);
			this.Controls.Add(this.ShowNumberscheckBox);
			this.Controls.Add(this.CreateTreeButton);
			this.Controls.Add(this.ClustersAntiGreedy_button);
			this.Controls.Add(this.generateHybrid_button);
			this.Controls.Add(this.clusters_textBox);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.generateClusters_button);
			this.Controls.Add(this.Length_label);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.NodesCount_textBox);
			this.Controls.Add(this.label1);
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
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox NodesCount_textBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label Length_label;
        private System.Windows.Forms.TextBox clusters_textBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button generateClusters_button;
        private System.Windows.Forms.Button generateHybrid_button;
        private System.Windows.Forms.Button ClustersAntiGreedy_button;
        private System.Windows.Forms.Button CreateTreeButton;
        private System.Windows.Forms.CheckBox ShowNumberscheckBox;
        private System.Windows.Forms.Button Extern_button;
        private System.Windows.Forms.Button Solve_button;
        private System.Windows.Forms.ListBox engines_listBox;
        private System.Windows.Forms.Button Load_button;
        private System.Windows.Forms.Button Save_button;
        private System.Windows.Forms.SaveFileDialog SaveInput_saveFileDialog;
        private System.Windows.Forms.OpenFileDialog LoadInput_openFileDialog;
    }
}

