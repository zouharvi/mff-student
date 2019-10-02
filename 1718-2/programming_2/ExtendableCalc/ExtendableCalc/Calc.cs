using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class Calc
    {
        private ISource source;
        private IOutput output;
        private IOperator[] opers;

        public Calc(ISource source, IOutput output, IOperator[] opers)
        {
            this.source = source;
            this.output = output;
            this.opers = opers;
        }

        public void Process()
        {
            double result = 0;
            while(source.HasNext())
            {
                string line = source.GetLine();
                foreach(IOperator op in opers) // priortity?
                {
                    if(op.CanProcess(line))
                    {
                        result = op.Process(result, line);
                        break;
                    }
                }
                output.Output(result);
                // skip on invalid operation
            }
        }

    }
}
