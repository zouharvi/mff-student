using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class Minus: IOperator
    {
        public bool CanProcess(string line)
        {
            return line.Length > 0 && line[0] == '-' && double.TryParse(line.Substring(1), out double ignore);
        }

        public double Process(double left, string right)
        {
            double rightNumber = double.Parse(right.Substring(1));
            return left - rightNumber;
        }
    }
}
