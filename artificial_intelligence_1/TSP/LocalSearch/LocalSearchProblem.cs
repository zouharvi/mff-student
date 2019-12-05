using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalSearch
{
    public abstract class LocalSearchProblem
    {
    }

    public abstract class CandidateSolution<P> where P : LocalSearchProblem
    {
        public P problem;

        public abstract double Evaluate();

        public CandidateSolution(P problem)
        {
            this.problem = problem;
        }
    }

    public abstract class IntegerSequenceCandidateSolution<P> : CandidateSolution<P> where P : LocalSearchProblem
    {
        public int[] data;

        public IntegerSequenceCandidateSolution(int[] data, P problem)
            :base(problem)
        {
            this.data = data;
        }

        public abstract IntegerSequenceCandidateSolutionFactory<IntegerSequenceCandidateSolution<P>, P> GetFactory();
    }

    public interface IntegerSequenceCandidateSolutionFactory<out T, P> where T : IntegerSequenceCandidateSolution<P> where P : LocalSearchProblem
    {
        T Create(int[] data, P problem);
    }

}
