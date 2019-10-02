using Snake.Entity;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.MapRelated
{
    class GameMap
    {
        // TODO: missing constructor, local variables
        private Worm worm;
        private Map map;

        public void Render()
        {
            throw new NotImplementedException();
        }

        public Map GetMap()
        {
            return map;
        }

        public void PlaceAtRandomFree(IMapTile tile)
        {
            throw new NotImplementedException();
        }

        public Worm GetWorm()
        {
            return worm;
        }
    }
}
