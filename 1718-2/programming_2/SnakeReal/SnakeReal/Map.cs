using System;
using System.Collections.Generic;
using System.Text;

namespace SnakeReal
{
    class Map
    {
        public char[,] map;
        int width, height;
        public Map(int width, int height)
        {
            this.width = width;
            this.height = height;
            map = new char[width, height];

            for (int i = 0; i < height; i++)
                    map[0, i] = map[width-1,i] = '#';
            for (int j = 0; j < width; j++)
                    map[j, 0] = map[j, height-1] = '#';
            for (int i = 1; i < height-1; i++)
                for (int j = 1; j < width-1; j++)
                    map[j, i] = ' ';
        }

        public void Render()
        {
            string[] buffer = new string[height];
            Console.ForegroundColor = ConsoleColor.White;
            Console.SetCursorPosition(0, 0);
            for(int i = 0; i < height; i++)
            {
                buffer[i] = "";
                for(int j = 0; j < width; j++)
                {
                    buffer[i] += map[j, i];
                }
                Console.WriteLine(buffer[i]+ " ");
            }
            Console.ForegroundColor = ConsoleColor.Black;
        }
    }
}
