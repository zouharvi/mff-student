using System;
namespace GameBookZouhar
{
    public class Option
    {
        public int dst;
        public string text;

        public Option() { }
        public Option(int dst, string text) 
        {
            this.dst = dst;
            this.text = text;
        }
    }
}
