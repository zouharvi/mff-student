using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class GreedySolver : TSPSolver
    {
        private List<int> available;
		Random r;
		

        public GreedySolver()
        {
            available = new List<int>();
        }

		public GreedySolver(Random r)
			:this()
		{
			this.r = r;
		}

		#region TSPSolver Members

		protected virtual int findBest(int from, TSPInput input) 
        {
            int best = -1;
            double bestDistance = double.MaxValue;
            foreach (var item in available)
            {
                double distance = input.getDistance(from, item);
                if (distance < bestDistance)
                {
                    bestDistance = distance;
                    best = item;
                }
            }
            return best;
        }

        public TSPSolution solve(TSPInput input)
        {
            available.Clear();
            for (int i = 0; i < input.nodesCount; i++)
                available.Add(i);
            TSPSolution result = new TSPSolution(input);
			int start = 0;
			if (r != null) start = r.Next(input.nodesCount);

			int j = start;
			available.Remove(j);
            for (int i = 0; i < input.nodesCount - 1; i++)
            {
                int best = findBest(j, input);
                result.setSuccessor(j, best);
                j = best;
                available.Remove(best);
            }
            result.setSuccessor(j, start);
            return result;
        }

        #endregion
    }

    class GreedySolverFactory : TSPSolverFactory<GreedySolver>
    {
        #region TSPSolverFactory<RandomSolver> Members

        public GreedySolver create()
        {
            return new GreedySolver();
        }

        #endregion
    }

    class GreedyImprovedSolver : GreedySolver
    {


        protected override int findBest(int from, TSPInput input)
        {
            return base.findBest(from, input);
        }
    }

    class GreedyImprovedSolverFactory : TSPSolverFactory<GreedyImprovedSolver>
    {
        #region TSPSolverFactory<RandomSolver> Members

        public GreedyImprovedSolver create()
        {
            return new GreedyImprovedSolver();
        }

        #endregion
    }

    class GreedyGrowingSolver : TSPSolver
    {
        struct edge
        {
            public int node1, node2;
            public double distance;

            public edge(int node1, int node2, double distance)
            {
                this.node1 = node1;
                this.node2 = node2;
                this.distance = distance;
            }
        }

        private int edgesUsed = 0;
        List<List<int>> succ;

        public GreedyGrowingSolver()
        {
            succ = new List<List<int>>();
        }

        public TSPSolution solve(TSPInput input)
        {
            TSPSolution result = new TSPSolution(input);
            succ = new List<List<int>>();

            edgesUsed = 0;
            List<edge> edges = new List<edge>();
            for (int i = 0; i < input.nodesCount; i++)
            {
                succ.Add(new List<int>());
                for (int j = 0; j < i; j++)
                    edges.Add(new edge(i, j, input.getDistance(i, j)));
            }

            edges.Sort((a, b) => (int)(a.distance - b.distance));
            int index = -1;
            while (edgesUsed < input.nodesCount)
            {
                index++;
                edge e = edges[index];
                if (succ[e.node1].Count >= 2 || succ[e.node2].Count >= 2)
                    continue;
                if (createsCycle(e) && edgesUsed != input.nodesCount - 1)
                    continue;
                addToSolution(e);
            }
            addEdgesToResult(result);
            return result;
        }

        private void addEdgesToResult(TSPSolution result)
        {
            int node = 0, succ = 0, pred = -1;
            for (int i = 0; i < result.problem.nodesCount; i++)
            {
                succ = getSuccessor(node, pred);
                result.setSuccessor(node, succ);
                pred = node;
                node = succ;
            }
        }

        private void addToSolution(edge e)
        {
            succ[e.node1].Add(e.node2);
            succ[e.node2].Add(e.node1);
            edgesUsed++;
        }

        private bool createsCycle(edge e)
        {
            if (succ[e.node1].Count < 1 && succ[e.node2].Count < 1)
                return false;

            int node = e.node1, pred = e.node2;
            while(node != e.node2)
            {
                if (node == -1)
                    return false;
                int pom = node;
                node = getSuccessor(node, pred);
                pred = pom;
            }
            return true;
        }

        private int getSuccessor(int node, int predecessor)
        {
            if (succ[node].Count == 0)
                return -1;
            if (succ[node][0] == predecessor)
            {
                if (succ[node].Count == 1)
                    return -1;
                return succ[node][1];
            }
            return succ[node][0];
        }
    }
    class GreedyGrowingSolverSolverFactory : TSPSolverFactory<GreedyGrowingSolver>
    {
        #region TSPSolverFactory<GreedyGrowingSolver> Members

        public GreedyGrowingSolver create()
        {
            return new GreedyGrowingSolver();
        }

        #endregion
    }


}
