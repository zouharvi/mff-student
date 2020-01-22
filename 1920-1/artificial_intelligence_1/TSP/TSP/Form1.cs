using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace TSP
{
    public partial class Form1 : Form
    {
        TSPInput inp;
        static TSPVisualizer vis;
        TSPSolver solver;
        TSPSolution solution;
        TreeSolver treeS;
        Random r = new Random();    //set random seed here if needed

        public Form1()
        {
            InitializeComponent();
            vis = new TSPVisualizer(pictureBox1);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            inp = TSPGenerator.generateUniform(int.Parse(NodesCount_textBox.Text), r);
            vis.draw(inp);
        }

        public void solveAndShow()
        {
            solution = solver.solve(inp);
            solution.computeDistance();
            Length_label.Text = solution.totalDistance.ToString();
            vis.draw(solution);
        }

        private void generateClusters_button_Click(object sender, EventArgs e)
        {
            inp = TSPGenerator.generateClusters(int.Parse(NodesCount_textBox.Text), int.Parse(clusters_textBox.Text), r);
            vis.draw(inp);
        }

        private void generateHybrid_button_Click(object sender, EventArgs e)
        {
            inp = TSPGenerator.generateHybrid(int.Parse(NodesCount_textBox.Text), int.Parse(clusters_textBox.Text), r);
            vis.draw(inp);
        }

        private void ClustersAntiGreedy_button_Click(object sender, EventArgs e)
        {
            inp = TSPGenerator.generateClustersAntiGreedy(int.Parse(NodesCount_textBox.Text), int.Parse(clusters_textBox.Text), r);
            vis.draw(inp);
        }

        private void CreateTreeButton_Click(object sender, EventArgs e)
        {
            if (treeS == null || treeS.IsDisposed)
                treeS = new TreeSolver(inp);
            treeS.inp = inp;
            treeS.Show();
            treeS.buildTree();
            treeS.computeLeafs();
            Length_label.Text = treeS.leafsCount.ToString();
            TreeVisualizer tviz = new TreeVisualizer(treeS);
            tviz.draw(treeS.root, treeS.maxVal, treeS.minVal);
        }

        private void ShowNumberscheckBox_CheckedChanged(object sender, EventArgs e)
        {
            vis.setShowNumbers(ShowNumberscheckBox.Checked);
        }

        private void Extern_button_Click(object sender, EventArgs e)
        {
            Process p = new Process();
            //p.StartInfo.FileName = @"C:\Documents and Settings\Ota\Dokumenty\Visual Studio 2010\Projects\MinesVisualizer\bin\Debug\MinesVisualizer.exe";
            p.StartInfo.FileName = @".\solver.exe";
            p.StartInfo.UseShellExecute = false;
            p.StartInfo.RedirectStandardInput = true;
            p.StartInfo.RedirectStandardOutput = true;
            p.Start();
            p.StandardInput.WriteLine(inp.nodesCount);
            for (int i = 0; i < inp.nodesCount; i++)
			{
			    p.StandardInput.WriteLine((int)(Math.Floor(inp.getPoint(i).x)) + " " + (int)(Math.Floor(inp.getPoint(i).y)));
			}
            string result = p.StandardOutput.ReadLine();
            solution = TSPSolution.fromString(result, inp);
            solution.computeDistance();
            Length_label.Text = solution.totalDistance.ToString();
            vis.draw(solution);
        }

        private void Solve_button_Click(object sender, EventArgs e)
        {
            if (engines_listBox.SelectedIndex == 3)
            {
                TreeAproximativeSolver s = new TreeApproximativeSolverFactory().create();
                solution = s.solve(inp);
                solution.computeDistance();
                Length_label.Text = solution.totalDistance.ToString();
                vis.drawSpanningTree(inp, s.successorsList);
                vis.draw(solution, false);
            }
            else
            {
                switch (engines_listBox.SelectedIndex)
                {
                    case 0:
                        solver = new RandomSolverFactory().create();
                        break;
                    case 1:
                        solver = new GreedySolverFactory().create();
                        break;
                    case 2:
                        solver = new GreedyGrowingSolverSolverFactory().create();
                        break;
                    case 4:
                        solver = new OptimalSolverFactory().create();
                        break;
                    case 5:
                        solver = new CentroidBubbleSolver();
                        break;
                    case 6:
                        /*
                        solver = new PlannerWrapperFactory().create(plannerType.AstarBlind);
                        break;
                         */
                        HillClimbingTSPManager s = new HillClimbingTSPManager(vis, r);
                        solution = s.solve(inp);
                        solution.computeDistance();
                        Length_label.Text = solution.totalDistance.ToString();
                        vis.draw(solution, false);
                        return;
					case 7:
                        /*
						TSPSolver so = new GASolver(vis, r);
						solution = so.solve(inp);
						solution.computeDistance();
						Length_label.Text = solution.totalDistance.ToString();
						vis.draw(solution);
                        */
						return;

				}
                solveAndShow();
            }



            /*
0 Random engine
1 Greedy engine
2 Greedy Growing engine
3 Spanning tree 2-approximation
4 Optimal solver
5 Star solver
6 Planner Blind
7 Planner + FF heuristic
8 Beam Search blind
9 Hill climbing blind
10 Hill climbing + FF heuristic
11 MCTS blind
12 MCTS + FF heuristic
             */

        }

        private void Load_button_Click(object sender, EventArgs e)
        {
            LoadInput_openFileDialog.ShowDialog();
        }

        private void Save_button_Click(object sender, EventArgs e)
        {
            SaveInput_saveFileDialog.ShowDialog();
        }

        private void LoadInput_openFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            inp = TSPInput.create(LoadInput_openFileDialog.FileName);
            vis.draw(inp);
        }

        private void SaveInput_saveFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            inp.save(SaveInput_saveFileDialog.FileName);
        }

    }
}
