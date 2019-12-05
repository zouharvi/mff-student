using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using LocalSearch;

namespace TSP
{
    struct TPSCouple
    {
        public int first, second;

        public TPSCouple(int first, int second)
        {
            this.first = first;
            this.second = second;
        }

        public int getTheOther(int value)
        {
            if (first == value)
                return second;
            else return first;
        }

        public void set(int value)
        {
            if (first == value)
                second = value;
            else first = value;
        }
    }

    class TSPSolution
    {
        private bool isDistanceComputed = false;
        private double _totalDistance;

        public TSPInput problem;

        private Dictionary<int, TPSCouple> succesors; //successors in the path. position of the neibhours indexed by the position of the node

        public double totalDistance
        {
            get
            {
                if (!isDistanceComputed)
                    computeDistance();
                return _totalDistance;
            }
            private set
            {
                _totalDistance = value;
            }
        }
        public bool isValid
        {
            get;
            private set;
        }
        public List<Edge> edges;

        public TSPSolution(TSPInput inp)
        {
            this.problem = inp;
            this.succesors = new Dictionary<int, TPSCouple>();
            this.edges = new List<Edge>();
        }
   
        public double computeDistance()
        {
            if (isDistanceComputed)
                return _totalDistance;
            _totalDistance = 0;
            for (int i = 0, j = 0; i < problem.nodesCount; i++, j = getSuccessor(j))
            {
                _totalDistance += problem.getDistance(j, getSuccessor(j));
            }
            isDistanceComputed = true;
            return totalDistance;
        }
        public int getSuccessor(int node, int notWantedSuccesor)
        {
            return succesors[node].getTheOther(notWantedSuccesor);
        }
        public int getSuccessor(int node)
        {
            return succesors[node].first;
        }
        public void setSuccessor(int node, int successor)
        {
            isDistanceComputed = false;
            if (!succesors.ContainsKey(node))
                succesors.Add(node, new TPSCouple(successor, successor));
            succesors[node].set(successor);
            edges.Add(new Edge(node, successor, this.problem, problem.getDistance(node, successor)));
        }
        public bool validate()
        {
            isValid = false;
            HashSet<int> visited = new HashSet<int>();
            int node = 0;
            while (!visited.Contains(node))
            {
                visited.Add(node);
                if (!succesors.ContainsKey(node))
                    return false;
                node = getSuccessor(node);
            }
            if (visited.Count < problem.nodesCount)
                return false;

            isValid = true;
            return true;
        }

        internal static TSPSolution fromString(string result, TSPInput inp)
        {
            string[] points = result.Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);
            if (points.Length != inp.nodesCount)
            {
                System.Windows.Forms.MessageBox.Show("Spatna delka reseni.\nReseni ma mit delku " + inp.nodesCount + ". Vase reseni ma delku " + points.Length);
                return null;
            }
            TSPSolution sol = new TSPSolution(inp);
            for (int i = 0; i < points.Length - 1; i++)
            {
                sol.setSuccessor(int.Parse(points[i]) - 1, int.Parse(points[i + 1]) - 1);
            }
            sol.setSuccessor(int.Parse(points[points.Length - 1]) - 1, int.Parse(points[0]) - 1);
            return sol;
        }
    }

    class PermutationStandard : IntegerSequenceCandidateSolution<TSPInput>
    {
        public int size;

        public TSPSolution convertToTSPSol()
        {
            TSPSolution sol = new TSPSolution(problem);
            for (int i = 0; i < size - 1; i++)
            {
                sol.setSuccessor(data[i], data[i + 1]);
            }
            sol.setSuccessor(data[size - 1], data[0]);
            return sol;
        }

        public PermutationInversions convertToInversions()
        {
            PermutationInversions inv = new PermutationInversions(this.problem)
            {
                size = this.size,
                data = new int[this.size]
            };
            for (int i = 0; i < this.size; i++)
            {
                int count = 0, m = 0;
                while (this.data[m] != i)
                {
                    if (this.data[m] > i)
                        count++;
                    m++;
                }
                inv.data[i] = count;
            }
            return inv;
        }

        public PermutationStandard(TSPInput input)
            :base(new int[input.nodesCount], input)
        {
            this.size = input.nodesCount;
        }

        public PermutationStandard(TSPSolution sol) : this(sol.problem)
        {
            data[0] = 0;
            data[1] = sol.getSuccessor(data[0]);
            for (int i = 1; i < size - 1; i++)
            {
                data[i + 1] = sol.getSuccessor(data[i], data[i - 1]);
            }
        }

        public override double Evaluate()
        {
            double totalDistance = 0;
            for (int i = 0; i < size - 1; i++)
            {
                totalDistance += problem.getDistance(data[i], data[i + 1]);
            }
            totalDistance += problem.getDistance(data[size - 1], data[0]);
            return totalDistance;
        }

        public PermutationStandard clone()
        {
            PermutationStandard res = new PermutationStandard(this.problem);
            res.size = this.size;
            res.data = new int[this.size];
            Array.Copy(this.data, res.data, this.size);
            return res;
        }

        public override IntegerSequenceCandidateSolutionFactory<IntegerSequenceCandidateSolution<TSPInput>, TSPInput> GetFactory()
        {
            return PermutationStandardFactory.GetInstance();
        }
    }

    class PermutationInversions : IntegerSequenceCandidateSolution<TSPInput>
    {
        public int size;

        public PermutationStandard convertToStandard()
        {
            PermutationStandard std = new PermutationStandard(this.problem);
            int[] pos = new int[this.size];
            for (int i = size - 1; i >= 0; i--)
            {
                for (int m = i; m < size; m++)
                {
                    if (pos[m] >= this.data[i] + 1)
                        pos[m]++;
                    pos[i] = data[i] + 1;
                }
            }
            for (int i = 0; i < size; i++)
            {
                std.data[pos[i] - 1] = i;
            }
            return std;
        }

        public TSPSolution convertToTSPSol()
        {
            return this.convertToStandard().convertToTSPSol();
        }

        public PermutationInversions(TSPInput input)
            : base(new int[input.nodesCount], input)
        {
            this.size = input.nodesCount;
        }

        public override double Evaluate()
        {
            return convertToStandard().Evaluate();
            //return convertToTSPSol().totalDistance;
        }

        public override IntegerSequenceCandidateSolutionFactory<IntegerSequenceCandidateSolution<TSPInput>, TSPInput> GetFactory()
        {
            return PermutationInversionsFactory.GetInstance();
        }
    }

    class PermutationStandardFactory : IntegerSequenceCandidateSolutionFactory<PermutationStandard, TSPInput>
    {
        public PermutationStandard Create(int[] data, TSPInput problem)
        {
            var res = new PermutationStandard(problem);
            res.data = data;
            return res;
        }

        public PermutationStandard CreateEmpty(TSPInput problem)
        {
            var res = new PermutationStandard(problem);
            res.data = new int[problem.nodesCount];
            return res;
        }

        public static PermutationStandardFactory GetInstance()
        {
            return singleton.Value;
        }

        private static Lazy<PermutationStandardFactory> singleton = new Lazy<PermutationStandardFactory>(() => new PermutationStandardFactory());

        private PermutationStandardFactory()
        { }
    }

    class PermutationInversionsFactory : IntegerSequenceCandidateSolutionFactory<PermutationInversions, TSPInput>
    {
        public PermutationInversions Create(int[] data, TSPInput problem)
        {
            var res = new PermutationInversions(problem);
            res.data = data;
            return res;
        }

        public static PermutationInversionsFactory GetInstance()
        {
            return singleton.Value;
        }

        private static Lazy<PermutationInversionsFactory> singleton = new Lazy<PermutationInversionsFactory>(() => new PermutationInversionsFactory());

        private PermutationInversionsFactory()
        {  }

    }

    class PermutationRandomizer : LSNullaryOperator<PermutationStandard, TSPInput>
    {
        Random r;

        public PermutationStandard Apply(TSPInput Problem)
        {
            var res = PermutationStandardFactory.GetInstance().CreateEmpty(Problem);
            int size = Problem.nodesCount;

            List<int> notUsed = new List<int>();
            for (int i = 0; i < size; i++)
            {
                notUsed.Add(i);
            }
            for (int i = 0; i < size; i++)
            {
                int selectedIndex = r.Next(notUsed.Count);
                res.data[i] = notUsed[selectedIndex];
                notUsed.RemoveAt(selectedIndex);
            }
            return res;
        }

        public PermutationRandomizer(Random r)
        {
            this.r = r;
        }
    }

    class PermutationRandomizer2 : LSNullaryOperator<PermutationStandard, TSPInput>
    {
        Random r;

        public PermutationRandomizer2(Random r)
        {
            this.r = r;
        }

        public PermutationStandard Apply(TSPInput problem)
        {
            var res = PermutationStandardFactory.GetInstance().CreateEmpty(problem);
            int size = problem.nodesCount;

            int distanceused = 0, allUsed = 0;
            List<int> notUsed = new List<int>();
            for (int i = 1; i < size; i++)
            {
                notUsed.Add(i);
            }
            res.data[0] = 0;

            double distanceSum = 0;
            int count = 0;
            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    distanceSum += problem.getDistance(i, j);
                    count++;
                }
            }
            double distanceLimit = (distanceSum / count) / 2;

            for (int i = 1; i < size; i++)
            {
                var nearByCities = notUsed.Where(a => problem.getDistance(res.data[i - 1], a) < distanceLimit);
                if (nearByCities.Count() == 0)
                {
                    allUsed++;
                    int selectedIndex = r.Next(notUsed.Count);
                    res.data[i] = notUsed[selectedIndex];
                    notUsed.RemoveAt(selectedIndex);
                }
                else
                {
                    distanceused++;
                    int selectedIndex = r.Next(nearByCities.Count());
                    res.data[i] = nearByCities.ToList()[selectedIndex];
                    List<int> ff = nearByCities.ToList();
                    notUsed.Remove(res.data[i]);
                }
            }
            return res;
        }
    }
}
