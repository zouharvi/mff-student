using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class RandomSolver : TSPSolver
    {
        private List<int> available;
        private static Random r = new Random();

        public RandomSolver()
        {
            available = new List<int>();
        }

        #region TSPSolver Members

        public TSPSolution solve(TSPInput input)
        {
            available.Clear();
            for (int i = 1; i < input.nodesCount; i++)
                available.Add(i);
            TSPSolution result = new TSPSolution(input);
            int j = 0;
            for (int i = 0; i < input.nodesCount - 1; i++)
            {
                int randomIndex = r.Next(available.Count);
                result.setSuccessor(j, available[randomIndex]);
                j = available[randomIndex];
                available.RemoveAt(randomIndex);
            }
            result.setSuccessor(j, 0);
            return result;
        }

        #endregion
    }

    class RandomSolverFactory : TSPSolverFactory<RandomSolver>
    {
        #region TSPSolverFactory<RandomSolver> Members

        public RandomSolver create()
        {
            return new RandomSolver();
        }

        #endregion
    }
}
