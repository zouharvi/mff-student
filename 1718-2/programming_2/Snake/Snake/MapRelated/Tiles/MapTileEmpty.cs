using Snake.Entity;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.MapRelated
{
    class MapTileEmpty : MapTileBase
    {
        public override void Chewed(Worm worm)
        {
            throw new NotImplementedException();
        }
    }
}
