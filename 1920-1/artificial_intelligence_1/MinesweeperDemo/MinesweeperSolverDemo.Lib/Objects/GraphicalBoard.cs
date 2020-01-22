using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinesweeperSolverDemo.Lib.Objects
{
    public class GraphicalBoard : GameBoard
    {
        private Visualizer vis;

        public override void Display()
        {
            vis.visualize(Panels);
        }

        public override void DisplayFinal()
        {
            vis.visualize(Panels);
        }

        public GraphicalBoard(int width, int height, int mines, Visualizer vis) : 
            base(width, height, mines)
        {
            this.vis = vis;
            vis.setBoard(this);
        }
    }
}
