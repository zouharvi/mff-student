using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class Program
    {
        static void Main(string[] args)
        {
            Calc calc = new Calc(
            //    new FixedSource(new string[] { "+1", "+2", "+3" } ),
                new ConsoleSource(),
                new ConsoleOutput(),
                new IOperator[] {  new Minus(), new Plus(), new Immediate() }                
            );

            calc.Process();
        }
    }
}
