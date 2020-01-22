using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalSearch
{
    public interface LSNullaryOperator<T, P> where T : CandidateSolution<P> where P : LocalSearchProblem
    {
        T Apply(P problem);
    }

    public interface LSUnaryOperator<T, P> where T : CandidateSolution<P> where P : LocalSearchProblem
    {
        T Apply(T candidateSolution);

        void ApplyInPlace(T candidateSolution);

        IEnumerable<T> GenerateNeighbourhood(T candidateSolution);
    }

    public interface LSBinaryOperator<T, P> where T : CandidateSolution<P> where P : LocalSearchProblem
    {
        T Apply(T candidateSolution1, T candidateSolution2);

    }

    /// <summary>
    /// Selects two indices A, B and swaps values on those indices.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="P"></typeparam>
    /// <typeparam name="F"></typeparam>
    public class SimpleSwapOperator<T, P, F> : LSUnaryOperator<T, P>
        where T : IntegerSequenceCandidateSolution<P>
        where P : LocalSearchProblem
        where F : IntegerSequenceCandidateSolutionFactory<T, P>
    {
        Random r;
        F factory;

        protected (int, int) selectSwapCoordinates(T candidate)
        {
            var firstCoord = r.Next(candidate.data.Length);
            var secondCoord = r.Next(candidate.data.Length);
            while (secondCoord == firstCoord)
                secondCoord = r.Next(candidate.data.Length);
            return (firstCoord, secondCoord);
        }

        protected void swap(int[] array, int coord1, int coord2)
        {
            int temp = array[coord1];
            array[coord1] = array[coord2];
            array[coord2] = temp;
        }

        public SimpleSwapOperator(F factory, Random r)
        {
            this.r = r;
            this.factory = factory;
        }

        public T Apply(T CandidateSolution)
        {
            var coordinates = selectSwapCoordinates(CandidateSolution);
            var newData = CandidateSolution.data.ToArray();
            swap(newData, coordinates.Item1, coordinates.Item2);
            return factory.Create(newData, CandidateSolution.problem);
        }

        public void ApplyInPlace(T CandidateSolution)
        {
            var coordinates = selectSwapCoordinates(CandidateSolution);
            swap(CandidateSolution.data, coordinates.Item1, coordinates.Item2);
        }

        public IEnumerable<T> GenerateNeighbourhood(T CandidateSolution)
        {
            for (int i = 0; i < CandidateSolution.data.Length; i++)
            {
                for (int j = i + 1; j < CandidateSolution.data.Length; j++)
                {
                    var newData = CandidateSolution.data.ToArray();
                    swap(newData, i, j);
                    yield return factory.Create(newData, CandidateSolution.problem);
                }
            }
        }
    }

    /// <summary>
    /// Selects three indices A, B, C and rotates values on those indices, I.e data[C] => data[A]; data[B] => data[C]; data[A] => data[B]
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="P"></typeparam>
    /// <typeparam name="F"></typeparam>
    public class Rotate3Values<T, P, F> : LSUnaryOperator<T, P>
        where T : IntegerSequenceCandidateSolution<P>
        where P : LocalSearchProblem
        where F : IntegerSequenceCandidateSolutionFactory<T, P>
    {
        Random r;
        F factory;

        protected (int, int, int) selectRotationCoordinates(T candidate)
        {
            var firstCoord = r.Next(candidate.data.Length);
            var secondCoord = r.Next(candidate.data.Length);
            while (secondCoord == firstCoord)
                secondCoord = r.Next(candidate.data.Length);

            var thirdCoord = r.Next(candidate.data.Length);
            while (thirdCoord == firstCoord || secondCoord == thirdCoord)
                thirdCoord = r.Next(candidate.data.Length);
            return (firstCoord, secondCoord, thirdCoord);
        }

        protected void rotate(int[] array, int coord1, int coord2, int coord3)
        {
            int temp = array[coord1];
            array[coord1] = array[coord2];
            array[coord2] = array[coord3];
            array[coord3] = temp;
        }

        public Rotate3Values(F factory, Random r)
        {
            this.r = r;
            this.factory = factory;
        }

        public T Apply(T CandidateSolution)
        {
            var coordinates = selectRotationCoordinates(CandidateSolution);
            var newData = CandidateSolution.data.ToArray();
            rotate(newData, coordinates.Item1, coordinates.Item2, coordinates.Item3);
            return factory.Create(newData, CandidateSolution.problem);
        }

        public void ApplyInPlace(T CandidateSolution)
        {
            var coordinates = selectRotationCoordinates(CandidateSolution);
            rotate(CandidateSolution.data, coordinates.Item1, coordinates.Item2, coordinates.Item3);
        }

        public IEnumerable<T> GenerateNeighbourhood(T CandidateSolution)
        {
            for (int i = 0; i < CandidateSolution.data.Length; i++)
            {
                for (int j = i + 1; j < CandidateSolution.data.Length; j++)
                {
                    for (int k = 0; k < j + 1; k++)
                    {
                        var newData = CandidateSolution.data.ToArray();
                        rotate(newData, i, j, k);
                        yield return factory.Create(newData, CandidateSolution.problem);
                    }
                }
            }
        }
    }

}
