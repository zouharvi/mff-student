using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace smake
{
    class DocAll
    {
        public Dictionary<string, int> Data { get; private set; }
        public int DocsNum { get; private set; }

        public DocAll(HashSet<string> sws)
        {
            var data = new Dictionary<string, int>();
            int docsNum = 0;

            foreach (var entry in Directory.GetFiles(Options.G_ABSTR_DIR, Options.G_ABSTR_PATTERN))
            {
                docsNum += 1;
                var text = File.ReadAllText(entry).ToLower();
                var textWords = Regex.Split(text, @"[^\p{L}]");
                var cset = new HashSet<string>(textWords.Where(x => !sws.Contains(x)));

                foreach (var word in cset)
                {
                    data.Add1OrIncrement(word);
                }
            }

            this.Data = data;
            this.DocsNum = docsNum;
        }

        public double TermIdf(string term)
        {
            var total = this.Data.GetValueOrDefault(term, 1);
            return Math.Log(this.DocsNum, 10.0) / total;
        }

    }
}
