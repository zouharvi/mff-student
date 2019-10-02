using Snake.Entity;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.MapRelated
{
    class MapTileEdible : MapTileBase
    {
        private int calories;
        // TODO: Missing constructor

        public int GetCalories()
        {
            return calories;
        }

        public override void Chewed(Worm worm)
        {
            throw new NotImplementedException();
        }
    }
}
