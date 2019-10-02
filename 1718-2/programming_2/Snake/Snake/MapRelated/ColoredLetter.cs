using System;

namespace Snake.MapRelated
{
    class ColoredLetter : ILetter
    {
        private char letter;
        private ConsoleColor foreground, background;
        // TODO: Missing constructor


        public void Write()
        {
            Console.ForegroundColor = foreground;
            Console.BackgroundColor = background;
            Console.Write(letter);
            // TODO: reset back to default?
        }
    }
}
