using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class FixedSource : ISource
    {
        private string[] lines;
        private int index = 0;

        public FixedSource(string[] lines)
        {
            this.lines = lines;
        }

        public string GetLine()
        {
            return lines[index++];
        }

        public bool HasNext()
        {
            return index < lines.Length;
        }
    }
}
