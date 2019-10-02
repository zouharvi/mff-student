using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class ConsoleSource : ISource
    {
        private string line;

        public string GetLine()
        {
            return line;
        }


        public bool HasNext()
        {
            line = Console.ReadLine();
            return line != "exit";
        }
    }
}
