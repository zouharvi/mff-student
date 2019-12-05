using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalSearch
{
    public class HillClimbingSolver<T, P> where T : CandidateSolution<P> where P : LocalSearchProblem
    {
        private Random r;
        private T current;
        private bool stop;
        private int steps, stepsWithoutImprovement;
        private double currentBestVal;

        private LSNullaryOperator<T, P> initializationOperator;
        private LSUnaryOperator<T, P> modificationOperator;

        public T Solve(P input, Action<T, int> onImprovementCallback = null)
        {
            reset();
            current = initialize(input);
            
            while (!stop)
            {
                steps++;
                goOneStep();
                var currentVal = current.Evaluate();
                if (currentVal < currentBestVal)
                {
                    onImprovementCallback?.Invoke(current, steps);
                    currentBestVal = currentVal;
                }
            }
            return current;
        }

        /// <summary>
        /// Tato metoda by mela vylepsit reseni ulozene v promenne "current". Kvalitu reseni je mozne ziskat volanim "current.Evaluate()". 
        /// Je mozne napr. prohodit nektere prvky v permutaci pomoci volani "modificationOperator.Apply(current)"
        /// Pokud uz soucasne reseni nelze vylepsit, metoda by mela nastavit promenou "stop" na "true", coz zpusobi, ze prohledavani skonci.
        /// Pro vylepseni (nebo obecne zmenu) reseni pouzijte nekterou variantu Hill-Climbingu.
        /// </summary>
        protected virtual void goOneStep()
        {
            Console.WriteLine("Beginning step");
            const int ATTEMPTS = 100;
            const int DEPTH = 5;
            for (int i = 0; i < ATTEMPTS; i++) {
                var next = current;
                for (int j = 0; j < DEPTH; j++) {
                    next = modificationOperator.Apply(next);
                    if(current.Evaluate() > next.Evaluate()) {
                        current = next;
                        return;
                    }
                }

            }
            stop = true;
        }

        private T initialize(P input)
        {
            return initializationOperator.Apply(input);
        }

        private void reset()
        {
            stop = false;
            steps = 0;
            stepsWithoutImprovement = 0;
            currentBestVal = double.MaxValue;
        }

        public HillClimbingSolver(Random r, LSNullaryOperator<T, P> initializationOperator, LSUnaryOperator<T, P> modificationOperator)
        {
            this.r = r;
            this.initializationOperator = initializationOperator;
            this.modificationOperator = modificationOperator;
        }

    }
}
