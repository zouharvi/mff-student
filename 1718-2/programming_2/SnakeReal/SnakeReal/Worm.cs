using System;
using System.Collections.Generic;
using System.Text;

namespace SnakeReal
{
    class Worm
    {
        private ConsoleKey? GetKey()
        {
            if (Console.KeyAvailable)
            {
                return Console.ReadKey(true).Key;
            }
            return null;
        }

        public void Update()
        {
            GetKey();
        }

        public void Render()
        {

        }
    }
}
