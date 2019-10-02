using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Width: ");
            int width = int.Parse(Console.ReadLine());
            Console.Write("Height: ");
            int height = int.Parse(Console.ReadLine());
            GameMap map = new GameMap(width, height);
            Console.CursorVisible = false;
            Game game = new Game(map);

            game.Run();
            Console.ReadLine();
        }
    }
}