using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class SolutionPostProcessor
    {
        public void postProcess(TSPSolution sol)
        {
            
        }

        private bool isShorterToSwap(Edge e1, Edge e2, TSPSolution sol, bool firstChoice)
        {
            if (firstChoice) return sol.problem.getDistance(e1.from, e2.from) + sol.problem.getDistance(e1.to, e2.to)
                < e1.weight + e2.weight;
            return sol.problem.getDistance(e1.from, e2.to) + sol.problem.getDistance(e1.to, e2.from)
                < e1.weight + e2.weight;
        }

        private void swap(Edge e1, Edge e2, TSPSolution sol, bool firstChoice)
        {
            sol.edges.Remove(e1);
            sol.edges.Remove(e2);
        }

    }
}
