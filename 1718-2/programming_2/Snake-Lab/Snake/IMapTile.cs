using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    interface IMapTile
    {
        void Write();

        void Chewed(Worm worm);

    }
}
