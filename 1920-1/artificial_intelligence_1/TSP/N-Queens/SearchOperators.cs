using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LocalSearch;

namespace N_Queens
{
    class Randomizer : LSNullaryOperator<NQueensCandidateSol, NQueensProblem>
    {
        Random rand;
        public NQueensCandidateSol Apply(NQueensProblem problem)
        {
            var data = Enumerable.Range(0, problem.boardSize).Select(q => rand.Next(problem.boardSize)).ToArray();
            var res = new NQueensCandidateSol(data, problem);
            return res;
        }

        public Randomizer(Random rand)
        {
            this.rand = rand;
        }
    }

    /// <summary>
    /// Changes value at a randomly selected index by +1 or -1 while keeping it within given bounds
    /// </summary>
    class ShiftValue : LSUnaryOperator<NQueensCandidateSol, NQueensProblem>
    {
        Random rand;
        int minVal, maxVal;

        public NQueensCandidateSol Apply(NQueensCandidateSol candidateSolution)
        {
            var data = candidateSolution.data.ToArray();
            var res = new NQueensCandidateSol(data, candidateSolution.problem);
            ApplyInPlace(res);
            return res;
        }

        public void ApplyInPlace(NQueensCandidateSol candidateSolution)
        {
            var selectedRow = rand.Next(candidateSolution.data.Length);

            if (rand.NextBool())    //descreases the value
            {
                if (candidateSolution.data[selectedRow] > minVal)
                    candidateSolution.data[selectedRow]--;
                else candidateSolution.data[selectedRow]++;
            }
            else //increases value
            {
                if (candidateSolution.data[selectedRow] < maxVal - 1)
                    candidateSolution.data[selectedRow]++;
                else candidateSolution.data[selectedRow]--;
            }
        }

        public IEnumerable<NQueensCandidateSol> GenerateNeighbourhood(NQueensCandidateSol candidateSolution)
        {
            for (int i = 0; i < candidateSolution.data.Length; i++)
            {
                var res1 = new NQueensCandidateSol(candidateSolution.data.ToArray(), candidateSolution.problem);
                if (candidateSolution.data[i] > minVal)
                {
                    res1.data[i]--;
                    yield return res1;
                }

                var res2 = new NQueensCandidateSol(candidateSolution.data.ToArray(), candidateSolution.problem);
                if (candidateSolution.data[i] < maxVal - 1)
                {
                    res2.data[i]++;
                    yield return res2;
                }
            }
        }

        public ShiftValue(Random rand, int minVal, int maxVal)
        {
            this.rand = rand;
            this.minVal = minVal;
            this.maxVal = maxVal;
        }
    }
}
