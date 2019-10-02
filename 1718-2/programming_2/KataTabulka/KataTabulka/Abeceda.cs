using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KataTabulka
{

    struct Souradnice
    {
        public int x;
        public int y;

        public Souradnice(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class vstupniAbeceda
    {
        //k ulozeni pouzijeme strukturu dictionary, ktera si o kazdem pismenku pamatuje jeho pozici
        public Dictionary<char, List<Souradnice>> slovnik = new Dictionary<char, List<Souradnice>>();

        public Souradnice velikostAbecedy;

        //vyrobi z prvnich trech radku "tabulku"
        public vstupniAbeceda(int x, int y, string vstup)
        {
            velikostAbecedy = new Souradnice(x, y);

            for (int i = 0; i < vstup.Length; i++)
            {
                List<Souradnice> seznam;
                try
                {
                    //pokud uz dane pismenko ve slovniku existuje, pridaji se k nemu nove souradnice
                    slovnik.TryGetValue((char)vstup[i], out seznam);
                    seznam.Add(new Souradnice(i % velikostAbecedy.x, i / velikostAbecedy.x));

                    /*
                    Console.WriteLine("Pridavam pismenko " + i + " " + (char)vstup[i] 
                        + " souradnice prvni " + i % velikostAbecedy.x + " souradnice druhe " +
                        i / velikostAbecedy.x);
                    */
                }
                catch (NullReferenceException)
                {
                    //pokud pismenko neexistuje, pak se do slovniku prida spolu se svoji pozici v tabulce
                    seznam = new List<Souradnice>();
                    seznam.Add(new Souradnice(i % velikostAbecedy.x, i / velikostAbecedy.x));
                    slovnik.Add((char)vstup[i], seznam);

                    /*
                    Console.WriteLine("Pridavam pismenko " + i + " " + (char)vstup[i]
                        + " souradnice prvni " + i % velikostAbecedy.x + " souradnice druhe " +
                        i / velikostAbecedy.x);
                    */
                }
            }
        }


        public int nejkratsiReseni(string s)
        {
            List<int> prevSolution = new List<int>();
            List<int> curSolution = new List<int>();
            List<Souradnice> prevChar;
            List<Souradnice> curChar;

            //zjistuji, jako znaky abecedy mam vlastne hledat - tedy ktere se vyskytuji v tabulce
            string nalezeno = "";
            for (int i = 0; i < s.Length; i++)
            {
                if (slovnik.ContainsKey(s[i]) == false) continue;
                nalezeno = nalezeno + s[i];
            }
            s = nalezeno;

            //zjistuji u prvniho pismenka, kde se vsude nachazi
            slovnik.TryGetValue(s[0], out prevChar);

            //zjistim dst od pocatku do vsech vyskytu prvniho pismenka v tabulce
            for (int i = 0; i < prevChar.Count; i++)
                prevSolution.Add(prevChar[i].x + prevChar[i].y + 1);
            Console.WriteLine(prevSolution.Min());

            //resim situaci pro vsechny dalsi pismenka
            for (int pocetZnaku = 1; pocetZnaku < s.Length; pocetZnaku++)
            {
                //zjistuji u daneho pismenka, kde se vsude nachazi
                slovnik.TryGetValue(s[pocetZnaku], out curChar);

                //pocitam dsti pro vsechny vyskyty pismenka v tabulce
                for (int j = 0; j < curChar.Count; j++)
                {
                    curSolution.Add(int.MaxValue);

                    //pro vsechny pripady zkousim ten, ve kterem je predchozi a soucasne pismenko nejmene vzdalene
                    for (int i = 0; i < prevChar.Count; i++)
                    {
                        int dst = Math.Abs(prevChar[i].x - curChar[j].x) + Math.Abs(prevChar[i].y - curChar[j].y);

                        if (dst + prevSolution[i] < curSolution[j])
                        {
                            curSolution[j] = dst + prevSolution[i] + 1;
                        }
                    }
                }
                prevChar = curChar;
                prevSolution = curSolution;
                curSolution = new List<int>();
            }
            return prevSolution.Min();
        }
    }
}