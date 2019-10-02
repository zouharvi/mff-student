using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class Worm
    {
        public class Coord {
            public int x, y;
            public Coord(int x, int y) { this.x = x; this.y = y; }
            public Coord(Coord c) { this.x = c.x; this.y = c.y; }
        }

        public short twisted = 1;
        public short twistedCountdown = -1;
        public IPlayerController controller;
        public List<Coord> body;
        public GameMap map;
        private Coord shadow;
        public bool dead = false;

        public Worm(int x, int y)
        {
            body = new List<Coord>();
            body.Add(new Coord(x, y));
            controller = new KeyboardController();
        }

        public Coord GetHead()
        {
            return body.Last();
        }

        public void Render()
        {
            if (dead)
                return;
            Console.BackgroundColor = ConsoleColor.Green;
            foreach (Coord c in body)
            {
                Console.SetCursorPosition(c.x, c.y);
                Console.Write(' ');
            }
        }

        public void Grow(int calories)
        {
            for(int i = 0; i < calories; i++)
            {
                body.Insert(0, new Coord(shadow));
            }
        }

        public void Die()
        {
            map.game.GameOver();
            dead = true;
        }

        public void Update()
        {
            // tail
            Console.SetCursorPosition(body.First().x, body.First().y);
            Console.BackgroundColor = ConsoleColor.Black;
            Console.Write(' ');
            Direction dir = controller.GetInput();

            if(body.Count == 1)
            {
                shadow = new Coord(body.First());
                body.First().x += dir.x * twisted;
                body.First().y += dir.y * twisted;
            }
            else
            {
                Coord tail = body[0];
                body.RemoveAt(0);
                shadow = new Coord(tail);
                tail.x = body.Last().x + dir.x * twisted;
                tail.y = body.Last().y + dir.y * twisted;
                body.Add(tail);
            }
            Render();

            foreach (Coord c in body)
            {
                int same = 0;
                foreach (Coord d in body) {
                    if (d.x == c.x && d.y == c.y)
                        same++;
                }
                Debug.WriteLine(same);
                if (same > 1 && twisted == 1)
                    Die();
            }
        }

    }
}
