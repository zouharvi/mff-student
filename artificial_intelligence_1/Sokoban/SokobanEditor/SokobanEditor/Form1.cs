using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Sokoban;

namespace SokobanEditor
{
    public enum Tools
    {
        empty,
        crate,
        sokoban,
        target,
        obstacle
    }

    public partial class Form1 : Form
    {
        Board b = new Board();
        Visualizer vis;
        Tools leftTool, rightTool;

        public Form1()
        {
            InitializeComponent();
            vis = new Visualizer(pictureBox1, null);
            leftTool = Tools.crate;
            rightTool = Tools.empty;
            left_Click_label.Text = AddCrate_button.Text;
            Right_Click_label.Text = Empty_button.Text;
        }

        public void updateSelectedTool(bool isLeftMouseButton, Button sender)
        {
            if (isLeftMouseButton)
                left_Click_label.Text = sender.Text;
            else 
                Right_Click_label.Text = sender.Text;
            switch (sender.Name)
            {
                case "Empty_button":
                    if (isLeftMouseButton) leftTool = Tools.empty;
                    else rightTool = Tools.empty;
                    break;
                case "Target_button":
                    if (isLeftMouseButton) leftTool = Tools.target;
                    else rightTool = Tools.target;
                    break;
                case "Obstacle_button":
                    if (isLeftMouseButton) leftTool = Tools.obstacle;
                    else rightTool = Tools.obstacle;
                    break;
                case "AddCrate_button":
                    if (isLeftMouseButton) leftTool = Tools.crate;
                    else rightTool = Tools.crate;
                    break;
                case "PutSokoban_button":
                    if (isLeftMouseButton) leftTool = Tools.sokoban;
                    else rightTool = Tools.sokoban;
                    break;
            }
        }

        private void button_MouseDown(object sender, MouseEventArgs e)
        {
            updateSelectedTool(e.Button == System.Windows.Forms.MouseButtons.Left, sender as Button);
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (vis == null)
                return;
            vis.handleClick(sender, e);
            if (vis.getCoordinatesOfLastClick().x == byte.MaxValue) // clicked outside of the board
                return;
            handleEditation(e.Button == System.Windows.Forms.MouseButtons.Left ? leftTool : rightTool);
            vis.visualize(b);
        }

        private void handleEditation(Tools tool)
        {
            Coords tile = vis.getCoordinatesOfLastClick();
            switch (tool)
            {
                case Tools.empty:
                    b.edit_ClearTile(tile);
                    break;
                case Tools.crate:
                    b.edit_AddCrate(tile);
                    break;
                case Tools.sokoban:
                    b.edit_AddSokoban(tile);
                    break;
                case Tools.target:
                    b.edit_SetTarget(tile);
                    break;
                case Tools.obstacle:
                    b.edit_SetObstacle(tile);
                    break;
                default:
                    break;
            }
        }

        private void Create_button_Click(object sender, EventArgs e)
        {
            b = new Board(int.Parse(Width_textBox.Text), int.Parse(Height_textBox.Text));
            vis.visualize(b);
        }

        private void Load_button_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        private void Save_button_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            b.load(openFileDialog1.FileName);
            vis.visualize(b);
        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            b.save(saveFileDialog1.FileName);
        }
    }
}
