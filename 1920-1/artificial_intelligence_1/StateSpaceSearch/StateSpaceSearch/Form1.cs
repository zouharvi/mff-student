using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StateSpaceSearch
{
    public partial class Form1 : Form
    {
        State currentState;
        Problem problemInstance;
        Visualizer visualizer;
        SearchEngine eng;
        int resultIndex;

        public Form1()
        {
            InitializeComponent();

            // Fifteen Puzzle:
            // problemInstance = new FifteenPuzzleProblem();
            // visualizer = new FifteenPuzzleVisualizer();
            // problemInstance.readFromFile("FP1.txt");
            // problemInstance.readFromFile("FP2.txt");
            // problemInstance.readFromFile("FP3.txt");


            // TSP:
            // problemInstance = new TSPProblem();
            // visualizer = new TSPVisualizer();
            // problemInstance.readFromFile("TSP1.txt");
            // problemInstance.readFromFile("TSP2.txt");
            // problemInstance = TSPProblem.createRandom(10, new Random(123));

            // Rubik's cube:
            problemInstance = new RubicsCubeProblem();
            visualizer = new CubeVisualizer();
            problemInstance.readFromFile("2");
            // problemInstance.readFromFile("3");

            visualizer.init(pictureBox1);
            currentState = problemInstance.initialState;
            visualizer.visualize(currentState);
        }

        private void button1_Click(object sender, EventArgs e)
        {
			// eng = new SearchEngine(SearchEngine.AlgType.DFS);
			eng = new IDS();

			eng.search(currentState);
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            List<State> result = eng.result;
            resultIndex = 0;
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (resultIndex >= eng.result.Count)
            {
                timer1.Enabled = false;
                return;
            }
            visualizer.visualize(eng.result[resultIndex]);
            resultIndex++;
        }
    }
}
