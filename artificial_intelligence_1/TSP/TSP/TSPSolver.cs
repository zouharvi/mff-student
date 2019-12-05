using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    interface TSPSolver
    {
        TSPSolution solve(TSPInput input);
    }

    interface TSPSolverFactory<S>
        where S : TSPSolver
    {
        S create();
    }
}
