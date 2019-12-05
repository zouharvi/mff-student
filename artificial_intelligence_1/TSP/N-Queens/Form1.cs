using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using LocalSearch;

namespace N_Queens
{
    public partial class Form1 : Form
    {
        NQueensVisualizer vis;
        NQueensCandidateSol currentSol;
        NQueensProblem p;

        /// <summary>
        /// Random object used in all subsequent computations. Change random seed here if needed.
        /// </summary>
        Random rand = new Random();

        public Form1()
        {
            InitializeComponent();
            vis = new NQueensVisualizer(this.pictureBox1);
        }

        private void generate_button_Click(object sender, EventArgs e)
        {
            p = new NQueensProblem(int.Parse(textBox1.Text));
            vis.DrawGrid(p);
        }

        private void printProgress(NQueensCandidateSol sol, int steps)
        {
            this.currentSol = sol;
            vis.Draw(sol);
            Console.WriteLine("Steps: " + steps + "\terrors: " + sol.Evaluate());
        }

        private void runHC_button_Click(object sender, EventArgs e)
        {
            var initializer = new Randomizer(rand);
            var modifier = new ShiftValue(rand, 0, this.p.boardSize);

            HillClimbingSolver<NQueensCandidateSol, NQueensProblem> solver =
                new HillClimbingSolver<NQueensCandidateSol, NQueensProblem>(rand, initializer, modifier);

            var res = solver.Solve(this.p, printProgress);
        }
    }
}
