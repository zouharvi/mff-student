using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using LocalSearch;

namespace TSP
{
    class HillClimbingTSPManager : TSPSolver
    {
        HillClimbingSolver<PermutationStandard, TSPInput> solver;

        private TSPVisualizer visualizer;

        public TSPSolution solve(TSPInput input)
        {
            Console.WriteLine("Hill climbing started");
            var res = solver.Solve(input, printProgress);
            Console.WriteLine("Search ended");
            return res.convertToTSPSol();
        }

        private void printProgress(PermutationStandard currentBest, int steps)
        {
            var sol = currentBest.convertToTSPSol();
            visualizer.draw(sol);
            Console.WriteLine("Steps: " + steps + " Best distance: " + sol.totalDistance);
        }

        public HillClimbingTSPManager(TSPVisualizer visualizer, Random r)
        {
            this.visualizer = visualizer;

            var initializationOperator = new PermutationRandomizer(r);
            //var initializationOperator = new PermutationRandomizer2(r);

            var modificationOperator = new SimpleSwapOperator<PermutationStandard, TSPInput, PermutationStandardFactory>(PermutationStandardFactory.GetInstance(), r);
            //var modificationOperator = new Rotate3Values<PermutationStandard, TSPInput, PermutationStandardFactory>(PermutationStandardFactory.GetInstance(), r);

            this.solver = new HillClimbingSolver<PermutationStandard, TSPInput>(r, initializationOperator, modificationOperator);
        }
    }
}
