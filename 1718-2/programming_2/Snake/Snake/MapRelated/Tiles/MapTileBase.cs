using Snake.Entity;
using Snake.MapRelated;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake
{
    abstract class MapTileBase : IMapTile
    {
        private ILetter letter;

        public virtual void Chewed(Worm worm)
        {
            throw new NotImplementedException();
        }

        // TODO: Missing constructor


        public virtual ILetter GetLetter()
        {
            return letter;
        }
    }
}
