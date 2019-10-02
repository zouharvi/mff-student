using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.Input
{
    class Direction
    {
        // Better than lazy singletons
        // TODO: pass correct constructor parameters
        public readonly static Direction
            LEFT  = new Direction(),
            RIGHT = new Direction(),
            UP = new Direction(),
            DOWN = new Direction();

        private int dx, dy;
        // TODO: Missing constructor

        public int dX()
        {
            throw new NotImplementedException();
        }

        public int dY()
        {
            throw new NotImplementedException();
        }
    }
}
