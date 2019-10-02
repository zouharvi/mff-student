using System;
using System.Collections.Generic;
namespace GameBookZouhar
{
    public class Page
    {
        public int pageNum = 0;
        public string text;
        public List<Option> options;
        public Page previous = null; // used only in BFS
        public Page(int pageNum) {
            options = new List<Option>();
            this.pageNum = pageNum;
        }
    }
}
