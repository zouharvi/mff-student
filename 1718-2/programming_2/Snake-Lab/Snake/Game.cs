using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class Game
    {
        private GameMap map;

        public Game(GameMap map)
        {
            this.map = map;
            this.map.game = this;
        }


        long milisFromStart = 0;
        public void Run()
        {
            Console.Clear();
            Console.SetWindowSize(map.width + 1, map.height + 2);
            map.Render();

            TimeDelta time = new TimeDelta();

            long nextMove = 250;

            while (true)
            {
                time.Update();

                nextMove -= time.GetDelta();
                milisFromStart += time.GetDelta();
                if (nextMove <= 0)
                {
                    if (map.worm.twistedCountdown > 0) 
                        map.worm.twistedCountdown--;
                    if (map.worm.twistedCountdown == 0)
                    {
                        map.worm.twisted = 1;
                        map.worm.twistedCountdown = -1;
                        map.worm.controller.ReverseInput();
                    }

                    map.Update();
                    map.Render();
                    RenderStats();
                    nextMove += 250;
                }
                if(map.worm.dead)
                {
                    GameOver();
                    break;
                }
            }

        }

        public void RenderStats()
        {
            Console.SetCursorPosition(0, map.height);
            Console.BackgroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("Length: " + map.worm.body.Count + " Time: "+milisFromStart/1000);
        }

        public void GameOver()
        {
            Debug.WriteLine("Game Over");
            Console.SetCursorPosition(2, 2);
            Console.BackgroundColor = ConsoleColor.DarkGray;
            Console.Write("Game Over");
        }

    }
}
