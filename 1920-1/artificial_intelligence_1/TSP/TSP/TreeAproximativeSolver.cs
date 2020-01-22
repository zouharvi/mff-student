using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class TreeAproximativeSolver : TSPSolver
    {
        public Dictionary<int, List<int>> successorsList;
        List<Edge> edges;
        int[] representatives;
        int lastNodeLabeled;
        HashSet<int> visited = new HashSet<int>();
        
        private int findRepresentative(int node)
        {
            int representative = node;
            while (representatives[representative] != representative)
                representative = representatives[representative];
            representatives[node] = representative;
            return representative;
        }

        private void addEdge(Edge e)
        {
            if (!successorsList.ContainsKey(e.from))
                successorsList.Add(e.from, new List<int>());
            if (!successorsList.ContainsKey(e.to))
                successorsList.Add(e.to, new List<int>());
            successorsList[e.from].Add(e.to);
            successorsList[e.to].Add(e.from);
        }

        private void computeSpanningTree(TSPInput input)
        {
            representatives = new int[input.nodesCount];
            for (int i = 0; i < input.nodesCount; i++)
            {
                representatives[i] = i;
            }
            successorsList = new Dictionary<int, List<int>>();
            copyEdgesLengths(input);
            int selectedEdgesCount = 0;
            for (int i = 0; i < edges.Count; i++)
            {
                if (selectedEdgesCount == input.nodesCount - 1)
                    break;
                int firstRepre = findRepresentative(edges[i].from),
                    secondRepre = findRepresentative(edges[i].to);
                if (firstRepre == secondRepre)
                    continue;
                representatives[firstRepre] = secondRepre;
                selectedEdgesCount++;
                addEdge(edges[i]);
            }
        }

        private void labelTreePreOrder(int start, TSPSolution solution)
        {
            if (visited.Contains(start))
                return;
            lastNodeLabeled = start;
            visited.Add(start);
            foreach (var item in successorsList[start])
            {
                if (visited.Contains(item))
                    continue;
                solution.setSuccessor(lastNodeLabeled, item);
                labelTreePreOrder(item, solution);
            }
        }

        private void copyEdgesLengths(TSPInput input)
        {
            edges = new List<Edge>();
            for (int i = 0; i < input.nodesCount; i++)
                for (int j = i + 1; j < input.nodesCount; j++)
                    edges.Add(new Edge(i, j, input, input.getDistance(i, j)));
            edges.Sort((t1, t2) => t1.weight.CompareTo(t2.weight));
        }

        #region TSPSolver Members

        public TSPSolution solve(TSPInput input)
        {
            computeSpanningTree(input);
            TSPSolution result = new TSPSolution(input);
            visited.Clear();
            labelTreePreOrder(0, result);
            result.setSuccessor(lastNodeLabeled, 0);
            return result;
            //return null;
        }

        #endregion
    }

    class TreeApproximativeSolverFactory : TSPSolverFactory<TreeAproximativeSolver>
    {
        #region TSPSolverFactory<TreeAproximativeSolver> Members

        public TreeAproximativeSolver create()
        {
            return new TreeAproximativeSolver();
        }

        #endregion
    }
}
