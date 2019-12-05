using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class OptimalSolver : TSPSolver
    {
        private double best = double.MaxValue;
        private int[] bestSolution;

        public OptimalSolver()
        {
            
        }

        #region TSPSolver Members

        private bool isCrossing(TSPInput inp, List<int> currentEdges)
        {
            if (currentEdges.Count <= 2)
                return false;
            TSPPoint A = inp.getPoint(currentEdges[currentEdges.Count - 2]),
                B = inp.getPoint(currentEdges[currentEdges.Count - 1]);
            double p = (B.y - A.y) / (B.x - A.x),
                q = A.y - p * A.x;
            for (int i = 0; i < currentEdges.Count-2; i++)
            {
                if (Edge.isCrossing(A, B, inp.getPoint(currentEdges[i]), inp.getPoint(currentEdges[i + 1]), p, q) &&
                    Edge.isCrossing(inp.getPoint(currentEdges[i]), inp.getPoint(currentEdges[i + 1]), A, B))
                    return true;
            }
            return false;
        }

        private void trySolve(TSPInput input, List<int> currentPart, List<int> remainning, double currentLength)
        {
            if (currentLength > best)
                return;
            
            // pokud se krizi prave pridana hrana s nejakou dalsi tak konec - v optimalnim reseni se hrany nekrizi.
            if (isCrossing(input, currentPart))
                return;

            if (remainning.Count == 0)
            {
                if (currentLength + input.getDistance(currentPart[currentPart.Count-1], 0) < best)
                {
                    best = currentLength + input.getDistance(currentPart[currentPart.Count - 1], 0);
                    currentPart.CopyTo(bestSolution);
                }
                return;
            }
            for (int i = 0; i < remainning.Count; i++)
            {
                int item = remainning[i];
                double distance = input.getDistance(currentPart[currentPart.Count - 1], item);
                currentPart.Add(item);
                remainning.RemoveAt(i);
                trySolve(input, currentPart, remainning, currentLength + distance);
                remainning.Insert(i, item);
                currentPart.RemoveAt(currentPart.Count - 1);
            }
        }

        public TSPSolution solve(TSPInput input)
        {
            GreedySolver s = new GreedySolver();
            best = s.solve(input).computeDistance() + 1;

            bestSolution = new int[input.nodesCount];
            List<int> current = new List<int>();
            current.Add(0);
            List<int> remaining = new List<int>();
            for (int i = 1; i < input.nodesCount; i++)
                remaining.Add(i);
            trySolve(input, current, remaining, 0);
            TSPSolution result = new TSPSolution(input);
            for (int i = 0; i < input.nodesCount-1; i++)
            {
                result.setSuccessor(bestSolution[i], bestSolution[i + 1]);
            }
            result.setSuccessor(bestSolution[input.nodesCount - 1], 0);
            return result;
        }

        #endregion
    }

    class OptimalSolverFactory : TSPSolverFactory<OptimalSolver>
    {
        #region TSPSolverFactory<OptimalSolver> Members

        public OptimalSolver create()
        {
            return new OptimalSolver();
        }

        #endregion
    }
}
