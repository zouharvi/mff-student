using System;

namespace GameBookZouhar
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Book book = BookLoader.Load("LoneWolf-FlightFromTheDark.txt");
            BookPlayer player = new BookPlayer(book);

            if (false)
                player.Play();
            else {
                // DISCLAIMER: the graph is not connected, for only options in the format of "* turn to number." are interpreted.
                Console.Write("Enter prefered ending, shortest path will be found: ");
                while (true)
                {
                    int userChoice = int.Parse(Console.ReadLine());
                    bool res = player.Play(userChoice - 1);
                    if (!res)
                        Console.Write("Invalid choice, path doesn't exist, or option not found. Try again: ");
                    else
                        break;
                }
            }
        }
    }
}
