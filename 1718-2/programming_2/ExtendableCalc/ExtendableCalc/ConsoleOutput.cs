using System;

namespace ExtendableCalc
{
    class ConsoleOutput : IOutput
    {
        public void Output(double s)
        {
            Console.WriteLine("-----------------");
            Console.WriteLine(s);
            Console.WriteLine("-----------------");
        }
    }
}