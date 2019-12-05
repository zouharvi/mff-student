using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SASPlan.MCTS
{
    abstract class SimulationPolicy
    {
        /// <summary>
        /// Runs a simulation given the initial part of the plan. It also adds actions in the simulation to the plan.
        /// </summary>
        /// <param name="p"></param>
        /// <param name="maxSimulationLength"></param>
        /// <returns></returns>
        public abstract List<int> runSimulation(Plan p, int maxSimulationLength);

        /// <summary>
        /// A state in which the simulation ended. Changes after each call of runSimulation method
        /// </summary>
        public State finalState;

        public virtual void updateStats(Plan simulation)
        {
            // default: no action. only overide if the object needs it
        }
    }

    class SearchEngineSimulationPolicy : SimulationPolicy
    {
        protected HeuristicSearchEngine engine;
        protected Heuristic h;
        protected Domain d;

        public SearchEngineSimulationPolicy(HeuristicSearchEngine engine, Heuristic h, Domain d)
        {
            this.engine = engine;
            this.h = h;
            this.d = d;
        }

        public override List<int> runSimulation(Plan p, int maxSimulationLength)
        {
            this.d.initialState = p.currentState;
            engine.search(true);
            var sol = engine.getSolution();
            foreach (var item in sol)
            {
                p.addAction(d.operators[item]);
            }
            return sol;
        }

        public SearchEngineSimulationPolicy()
        {

        }
    }

    class RandomSimulationPolicy : SimulationPolicy
    {
        public int maxLength = int.MaxValue;
        private List<int> simulation;
        private Domain dom;

        public RandomSimulationPolicy(Domain dom, int maxLength)
        {
            this.simulation = new List<int>();
            this.dom = dom;
            this.maxLength = maxLength;
        }

        public override List<int> runSimulation(Plan p, int maxSimulationLength)
        {
            simulation.Clear();
            State state = p.currentState;
            for (int i = 0; i < maxLength; i++)
            {
                if (dom.isGoalState(state))
                    break;
                var successors = dom.getSuccessors(state);
                if (successors.Count == 0)
                    break;
                Operator op = successors.Keys.ElementAt(Program.r.Next(successors.Keys.Count));
                simulation.Add(op.orderIndex);
                p.addAction(op);
                state = Operator.apply(op, state);
            }
            this.finalState = state;
            return simulation;
        }
    }

    class CompositeSimulationPolicy : SimulationPolicy
    {
        private static Random r = new Random();
        List<SimulationPolicy> policies;
        public override List<int> runSimulation(Plan p, int maxSimulationLength)
        {
            SimulationPolicy pol = policies[r.Next(policies.Count)];
            return pol.runSimulation(p, maxSimulationLength);
        }

        public CompositeSimulationPolicy()
        {
            this.policies = new List<SimulationPolicy>();
        }

        public void addPolicy(SimulationPolicy p)
        {
            policies.Add(p);
        }
    }

    /// <summary>
    /// For each operator it holds all operators that followed it in some plan and for each such response
    /// it holds the average quality of the plan achived. I.e. average value of plans where these two operators were used together
    /// (the second immediatelly following the first one)
    /// 
    /// It then selects operator based on these statistics maximizing performance (by some kind of randomized fitness-based selector)
    /// </summary>
    class BestResponse : SimulationPolicy
    {
        public void updateStats(Plan simulation)
        {

        }

        public override List<int> runSimulation(Plan p, int maxSimulationLength)
        {
            throw new NotImplementedException();
        }
    }

    /// <summary>
    /// Accumulates global statistics about the operators used. 
    /// For each operator it holds information about average value of the plans, where this operator has been used.
    /// Uses these statistics to select operators either by tournament selection or roulette.
    /// </summary>
    class BestPerformancePolicy : SimulationPolicy
    {
        public int maxLenght = int.MaxValue;
        private List<int> simulation;
        private Domain dom;
        private double[] simResultSum;
        private int[] simulationsCount;
        List<double> cummulatedValues;
        List<int> operatorIndices;
        double tournamentSizeProportional = 0.7;

        public BestPerformancePolicy(Domain dom)
        {
            this.dom = dom;
            this.cummulatedValues = new List<double>();
            this.operatorIndices = new List<int>();
            this.simResultSum = new double[dom.operators.Count];
            this.simulation = new List<int>();
            this.simulationsCount = new int[dom.operators.Count];
        }

        public override void updateStats(Plan simulation)
        {
            foreach (var item in simulation.actions)
            {
                simResultSum[item] = simResultSum[item] + simulation.eval();
                simulationsCount[item] = simulationsCount[item] + 1;
            }
        }

        /// <summary>
        /// Vyuziva turnajovou selekci
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public override List<int> runSimulation(Plan p, int maxSimulationLength)
        {
            this.maxLenght = maxSimulationLength;
            simulation.Clear();
            State state = p.currentState;
            for (int i = 0; i < maxLenght; i++)
            {
                if (dom.isGoalState(state))
                    break;
                var successors = dom.getSuccessors(state);
                if (successors.Count <= 0)
                    return simulation;
                int opIndex = -1;
                double opPerformance = double.MaxValue;
                while (opIndex == -1)
                    foreach (var item in successors.Keys)
                    {
                        if (Program.r.NextDouble() <= tournamentSizeProportional)
                        {
                            if (opPerformance > getOperatorPerformance(item.orderIndex))
                            {
                                opPerformance = getOperatorPerformance(item.orderIndex);
                                opIndex = item.orderIndex;
                            }
                        }
                    }

                simulation.Add(opIndex);
                p.addAction(dom.operators[opIndex]);
                state = Operator.apply(dom.operators[opIndex], state);
            }
            return simulation;
        }

        private double getOperatorPerformance(int opIndex)
        {
            return simResultSum[opIndex] / (simulationsCount[opIndex] + 1);
        }

        /// <summary>
        /// Metoda nepracuje spravne - uprednostnuje akce ktere vedou na vyssi vysledek simulace (ma to byt naopak)
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public List<int> runSimulationRoulette(State s)
        {
            simulation.Clear();
            State state = s;
            for (int i = 0; i < maxLenght; i++)
            {
                if (dom.isGoalState(state))
                    break;
                var successors = dom.getSuccessors(state);
                cummulatedValues.Clear();
                operatorIndices.Clear();
                double totalSum = 0;
                foreach (var item in successors.Keys)
                {
                    totalSum += simResultSum[item.orderIndex] / (simulationsCount[item.orderIndex] + 1);
                    cummulatedValues.Add(totalSum);
                    operatorIndices.Add(item.orderIndex);
                }
                double rand = Program.r.NextDouble() * totalSum;
                int opIndex = 0;
                for (int j = 0; j < cummulatedValues.Count; j++)
                {
                    if (rand <= cummulatedValues[j])
                    {
                        opIndex = operatorIndices[j];
                        break;
                    }
                }

                simulation.Add(opIndex);
                state = Operator.apply(dom.operators[opIndex], state);
            }
            return simulation;
        }
    }

    class HeuristicGreedySearch : SearchEngineSimulationPolicy
    {
        public HeuristicGreedySearch(Heuristic h, Domain d, int maxSimulationLength)
        {
            this.engine = new HillClimbingSearch(d, h, maxSimulationLength);
            this.d = d;
            this.h = h;
        }
    }

    class BeamSearchPolicy : SearchEngineSimulationPolicy
    {
        public BeamSearchPolicy(Heuristic h, Domain d, int maxWidth)
        {
            BeamStackSearch b = new BeamStackSearch(d, h);
            b.maxWidth = maxWidth;
            this.engine = b;
            this.d = d;
            this.h = h;
        }
    }

    class AStarSimulationPolicy : SearchEngineSimulationPolicy
    {
        public AStarSimulationPolicy(Heuristic h, Domain d, int maxSimulationLength)
        {
            this.engine = new AStarSearch(d, h);
            this.d = d;
            this.h = h;
        }
        public AStarSimulationPolicy()
        {

        }
    }

    class F_LimitedAStarSimulationPolicy : AStarSimulationPolicy
    {
        public F_LimitedAStarSimulationPolicy(Heuristic h, Domain d, int maxSimulationLength, int fLimit)
        {
            f_limitedAStarSearch s = new f_limitedAStarSearch(d, h);
            s.setLimit(fLimit);
            this.engine = s;
            this.d = d;
            this.h = h;
        }
    }
}
