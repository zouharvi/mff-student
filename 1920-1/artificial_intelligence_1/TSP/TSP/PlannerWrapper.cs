using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SASPlan;

namespace TSP
{
    public enum plannerType
    {
        AstarFF,
        AstarBlind,
        BeamStackSearchBlind,
        HillClimbingBlind,
        HillClimbingFF,
        MCTSFF,
        MCTSBlind
    }
    
    class PlannerWrapper : TSPSolver
    {
        private HeuristicSearchEngine engine;
        private plannerType t;

        public PlannerWrapper(plannerType t)
        {
            this.t = t;
        }

        private void createEngine(Domain dom)
        {
            switch (t)
            {
                case plannerType.AstarBlind:
                    engine = new AStarSearch(dom, new SASPlan.BlindHeuristic());
                    break;
                default:
                    engine = new AStarSearch(dom, new SASPlan.BlindHeuristic());
                    break;
                    /*
                case plannerType.AstarFF:
                    engine = new AStarSearch(dom, new FFHeuristic(dom));
                    break;
                case plannerType.BeamStackSearchBlind:
                    engine = new BeamStackSearch(dom, new BlindHeuristic());
                    break;
                case plannerType.HillClimbingBlind:
                    engine = new HillClimbingSearch(dom, new BlindHeuristic());
                    break;
                case plannerType.HillClimbingFF:
                    engine  =new HillClimbingSearch(dom, new FFHeuristic(dom));
                    break;
                case plannerType.MCTSBlind:
                    engine = new MCTSSolver(dom, new BlindHeuristic());
                    break;
                case plannerType.MCTSFF:
                    engine = new MCTSSolver(dom, new FFHeuristic(dom));
                    break;
                     */
            }
        }
        
        public TSPSolution solve(TSPInput input)
        {
            SASPlan.Domain dom = input.exportToPlanningDomain();
            createEngine(dom);
            engine.search();
            return convertPlan(engine.getSolution(), dom, input);
        }

        private TSPSolution convertPlan(List<int> plan, SASPlan.Domain domain, TSPInput input)
        {
            TSPSolution sol = new TSPSolution(input);
            int j = 0;
            foreach (var item in plan)
	        {
                SASPlan.Operator op = domain.operators[item];
                sol.setSuccessor(j, op.effects[0].effectValue);
                j = op.effects[0].effectValue;
	        }
            sol.setSuccessor(j, 0);
            return sol;
        }
    }

    class PlannerWrapperFactory : TSPSolverFactory<PlannerWrapper>
    {
        private plannerType type;
        #region TSPSolverFactory<PlannerWrapper> Members

        public PlannerWrapper create()
        {
            return new PlannerWrapper(plannerType.AstarBlind);
        }

        #endregion
        public PlannerWrapper create(plannerType t)
        {
            return new PlannerWrapper(t);
        }
    }
}
