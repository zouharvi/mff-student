using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class KeyboardController : IPlayerController
    {
        public bool HasKey()
        {
            return Console.KeyAvailable;
        }

        public void ReverseInput()
        {
            lastDirection.x *= -1;
            lastDirection.y *= -1;
        }

        public ConsoleKey? GetKey()
        {
            if(Console.KeyAvailable)
            {
                return Console.ReadKey(true).Key;
            }
            return null;
        }

        public void Update()
        {
            // throw new NotImplementedException();
        }

        private Direction lastDirection = new Direction(0, -1);
        public Direction GetInput()
        {
            ConsoleKey? key = GetKey();
            if (key != null)
            {
                switch(key.Value)
                {
                    case ConsoleKey.W:
                        lastDirection = new Direction(0, -1); break;
                    case ConsoleKey.S:
                        lastDirection = new Direction(0,  1); break;
                    case ConsoleKey.A:
                        lastDirection = new Direction(-1, 0); break;
                    case ConsoleKey.D:
                        lastDirection = new Direction( 1, 0); break;
                }
            }
            return lastDirection;
        }

        public bool IsEndGame()
        {
            throw new NotImplementedException();
        }
    }
}
