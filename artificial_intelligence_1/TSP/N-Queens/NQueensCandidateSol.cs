using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LocalSearch;

namespace N_Queens
{
    class NQueensProblem : LocalSearchProblem
    {
        public int boardSize
        {
            get;
            private set;
        }

        public NQueensProblem(int boardSize)
        {
            this.boardSize = boardSize;
        }
    }

    class NQueensCandidateSol : IntegerSequenceCandidateSolution<NQueensProblem>
    {
        public NQueensCandidateSol(int[] data, NQueensProblem p)
            :base(data, p)
        {

        }

        public static bool IsSameDiagoval(int x1, int y1, int x2, int y2)
        {
            return x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2;
        }


        public override double Evaluate()
        {
            var errors = 0;

            for (int i = 0; i < data.Length - 1; i++)
            {
                for (int j = i + 1; j < data.Length; j++)
                {
                    if (data[j] == data[i]) //same column
                        errors++;
                    if (IsSameDiagoval(i, data[i], j, data[j]))
                        errors++;
                }
            }
            return errors;
        }

        public override IntegerSequenceCandidateSolutionFactory<IntegerSequenceCandidateSolution<NQueensProblem>, NQueensProblem> GetFactory()
        {
            return NQueensCandidateSol_Factory.GetInstance();
        }

    
    }

    class NQueensCandidateSol_Factory : IntegerSequenceCandidateSolutionFactory<NQueensCandidateSol, NQueensProblem>
    {
        public NQueensCandidateSol Create(int[] data, NQueensProblem problem)
        {
            return new NQueensCandidateSol(data, problem);
        }

        public static NQueensCandidateSol_Factory GetInstance()
        {
            return singleton.Value;
        }

        private static Lazy<NQueensCandidateSol_Factory> singleton = new Lazy<NQueensCandidateSol_Factory>(() => new NQueensCandidateSol_Factory());

        private NQueensCandidateSol_Factory()
        { }
    }
}
