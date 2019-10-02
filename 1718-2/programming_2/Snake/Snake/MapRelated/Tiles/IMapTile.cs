using Snake.Entity;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.MapRelated
{
    interface IMapTile
    {
        ILetter GetLetter();
        void Chewed(Worm worm);
    }
}
