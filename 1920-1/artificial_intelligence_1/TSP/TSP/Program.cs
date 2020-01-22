using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace TSP
{
    static class Program
    {
        
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        
        /*
        static void Main()
        {
            runTests();
        }
        */
        static void runTests()
        {
            Random rand = new Random(123);
            List<TSPInput> inputs = new List<TSPInput>();
            for (int i = 5; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    inputs.Add(TSPGenerator.generateUniform(i, rand));
                }
            }

            TSPPreprocessor p = new TSPPreprocessor();
            TreeEvaluator e = new TreeEvaluator();

            Console.WriteLine("Number\tsize\tnormal\tbest\ttime (sec)");
            for (int i = 0; i < inputs.Count; i++)
            {
                Console.Write(i + "\t" + inputs[i].nodesCount + "\t");
                TreeNode root = TreeSolver.buildTree(inputs[i]);
                Console.Write(e.eval(root) + "\t");
                DateTime start = DateTime.Now;
                p.findBestPermutation(inputs[i]);
                DateTime end = DateTime.Now;
                Console.WriteLine(p.bestFitness + "\t" + (end - start).TotalSeconds);
            }
        }
    }
}
