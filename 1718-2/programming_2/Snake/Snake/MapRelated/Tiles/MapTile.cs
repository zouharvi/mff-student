using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.MapRelated
{
    static class MapTile
    {
        // Better than lazy singletons
        // TODO: pass correct constructor parameters
        public static readonly IMapTile
            FOOD    = new MapTileEdible(),
            FOODx2  = new MapTileEdible(),
            FOODx10 = new MapTileEdible(),
            WINE    = new MapTileWine(),
            POISON  = new MapTileWormKiller();

        // TODO: ??? worm parts shouldn't be handled here
        public static readonly IMapTile
            WORM_BODY, WORM_HEAD;

    }
}
