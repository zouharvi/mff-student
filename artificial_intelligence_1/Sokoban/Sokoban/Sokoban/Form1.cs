using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Sokoban
{
    public partial class Form1 : Form
    {
        private Visualizer vis;
        private Board b;
        private List<Direction> solution;
        private Solver solver;
        public static bool useDeadEndDetection = true,
            useAdvancedSuccessorsGeneration = true,
			useSymmetryBreaking = true;
        private Heuristic heuristic;

        public Form1()
        {
           
            //  ZDE NASTAVTE SVOU HEURISTIKU

            // heuristic = new BlindHeuristic();
            heuristic = new BlindHeuristicVilda();
            // heuristic = new SimpleDistanceHeuristic();
            //heuristic = new AdvancedDistanceHeuristic();
            //heuristic = new WeightedHeuristic(new AdvancedDistanceHeuristic(), 10);
          


            // zbytek neni treba editovat

            InitializeComponent();
            vis = new Visualizer(pictureBox1, label1);
            b = new Board();
            b.size = new Coords(15, 4);
            solver = new Astar();
			solver.setHeuristic(heuristic);
            useDeadEndDetection = checkBox1.Checked;
            useAdvancedSuccessorsGeneration = checkBox2.Checked;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (int.Parse(SeedtextBox.Text) < 0)
                b.createSimple();
            else
                b.randomize(int.Parse(SeedtextBox.Text));
            vis.visualize(b);
        }

        private void leftButton_Click(object sender, EventArgs e)
        {
            b.move(Direction.left);
            vis.visualize(b);
        }

        private void upBotton_Click(object sender, EventArgs e)
        {
            b.move(Direction.up);
            vis.visualize(b);
        }

        private void downButton_Click(object sender, EventArgs e)
        {
            b.move(Direction.down);
            vis.visualize(b);
        }

        private void rightButton_Click(object sender, EventArgs e)
        {
            b.move(Direction.right);
            vis.visualize(b);
        }

        private void Solvebutton_Click(object sender, EventArgs e)
        {
            solvingLabel.Text = "SOLVING ... ";
            solution = solver.solve(b, TimeSpan.FromSeconds(300));
            if (solution == null)
                solvingLabel.Text = "solution NOT found";
            else solvingLabel.Text = "solution found";
        }

        private void ShowSolutiontimer_Tick(object sender, EventArgs e)
        {
            if (solution == null || solution.Count == 0)
            {
                ShowSolutiontimer.Enabled = false;
                return;
            }
            b.move(solution[0]);
            solution.RemoveAt(0);
            vis.visualize(b);
        }

        private void ShowSolutionbutton_Click(object sender, EventArgs e)
        {
            ShowSolutiontimer.Enabled = true;
			if (solution == null || solution.Count == 0)
				return;
			int i = 1;
			foreach (var item in solution)
			{
				Console.WriteLine(i++ + "\t" + item.ToString());
			}
        }

        private void Save_button_Click(object sender, EventArgs e)
        {
            saveMap_saveFileDialog.ShowDialog();
        }

        private void saveMap_saveFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            b.save(saveMap_saveFileDialog.FileName);
        }

        private void Load_button_Click(object sender, EventArgs e)
        {
            LoadMap_openFileDialog.ShowDialog();
        }

        private void LoadMap_openFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            b.load(LoadMap_openFileDialog.FileName);
            vis.visualize(b);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
			useDeadEndDetection = checkBox1.Checked;
			if (vis != null && b != null)
				vis.visualize(b);
        }

		private void checkBox3_CheckedChanged(object sender, EventArgs e)
		{
			useSymmetryBreaking = checkBox3.Checked;
		}

		private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
			useAdvancedSuccessorsGeneration = checkBox2.Checked;
        }
    }
}
