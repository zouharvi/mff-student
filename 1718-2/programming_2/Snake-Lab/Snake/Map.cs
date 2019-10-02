using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class Map
    {
        public char[,] map;
       
        public Map(int width, int height)
        {
        }

        public int GetWidth()
        {
            return map.GetLength(0);
        }

        public int GetHeight()
        {
            return map.GetLength(1);
        }
    }
}
