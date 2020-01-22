namespace SokobanEditor
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
            this.label1 = new System.Windows.Forms.Label();
            this.Create_button = new System.Windows.Forms.Button();
            this.Width_textBox = new System.Windows.Forms.TextBox();
            this.Height_textBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Load_button = new System.Windows.Forms.Button();
            this.Save_button = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.left_Click_label = new System.Windows.Forms.Label();
            this.Right_Click_label = new System.Windows.Forms.Label();
            this.Empty_button = new System.Windows.Forms.Button();
            this.Obstacle_button = new System.Windows.Forms.Button();
            this.Target_button = new System.Windows.Forms.Button();
            this.PutSokoban_button = new System.Windows.Forms.Button();
            this.AddCrate_button = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(795, 434);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 462);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Width";
            // 
            // Create_button
            // 
            this.Create_button.Location = new System.Drawing.Point(15, 511);
            this.Create_button.Name = "Create_button";
            this.Create_button.Size = new System.Drawing.Size(141, 23);
            this.Create_button.TabIndex = 2;
            this.Create_button.Text = "Create new";
            this.Create_button.UseVisualStyleBackColor = true;
            this.Create_button.Click += new System.EventHandler(this.Create_button_Click);
            // 
            // Width_textBox
            // 
            this.Width_textBox.Location = new System.Drawing.Point(56, 459);
            this.Width_textBox.Name = "Width_textBox";
            this.Width_textBox.Size = new System.Drawing.Size(100, 20);
            this.Width_textBox.TabIndex = 3;
            this.Width_textBox.Text = "10";
            // 
            // Height_textBox
            // 
            this.Height_textBox.Location = new System.Drawing.Point(56, 485);
            this.Height_textBox.Name = "Height_textBox";
            this.Height_textBox.Size = new System.Drawing.Size(100, 20);
            this.Height_textBox.TabIndex = 5;
            this.Height_textBox.Text = "10";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 488);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Height";
            // 
            // Load_button
            // 
            this.Load_button.Location = new System.Drawing.Point(213, 457);
            this.Load_button.Name = "Load_button";
            this.Load_button.Size = new System.Drawing.Size(141, 23);
            this.Load_button.TabIndex = 6;
            this.Load_button.Text = "Load";
            this.Load_button.UseVisualStyleBackColor = true;
            this.Load_button.Click += new System.EventHandler(this.Load_button_Click);
            // 
            // Save_button
            // 
            this.Save_button.Location = new System.Drawing.Point(213, 483);
            this.Save_button.Name = "Save_button";
            this.Save_button.Size = new System.Drawing.Size(141, 23);
            this.Save_button.TabIndex = 7;
            this.Save_button.Text = "Save";
            this.Save_button.UseVisualStyleBackColor = true;
            this.Save_button.Click += new System.EventHandler(this.Save_button_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(622, 462);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Left click:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(622, 488);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "Right click:";
            // 
            // left_Click_label
            // 
            this.left_Click_label.AutoSize = true;
            this.left_Click_label.Location = new System.Drawing.Point(681, 462);
            this.left_Click_label.Name = "left_Click_label";
            this.left_Click_label.Size = new System.Drawing.Size(0, 13);
            this.left_Click_label.TabIndex = 10;
            // 
            // Right_Click_label
            // 
            this.Right_Click_label.AutoSize = true;
            this.Right_Click_label.Location = new System.Drawing.Point(681, 488);
            this.Right_Click_label.Name = "Right_Click_label";
            this.Right_Click_label.Size = new System.Drawing.Size(0, 13);
            this.Right_Click_label.TabIndex = 11;
            // 
            // Empty_button
            // 
            this.Empty_button.Location = new System.Drawing.Point(391, 457);
            this.Empty_button.Name = "Empty_button";
            this.Empty_button.Size = new System.Drawing.Size(107, 23);
            this.Empty_button.TabIndex = 12;
            this.Empty_button.Text = "Empty";
            this.Empty_button.UseVisualStyleBackColor = true;
            this.Empty_button.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_MouseDown);
            // 
            // Obstacle_button
            // 
            this.Obstacle_button.Location = new System.Drawing.Point(391, 486);
            this.Obstacle_button.Name = "Obstacle_button";
            this.Obstacle_button.Size = new System.Drawing.Size(107, 23);
            this.Obstacle_button.TabIndex = 13;
            this.Obstacle_button.Text = "Obstacle";
            this.Obstacle_button.UseVisualStyleBackColor = true;
            this.Obstacle_button.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_MouseDown);
            // 
            // Target_button
            // 
            this.Target_button.Location = new System.Drawing.Point(391, 515);
            this.Target_button.Name = "Target_button";
            this.Target_button.Size = new System.Drawing.Size(107, 23);
            this.Target_button.TabIndex = 14;
            this.Target_button.Text = "Target";
            this.Target_button.UseVisualStyleBackColor = true;
            this.Target_button.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_MouseDown);
            // 
            // PutSokoban_button
            // 
            this.PutSokoban_button.Location = new System.Drawing.Point(509, 486);
            this.PutSokoban_button.Name = "PutSokoban_button";
            this.PutSokoban_button.Size = new System.Drawing.Size(107, 23);
            this.PutSokoban_button.TabIndex = 16;
            this.PutSokoban_button.Text = "Put Sokoban";
            this.PutSokoban_button.UseVisualStyleBackColor = true;
            this.PutSokoban_button.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_MouseDown);
            // 
            // AddCrate_button
            // 
            this.AddCrate_button.Location = new System.Drawing.Point(509, 457);
            this.AddCrate_button.Name = "AddCrate_button";
            this.AddCrate_button.Size = new System.Drawing.Size(107, 23);
            this.AddCrate_button.TabIndex = 15;
            this.AddCrate_button.Text = "Add crate";
            this.AddCrate_button.UseVisualStyleBackColor = true;
            this.AddCrate_button.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_MouseDown);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.DefaultExt = "sok";
            this.openFileDialog1.Filter = "Sokoban maps|*.sok|All files|*.*";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.Filter = "Sokoban maps|*.sok";
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(819, 548);
            this.Controls.Add(this.PutSokoban_button);
            this.Controls.Add(this.AddCrate_button);
            this.Controls.Add(this.Target_button);
            this.Controls.Add(this.Obstacle_button);
            this.Controls.Add(this.Empty_button);
            this.Controls.Add(this.Right_Click_label);
            this.Controls.Add(this.left_Click_label);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Save_button);
            this.Controls.Add(this.Load_button);
            this.Controls.Add(this.Height_textBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Width_textBox);
            this.Controls.Add(this.Create_button);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Create_button;
        private System.Windows.Forms.TextBox Width_textBox;
        private System.Windows.Forms.TextBox Height_textBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Load_button;
        private System.Windows.Forms.Button Save_button;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label left_Click_label;
        private System.Windows.Forms.Label Right_Click_label;
        private System.Windows.Forms.Button Empty_button;
        private System.Windows.Forms.Button Obstacle_button;
        private System.Windows.Forms.Button Target_button;
        private System.Windows.Forms.Button PutSokoban_button;
        private System.Windows.Forms.Button AddCrate_button;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
    }
}

