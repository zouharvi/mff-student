using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class TSPPreprocessor
    {
        public TreeEvaluator evaluator = new TreeEvaluator();
        private TreeNode root;
        private TSPInput inp;

        public double bestFitness;
        public List<int> bestPermutation;

        public void findBestPermutation(TSPInput input)
        {
            inp = input;
            bestFitness = double.MaxValue;
            bestPermutation = new List<int>(input.nodesCount);
            List<int> available = new List<int>(input.nodesCount);
            for (int i  =1; i < input.nodesCount; i++)
            {
                available.Add(i);
            }
            searchPermutations(available, new List<int>(input.nodesCount));
        }

        private void searchPermutations(List<int> available, List<int> permutation)
        {
            if (available.Count == 0)
            {
                root = TreeSolver.buildTree(inp, permutation);
                double val = evaluator.eval(root, permutation);
                if (val < bestFitness)
                {
                    bestFitness = val;
                    bestPermutation.Clear();
                    bestPermutation.AddRange(permutation);
                }
                return;
            }
            for (int i = 0; i < available.Count; i++)
            {
                permutation.Add(available[i]);
                available.RemoveAt(i);
                searchPermutations(available, permutation);
                available.Insert(i, permutation[permutation.Count - 1]);
                permutation.RemoveAt(permutation.Count - 1);
            }
        }

        public TSPPreprocessor()
        {

        }

    }
}
