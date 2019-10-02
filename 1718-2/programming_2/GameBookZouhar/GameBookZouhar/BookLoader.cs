using System.Text.RegularExpressions;

namespace GameBookZouhar
{
    class BookLoader
    {
        public static Book Load(string fileName)
        {
            string[] lines = System.IO.File.ReadAllLines(fileName);
            Book book = new Book();
            Page currPage = new Page(-1); // unused, TODO: surpress uninitialized var warning

            Regex optionLineRe = new Regex(@"^.*turn to \d+.$", RegexOptions.IgnoreCase);
            Regex optionNumberRe = new Regex(@"(\d+)(?!.*\d)", RegexOptions.IgnoreCase);
            Regex numberLineRe = new Regex(@"^\d+$", RegexOptions.IgnoreCase);

            foreach (string line in lines)
            {
                if (numberLineRe.Match(line).Success) // new page
                {
                    currPage = new Page(book.pages.Count);
                    book.pages.Add(currPage);
                }
                else if (optionLineRe.Match(line).Success) // new option
                {
                    int dst = int.Parse(optionNumberRe.Match(line).Value) - 1;
                    Option option = new Option(dst, line);
                    currPage.options.Add(option);
                }
                else // just more text
                    currPage.text += line + System.Environment.NewLine;
            }
            return book;
        }
    }
}
