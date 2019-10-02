using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class GameMap
    {
        public char[,] map;
        public Game game;
        public Worm worm;
        public int width, height;

        public GameMap(int width, int height)
        {
            this.width = width; this.height = height;
            map = new char[width,height];

            for (int x = 0; x < width; ++x)
                map[x, 0] = map[x, height-1] = '#';
            for (int y = 0; y < height; ++y)
                map[0, y] = map[width-1, y] = '#';

            worm = new Worm(width / 2, height / 2);
            worm.map = this;
            NewSpecTile('f');
            NewSpecTile('w');
            NewSpecTile('p');
        }

        public void Update()
        {
            if (worm.dead)
                return;
            worm.Update();
            int x = worm.GetHead().x;
            int y = worm.GetHead().y;
            switch (map[x, y])
            {
                case 'f':
                    worm.Grow(1);
                    map[x, y] = ' ';
                    NewSpecTile('f');
                    break;
                case 'p':
                    map[x, y] = ' ';
                    worm.Die();
                    break;
                case '#':
                    worm.Die();
                    break;
                case 'w':
                    worm.twistedCountdown = 8;
                    worm.twisted = -1;
                    worm.controller.ReverseInput();
                    NewSpecTile('w');
                    worm.Grow(4);
                    map[x, y] = ' ';
                    break;
            }
        }

        Random r = new Random();
        public void NewSpecTile(char tile)
        {
            map[r.Next(1, width - 1), r.Next(1, height - 1)] = tile;
        }

        public void Render()
        {
            Console.SetCursorPosition(0, 0);
            for (int y = 0; y < height; ++y)
            {
                for (int x = 0; x < width; ++x)
                {
                    switch(map[x,y]) {
                        case 'f':
                            Console.BackgroundColor = ConsoleColor.Magenta; break;
                        case 'w':
                            Console.BackgroundColor = ConsoleColor.Blue; break;
                        case '#':
                        case 'p':
                            Console.BackgroundColor = ConsoleColor.Red; break;
                        default:
                            Console.BackgroundColor = ConsoleColor.Black; break;
                    }
                    Console.Write(map[x,y]);
                }
                Console.WriteLine();
            }

            worm.Render();
        }

    }
}
