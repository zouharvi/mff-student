using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace GameBookZouhar
{
    class BookPlayer
    {
        private Book book;
        private Page currPage;
        private Stack<int> scenario;

        public BookPlayer(Book book)
        {
            this.book = book;
        }


        /// <summary>
        /// Play towards a specific ending. Returns false if such ending is not achievable.
        /// </summary>
        /// <param name="ending"></param>
        public bool Play(int ending)
        {
            if (ending < 0 || ending > book.pages.Count)
                return false;

            bool found = false;

            if (ending == 0) // IDK humans are weird
                found = true;
            else
            {
                foreach (Page page in book.pages)
                    page.previous = null;

                // Doing DFS here would be cleaner, as Page class could be made simpler
                Queue<Page> leftPages = new Queue<Page>();
                leftPages.Enqueue(book.pages[0]);
                while(leftPages.Count != 0)
                {
                    Page openPage = leftPages.Dequeue();
                    foreach(Option o in openPage.options)
                    {
                        if(book.pages[o.dst].previous == null)
                        {
                            book.pages[o.dst].previous = openPage;
                            leftPages.Enqueue(book.pages[o.dst]);
                            if(o.dst == ending)
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (!found)
            {
                return false; // ending path not found
            }

            scenario = new Stack<int>();
            Page curr = book.pages[ending].previous;
            Page next = book.pages[ending];
            while (curr != null)
            {
                for(int i = 0; i < curr.options.Count; i++)
                {
                    if (curr.options[i].dst == next.pageNum)
                        scenario.Push(i + 1);
                }
                next = curr;
                curr = curr.previous;
            }
            Drive(false);
            return true;
        }

        /// <summary>
        /// Play according to human player.
        /// </summary>
        /// <returns></returns>
        public void Play()
        {
            Drive(true);
        }


        private void Drive(bool human)
        {
            int currPageIndex = 1;
            while (true)
            {
                currPage = book.pages[currPageIndex - 1];
                // display current page
                Console.Clear();
                Console.WriteLine("Page " + (currPageIndex).ToString() + "/" + book.pages.Count);
                Console.WriteLine(currPage.text);

                // show options
                if (currPage.options.Count == 0) // no options left
                {
                    Console.ReadLine();
                    SayGoodbye();
                    return;
                }
                else
                {
                    for (int i = 0; i < currPage.options.Count; i++)
                        Console.WriteLine((i + 1).ToString() + ") " + currPage.options[i].text);
                    Console.WriteLine("0) Exit the game.");
                }

                int userChoice = human ? GetHumanInput() : GetRobotInput();

                if (userChoice == 0)
                {
                    SayGoodbye();
                    return;
                }
                else // move on
                    currPageIndex = currPage.options[userChoice - 1].dst + 1;
            }
        }

        private int GetHumanInput()
        {
            bool validInput;
            int userChoice = -1;
            do
            {
                string userChoiceRaw = Console.ReadLine();
                if (!Regex.IsMatch(userChoiceRaw, @"\d"))
                    validInput = false;
                else
                {
                    userChoice = int.Parse(userChoiceRaw);
                    validInput = userChoice >= 0 && userChoice <= currPage.options.Count;
                }
                if (!validInput)
                    Console.WriteLine("Invalid input");
            } while (!validInput);
            return userChoice;
        }

        private int GetRobotInput()
        {
            if(scenario.Count == 0)
            {
                Console.WriteLine("\nReached the prefered ending. You're welcome.");
                Console.ReadLine();
                return 0;
            } else
            {
                int nextPage = scenario.Pop();
                Console.WriteLine("\nI'll choose {0}), press ENTER to continue.", nextPage);
                Console.ReadLine();
                return nextPage;
            }
        }

        static void SayGoodbye()
        {
            Console.Clear();
            Console.WriteLine("Thank you for playing our game. Bye!");
            Console.ReadLine();
        }
    }
}
