using System;
using System.Collections.Generic;
using System.Text;
using System.Timers;

namespace SnakeReal
{
    class Game
    {
        Map map;
        Worm worm;

        public Game(int width, int height)
        {
            map = new Map(width, height);
            Console.WindowHeight = height + 1;
            Console.WindowWidth = width + 1;
            Console.CursorVisible = false;
            worm = new Worm();
            System.Timers.Timer aTimer = new System.Timers.Timer();
            aTimer.Elapsed += new ElapsedEventHandler(Update);
            aTimer.Interval = 200;
            aTimer.Enabled = true;
        }

        private void Update(object source, ElapsedEventArgs e)
        {
            map.Render();
            worm.Render();
        }
    }
}
