using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace StateSpaceSearch
{
    struct StateInformation
    {
        public int gValue;
        public bool isClosed;

        public StateInformation(int val = 0)
        {
            this.gValue = val;
            this.isClosed = false;
        }

		public override string ToString()
		{
			return "cost=" + gValue;
		}
	}

    class SearchEngine
    {
        public enum AlgType { RED_BLACK, DFS, BFS };

        public IHeap<int, State> openNodes;
        protected Dictionary<State, StateInformation> gValues;
        protected Dictionary<State, State> predecessor;
        public TimeSpan searchTime;
        protected DateTime start;
        protected bool quiet = false;
        public List<State> result;
        public int solutionCost;
        protected List<StateCostPair> successors = new List<StateCostPair>();
		protected int branchingSum, branchingCount, maxGVal;
        private Process proc;

        protected virtual void addToClosedList(State state)
        {
            StateInformation f = gValues[state];
            f.isClosed = true;
            gValues[state] = f;
			if (maxGVal < f.gValue)
				maxGVal = f.gValue;
        }

        protected virtual void addToOpenList(State s, int gValue, State pred)
        {
            if (!gValues.ContainsKey(s))
            {
                gValues.Add(s, new StateInformation(gValue));
                predecessor.Add(s, pred);
                openNodes.insert(gValue, s);
                return;
            }
            if (gValues[s].gValue > gValue)
            {
                StateInformation f = gValues[s];
                f.gValue = gValue;
                gValues[s] = f;
                predecessor[s] = pred;
                openNodes.insert(gValue, s);
                return;
            }
        }

        protected virtual void printSearchStats(bool quiet)
        {
            DateTime now = DateTime.Now;
            printMessage("Time elapsed: " + (now - start).TotalSeconds + " seconds", quiet);
			printMessage("Open nodes: " + openNodes.size(), quiet);
			printMessage("Expanded nodes: " + gValues.Count, quiet);
			printMessage("Max GVal: " + maxGVal, quiet);
			printMessage("Speed: " + (gValues.Count / (now - start).TotalSeconds).ToString("0.00") + " states per second", quiet);
			printMessage("Average branching: " + (((double)branchingSum) / branchingCount).ToString("0.00"), quiet);
            printMessage("Memory used: " + (proc.PrivateMemorySize64/1024.0/1024/1024).ToString("0.00") + "GB", quiet);
			printMessage("\n", quiet);
		}

        protected void printMessage(string message, bool quiet)
        {
            if (!quiet)
                Console.WriteLine(message);
        }

        public SearchEngine(AlgType algType)
        {
            gValues = new Dictionary<State, StateInformation>();
            switch(algType) {
                case AlgType.RED_BLACK:
                    openNodes = new RedBlackTreeHeap<State>();
                    break;
                case AlgType.BFS:
                    openNodes = new QueueFIFO<State>();
                    break;
                case AlgType.DFS:
                    openNodes = new StackLIFO<State>();
                    break;
            }
            proc = Process.GetCurrentProcess();
        }

        public virtual void search(State s)
        {
			branchingCount = 1;
			branchingSum = 1;
			maxGVal = 0;

			printMessage("--- search started ---", quiet);
            State currentState = null;
            predecessor = new Dictionary<State, State>();
            gValues.Clear();
            openNodes.clear();
            start = DateTime.Now;
            openNodes.insert(0, s);
            gValues.Add(s, new StateInformation());
            predecessor.Add(s, null);
            int steps = -1;
            while (openNodes.size() > 0)
            {
                steps++;

				if (steps % 10000 == 0)
                    printSearchStats(quiet);

                currentState = openNodes.removeMin();
                if (gValues[currentState].isClosed)
                    continue;
                addToClosedList(currentState);
                if (currentState.isFinal())
                {
                    DateTime end = DateTime.Now;
                    searchTime = (end - start);
                    int GVAL = gValues[currentState].gValue;
                    printMessage("Plan length: " + GVAL, quiet);
                    printSearchStats(quiet);
                    this.result = extractSolution(currentState);
                    this.solutionCost = GVAL;
                    printMessage("--- search ended ---", quiet);
                    return;
                }
                int currentGValue = gValues[currentState].gValue;

                currentState.getSuccessors(successors);
				branchingSum += successors.Count;
				branchingCount++;
                foreach (var item in successors)
                {
                    State state = item.state;
                    int gVal = currentGValue + item.cost;
                    addToOpenList(state, gVal, currentState);
                }
            }
            printMessage("No solution exists.", quiet);
        }

        protected List<State> extractSolution(State state)
        {
            List<State> result = new List<State>();
            State current = state;
            while (current != null)
            {
                State pred = predecessor[current];
                if (pred == null)
                    break;
                result.Insert(0, current);
                current = pred;
            }
            return result;
        }

    }
    
    class IDS : SearchEngine
    {
        private int maxDepth = 0;
        private int nextDepth = 0;
        private const int MAX_MAX_DEPTH = int.MaxValue;

        public IDS() : base(AlgType.DFS) { }

        public override void search(State s)
        {
            DateTime start = DateTime.Now;
            while(result == null && maxDepth != MAX_MAX_DEPTH)
            {
                nextDepth = MAX_MAX_DEPTH;
                base.search(s);
                maxDepth = nextDepth;
            }
            printMessage("Time total: " + (DateTime.Now - start).TotalSeconds + " seconds", quiet);

            if(maxDepth == MAX_MAX_DEPTH)
                Console.WriteLine("No solution found at MAX_MAX_DEPTH");
        }

        protected override void addToOpenList(State s, int gValue, State pred)
        {
            if(gValue <= maxDepth)
                base.addToOpenList(s, gValue, pred);
            if(gValue > maxDepth && gValue < nextDepth)
                nextDepth = gValue;
        }
    }
}
