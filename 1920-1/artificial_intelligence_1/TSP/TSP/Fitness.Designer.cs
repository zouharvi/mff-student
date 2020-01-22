namespace TSP
{
    partial class TreeSolver
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
            this.TreePictureBox = new System.Windows.Forms.PictureBox();
            this.FitnessPictureBox = new System.Windows.Forms.PictureBox();
            this.valueLabel = new System.Windows.Forms.Label();
            this.evalButton = new System.Windows.Forms.Button();
            this.RebuildWithPermutationbutton = new System.Windows.Forms.Button();
            this.OptimalSolve_button = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.TreePictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.FitnessPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // TreePictureBox
            // 
            this.TreePictureBox.Dock = System.Windows.Forms.DockStyle.Top;
            this.TreePictureBox.Location = new System.Drawing.Point(0, 0);
            this.TreePictureBox.Name = "TreePictureBox";
            this.TreePictureBox.Size = new System.Drawing.Size(1156, 266);
            this.TreePictureBox.TabIndex = 0;
            this.TreePictureBox.TabStop = false;
            // 
            // FitnessPictureBox
            // 
            this.FitnessPictureBox.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.FitnessPictureBox.Location = new System.Drawing.Point(0, 300);
            this.FitnessPictureBox.Name = "FitnessPictureBox";
            this.FitnessPictureBox.Size = new System.Drawing.Size(1156, 278);
            this.FitnessPictureBox.TabIndex = 1;
            this.FitnessPictureBox.TabStop = false;
            // 
            // valueLabel
            // 
            this.valueLabel.AutoSize = true;
            this.valueLabel.Location = new System.Drawing.Point(13, 273);
            this.valueLabel.Name = "valueLabel";
            this.valueLabel.Size = new System.Drawing.Size(33, 13);
            this.valueLabel.TabIndex = 2;
            this.valueLabel.Text = "value";
            // 
            // evalButton
            // 
            this.evalButton.Location = new System.Drawing.Point(222, 273);
            this.evalButton.Name = "evalButton";
            this.evalButton.Size = new System.Drawing.Size(113, 23);
            this.evalButton.TabIndex = 3;
            this.evalButton.Text = "Evaluate current";
            this.evalButton.UseVisualStyleBackColor = true;
            this.evalButton.Click += new System.EventHandler(this.evalButton_Click);
            // 
            // RebuildWithPermutationbutton
            // 
            this.RebuildWithPermutationbutton.Location = new System.Drawing.Point(341, 273);
            this.RebuildWithPermutationbutton.Name = "RebuildWithPermutationbutton";
            this.RebuildWithPermutationbutton.Size = new System.Drawing.Size(204, 23);
            this.RebuildWithPermutationbutton.TabIndex = 4;
            this.RebuildWithPermutationbutton.Text = "Rebuild using random permutation";
            this.RebuildWithPermutationbutton.UseVisualStyleBackColor = true;
            this.RebuildWithPermutationbutton.Click += new System.EventHandler(this.RebuildWithPermutationbutton_Click);
            // 
            // OptimalSolve_button
            // 
            this.OptimalSolve_button.Location = new System.Drawing.Point(650, 273);
            this.OptimalSolve_button.Name = "OptimalSolve_button";
            this.OptimalSolve_button.Size = new System.Drawing.Size(137, 23);
            this.OptimalSolve_button.TabIndex = 6;
            this.OptimalSolve_button.Text = "Best Permutation";
            this.OptimalSolve_button.UseVisualStyleBackColor = true;
            this.OptimalSolve_button.Click += new System.EventHandler(this.OptimalSolve_button_Click);
            // 
            // TreeSolver
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1156, 578);
            this.Controls.Add(this.OptimalSolve_button);
            this.Controls.Add(this.RebuildWithPermutationbutton);
            this.Controls.Add(this.evalButton);
            this.Controls.Add(this.valueLabel);
            this.Controls.Add(this.FitnessPictureBox);
            this.Controls.Add(this.TreePictureBox);
            this.Name = "TreeSolver";
            this.Text = "Fitness";
            ((System.ComponentModel.ISupportInitialize)(this.TreePictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.FitnessPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox TreePictureBox;
        private System.Windows.Forms.PictureBox FitnessPictureBox;
        private System.Windows.Forms.Label valueLabel;
        private System.Windows.Forms.Button evalButton;
        private System.Windows.Forms.Button RebuildWithPermutationbutton;
        private System.Windows.Forms.Button OptimalSolve_button;
    }
}