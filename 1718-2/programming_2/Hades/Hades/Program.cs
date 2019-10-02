using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Hades
{
    public struct Char
    {
        public char c;
        public bool free;
        public Char(char c, bool free = false)
        {
            this.c = c;
            this.free = free;
        }
        
        public Char Copy()
        {
            return new Char(c, free);
        }
    }

    public class Genome
    {
        public Char[] raw = new Char[64];
        public long inverseFitness;

        private void RecalcFitness()
        {
            inverseFitness = FitnessEvaluator.Eval(Utils.CharArrToString(raw));
        }

        // random constructor
        public Genome()
        {
            // TODO:
            RecalcFitness();
        }

        // explicit constructor
        public Genome(Char[] raw)
        {
            this.raw = raw;
            RecalcFitness();
        }

        // one off mutation
        public Genome(Genome genome)
        {
            throw new NotImplementedException();
            // TODO:
            for (int i = 0; i < 8 * 8; i++) // placeholder
                raw[i] = genome.raw[i].Copy();
            RecalcFitness();
        }


        private static Random r = new Random();
        // multiple parents mutation
       
        public Genome(List<Genome> genomes)
        {
            Genome chosen = genomes[(int) (1-Randomness.RandomLinear(10))*genomes.Count];
            raw = Utils.CloneCharArr(chosen.raw);
            do
            {
                Swap(r.Next(8 * 8), r.Next(8 * 8));
            } while (r.NextDouble() > 0.85);
            do
            {
                int a = r.Next(8 * 8);
                if (raw[a].free)
                    ReplaceRandom(a);
            } while (r.NextDouble() > 0.75);

            // TODO: shift columns / row?
            RecalcFitness();
        }

        private void ReplaceRandom(int a)
        {
            raw[a] = new Char(Program.UNIQ[r.Next(Program.UNIQ.Length)], true);
        }

        private void Swap(int a, int b)
        {
            Char tmp = raw[a];
            raw[a] = raw[b];
            raw[b] = tmp;
        }

        public void Display()
        {
            Console.WriteLine(Utils.CharArrToString(raw) + " : " + inverseFitness);
        }
    }

    // evolution manager
    public class Darwin
    {
        public List<Genome> population = new List<Genome>();
        public int popSize;
        public Darwin(int popSize = 2)
        {
            this.popSize = popSize;
            population.Add(new Genome(Utils.LastFreeImp("LorelvfPwpm sa hQluticdbPegnuroiFdNaqentOS .m suHTEMCVIjWRLUyADJ")));
            population.Add(new Genome(Utils.LastFreeImp("LorelvfPwpm sa hQluticdbPegnuroiFdNaqentOS .m suHTEMCVIjWRLUyADJ")));
            population = population.OrderBy(i => i.inverseFitness).ToList();
        }

        // simulates a generation + returns the best genome
        public Genome PrepareNextPop()
        {
            List<Genome> newPop = new List<Genome>();
            newPop.Add(population.First()); // best one carries over
            while (newPop.Count != popSize)
                newPop.Add(new Genome(population));

            // TODO: check sort is correct order
            population = newPop.OrderBy(i => i.inverseFitness).ToList();
            return population.First();
        }
    }

    public class Utils
    {
        public static string Unique(string a)
        {
            HashSet<char> set = new HashSet<char>();
            foreach (char c in a) set.Add(c);
            string s = "";
            foreach (char c in set) s += c;
            return s;
        }

        public static Char[] LastFree(string a)
        {
            Char[] r = new Char[8 * 8];
            for (int i = 0; i < 8 * 8; i++)
            {
                r[i] = new Char(a[i], i > 45); // TODO: check +-1 err
            }
            return r;
        }

        public static Char[] LastFreeImp(string a)
        {
            HashSet<char> set = new HashSet<char>();
            Char[] r = new Char[8 * 8];
            for (int i = 0; i < 8 * 8; i++)
            {
                r[i] = new Char(a[i], set.Contains(a[i]));
                set.Add(a[i]);
            }
            return r;
        }

        public static string CharArrToString(Char[] a)
        {
            string s = "";
            foreach (Char c in a)
                s += c.c;
            return s;
        }

        public static Char[] CloneCharArr(Char[] a)
        {
            Char[] b = new Char[a.Length];
            for (int i = 0; i < 8 * 8; i++) // placeholder
                b[i] = a[i].Copy();
            return b;
        }
    }


    public class Program
    {
        public static string INPUT = "Lorem ipsum dolor sit amet consectetuer nunc augue at turpis cursus. Vestibulum eleifend dui mauris tincidunt ligula volutpat purus felis adipiscing lacinia. Sagittis orci Lorem lobortis hac tincidunt dis Pellentesque vel et Proin. Magnis tellus sit malesuada id elit hendrerit nec malesuada cursus Nunc. Ipsum justo arcu tincidunt nunc Mauris scelerisque elit Aliquam dictum Vivamus. Semper dui magnis at cursus tellus Vivamus at ligula sem malesuada. Ut interdum nibh Vivamus faucibus elit vitae lorem libero commodo augue. Curabitur mauris eget et orci nec auctor convallis ipsum fringilla condimentum. Vestibulum tellus non lacus et Curabitur aliquet ante convallis facilisi metus. Consectetuer sodales magna ut mollis condimentum sit nunc sed sed laoreet. Commodo malesuada libero Integer laoreet pretium Integer elit sociis Sed felis. Velit ac et leo ac nunc pretium pede pellentesque Vestibulum purus. Vestibulum cursus leo mi Nunc iaculis id Pellentesque Curabitur enim semper. Risus tempor pulvinar laoreet nunc justo tellus Mauris tincidunt pretium magna. Et at ac Phasellus purus urna faucibus metus turpis pede vel. Laoreet faucibus wisi elit Vestibulum justo nibh montes sapien tempus dictum. Sagittis et interdum consectetuer ut ac ipsum libero nulla diam dis. Sed Proin leo tempor consectetuer Nulla Nam justo fames natoque lorem. Vel vestibulum lacinia a et pellentesque Vivamus laoreet et ut vitae. Scelerisque dolor Curabitur id et consequat Cras convallis laoreet Phasellus fames. Vestibulum a scelerisque vel ultrices Nam massa ac Curabitur mauris tempus. Pellentesque id In et tempor Nullam justo Duis et sagittis commodo. Et faucibus a a Lorem amet sem in ac Ut Curabitur. Montes consectetuer accumsan vel justo venenatis nibh dui arcu semper convallis. Dui non tellus ut ligula Vestibulum pede at Nunc urna tellus. Nulla id tincidunt sem eu Nullam nisl Mauris et Vestibulum risus. Cursus ligula consequat enim nec pulvinar a Vestibulum pretium rhoncus nascetur. Arcu sem consequat ut ac dui rutrum Nunc metus lacinia nunc. Quisque condimentum sed est quis nunc Maecenas In nibh metus faucibus. Cursus velit Nam Cum felis at Nam suscipit aliquet wisi non. Et enim pretium tristique vitae ac pellentesque penatibus wisi orci elit. Tincidunt neque parturient felis dolor metus orci sem adipiscing adipiscing semper. Nisl et a turpis non Curabitur hendrerit molestie Vivamus interdum Nulla. Felis dolor adipiscing ut vel feugiat Pellentesque Quisque magnis quam mattis. Orci Nulla risus convallis et platea In enim convallis tortor lobortis. Quisque leo Curabitur faucibus sagittis sem enim semper tempor quis dis. Nam elit eros Sed pede malesuada Nulla sociis congue Mauris vitae. Sem rhoncus justo Cras nulla Aenean ligula augue eros tempus commodo. Pellentesque urna dui elit nec consectetuer ipsum Aliquam quis ut ac. Justo Phasellus sit tellus sociis Nam Maecenas feugiat magna pretium accumsan. Rhoncus vel urna gravida ipsum turpis tristique vel eget semper Morbi. Aenean ac lacinia pretium Integer velit risus non Donec Vivamus interdum. Vitae id Morbi risus pellentesque auctor et Curabitur orci Integer Curabitur. Ornare enim tortor velit odio sagittis pede Curabitur sapien consectetuer vitae. In in egestas Cum iaculis magnis In felis risus neque magna. Nulla nulla Fusce pellentesque nulla ut et Vestibulum nibh turpis magna. Morbi Nulla Vestibulum justo lacus tempus Curabitur malesuada velit condimentum tristique. Commodo pulvinar justo mauris eget et est sapien nec ut condimentum. Et turpis neque pede eget dolor molestie dis Nam ut faucibus. Interdum nibh gravida Duis Vivamus lacus dis Phasellus sit Donec eget. Metus et lacus tellus Curabitur elit leo pharetra nunc nascetur velit. Enim porttitor condimentum enim interdum Curabitur Curabitur et id nunc pede. Interdum fermentum Curabitur parturient congue risus urna ullamcorper quis ipsum ac. Neque congue elit Nullam dui semper rutrum quis Donec malesuada gravida. A lacus accumsan sapien Aliquam eros nibh dui quis sociis laoreet. Tellus Nam leo metus Lorem ipsum semper consequat Vestibulum pretium ante. Nisl Nam eu ipsum natoque orci fames id Vestibulum justo congue. Aliquam sagittis semper quis cursus nibh nibh justo eu diam sem. Aliquam pretium non sit Curabitur lorem Donec montes ut nisl tortor. Dis id consequat nibh nibh Curabitur quis Nulla semper ac vitae. Cursus vel pretium gravida dignissim orci ut tempus dolor ac dolor. Lacinia adipiscing urna tempus consectetuer adipiscing Vivamus adipiscing Aenean ligula Nam. Urna dui Vestibulum at orci Phasellus enim nec sodales ut congue. Ligula adipiscing facilisis Morbi dolor eros ligula sed ac egestas ut. Nisl Duis aliquet sem convallis malesuada dictumst nibh lacus diam nibh. Non est suscipit commodo Phasellus velit Nam a tempus interdum metus. Justo Aenean vel et wisi Proin leo urna nibh euismod Quisque. Tellus wisi auctor augue quam ut sagittis id feugiat convallis Phasellus. Nulla Nam et Morbi aliquam id pede id quis tincidunt Duis. Netus nulla turpis pellentesque mauris Phasellus Nunc Nulla libero molestie felis. Dolor nunc dictum sem consequat rutrum feugiat felis wisi quis sagittis. A dictum Sed volutpat id Curabitur dolor Phasellus tempor orci dictum. Consequat Praesent enim laoreet Mauris id Pellentesque nec magnis urna ridiculus. Amet hendrerit orci Sed ipsum ante vitae cursus eros pretium habitant. Mauris id congue Aenean urna et purus eu gravida elit scelerisque. Et accumsan Pellentesque sem gravida congue adipiscing augue pulvinar Quisque nulla. Sem consequat leo id leo vel augue at semper auctor natoque. Curabitur eu risus Aenean vitae In elit egestas tristique Integer lacus. Nisl lorem ac Aenean Lorem Nulla lorem magna a dui et. Vitae vel lacinia dui Sed elit nibh eu wisi orci euismod. Pellentesque rutrum convallis eros libero Vivamus sed malesuada natoque dolor dapibus. Arcu consequat fermentum quam vel convallis laoreet consectetuer nonummy vestibulum Aliquam. Enim mollis pretium id porta orci fringilla ligula eros ipsum congue. Nibh augue tincidunt est ante Vestibulum elit Nam urna enim vel. Vestibulum metus sagittis urna mauris condimentum consequat id pellentesque quam Sed. Et tortor enim tincidunt lacus at nibh lacus sapien sapien hendrerit. Tristique et semper enim elit ligula In Curabitur ac justo parturient. Vitae ut at parturient Phasellus velit Sed pellentesque nibh convallis enim. Cursus Curabitur ac sit quis vel tincidunt libero In ligula gravida. Ac Nam ipsum iaculis consequat sit egestas In eu auctor tempor. Vestibulum nibh at condimentum quis risus est Quisque facilisis ut Suspendisse. Auctor enim orci Phasellus suscipit interdum Aenean at tempus id at. A Sed penatibus risus habitant urna purus Vivamus Quisque mauris dictumst. Ut cursus hac Maecenas molestie auctor nunc semper vitae dictum mauris. Dolor magna ut risus nibh non Sed eget elit pellentesque ut. Ligula vitae odio id semper lacus convallis Nullam pede ut non. Tempor Nam Praesent est enim auctor Vestibulum Integer mauris consequat elit. Pretium neque volutpat In lacus et velit congue eros Nunc dis. Id a interdum Curabitur mollis pellentesque nibh risus ac quis tincidunt. Non tincidunt facilisi mi tellus condimentum lacinia ut tellus pretium habitant. Ac ut purus consequat urna pretium lorem Vestibulum Vestibulum urna ante. Vel tincidunt Curabitur vel et non faucibus vitae tristique Vestibulum congue. Tempus convallis ipsum In Nulla nulla Morbi nunc adipiscing justo condimentum. Sed ac wisi Nunc Vivamus ac Vestibulum Curabitur id Vestibulum Nulla. Donec Nam et hendrerit Aliquam pretium eget quis laoreet dui consequat. Commodo Nam hac tellus adipiscing Duis sagittis adipiscing sit at venenatis. Ridiculus enim consectetuer Vestibulum non ipsum gravida consectetuer orci Nulla velit. Malesuada nunc gravida mauris quis tincidunt sapien id wisi pellentesque lacus. Condimentum habitant Nam et adipiscing pellentesque faucibus congue vel Vestibulum In. Lorem mauris accumsan pede ullamcorper tellus laoreet montes orci ac sapien. Tempor aliquet eros malesuada hac sed lorem Cum ornare elit at. Non consequat nibh malesuada facilisi mi convallis ipsum Aenean pretium enim. Nullam Aenean enim hendrerit congue nunc molestie Curabitur morbi natoque volutpat. Accumsan Aliquam a Sed et commodo Integer purus augue et nec. Interdum et netus laoreet cursus nulla vel dignissim dolor rutrum et. Auctor dolor dui quis neque Nunc congue tincidunt parturient est laoreet. Ligula Curabitur sem dui condimentum sagittis tincidunt non risus Ut et. Vivamus ridiculus nibh Pellentesque libero consectetuer Lorem id aliquet at dui. Tincidunt vitae dolor in pede lorem vitae interdum elit In nibh. Mauris consectetuer velit tortor vitae quis nisl a et auctor ut. A ipsum nibh sapien sagittis Curabitur tincidunt Quisque eget egestas nunc. Commodo nec netus et dui dolor suscipit tempus lacus libero morbi. Ligula morbi tristique tristique consequat wisi faucibus ut pretium velit at. Sed orci consequat nec Sed Vestibulum non adipiscing nec rhoncus wisi. Volutpat magna tortor sodales est interdum Phasellus metus et tempor elit. Justo porttitor dictumst vel nibh ac Curabitur massa vitae adipiscing Sed. At sagittis pretium sed elit tempor semper neque Integer sociis accumsan. Justo accumsan penatibus aliquet et dui malesuada Curabitur Phasellus ridiculus nec. Odio urna mauris Suspendisse Curabitur cursus scelerisque hendrerit lacus et a. Vel Sed consequat venenatis Nulla at ipsum et Integer justo leo. Vestibulum dapibus urna interdum nunc Vivamus adipiscing felis at Sed senectus. Vivamus urna euismod pretium et velit pellentesque Vivamus quis arcu volutpat. Laoreet In Duis In dui fringilla dui hendrerit urna accumsan nulla. Magnis habitant Sed est nibh Phasellus massa eros tellus justo amet. Elit dictum consequat risus et lacus ut nunc Phasellus ante Morbi. Et Morbi semper et tortor vitae et Sed In fermentum risus. Congue porta condimentum pretium sollicitudin vitae ut Quisque Curabitur nibh sit. Euismod at congue nisl cursus Curabitur nec justo nunc nibh semper. Sit Praesent purus iaculis quis tellus odio velit Pellentesque Sed quis. Augue Aenean Integer sit sed pede tempus risus Curabitur eget egestas. Aenean convallis magna quis hac tellus vitae fringilla Nunc ac scelerisque. Vivamus consequat diam Pellentesque tristique laoreet Pellentesque Aenean mattis nisl auctor. Convallis Phasellus tincidunt consequat enim vitae tellus auctor Suspendisse Vivamus rutrum. Condimentum diam orci interdum egestas Quisque eget wisi tempor condimentum tempus. Ipsum eget amet sociis parturient velit parturient Phasellus Suspendisse quis non. Condimentum ut adipiscing sed Nunc mauris Quisque ante Praesent Praesent justo. Sagittis Vestibulum sagittis Curabitur purus elit dolor quis nibh Curabitur pede. Id velit congue commodo a Donec vitae sodales et metus Vivamus. Magna tortor pellentesque id leo est elit Quisque Nulla Nam ullamcorper. Egestas at Nulla nulla id justo libero laoreet penatibus hac urna. Curabitur wisi Curabitur Duis massa Vestibulum platea sed wisi sed sed. Vel neque interdum laoreet id adipiscing euismod urna faucibus pellentesque Aenean. Tellus dictum quis ut Fusce sit vitae a justo eros Aliquam. Eget condimentum sapien vel vel ut sed dis justo id wisi. Libero nonummy et platea leo sem non Phasellus mattis odio tellus. Feugiat tempus Nullam Aenean pretium vel mattis id ullamcorper volutpat at. Maecenas auctor justo vitae Sed suscipit euismod sodales fames ridiculus Vestibulum. Mollis lobortis congue est pretium mattis id id nulla molestie Nam. Fringilla vitae non elit sit convallis In Nulla montes consequat semper. Pede pellentesque Curabitur pede ut non mauris Integer tellus natoque amet. Egestas et Donec mattis hendrerit eu mi porta ac lacus mauris. Justo mattis ipsum eros libero Nam ac eget nunc dolor tincidunt. Cras felis eget risus consectetuer vitae Nulla sem dignissim nonummy Proin. Convallis laoreet urna turpis elit condimentum dignissim et vel cursus wisi. Feugiat sit in tempus felis mauris sociis gravida eget pharetra tellus. Wisi sem Maecenas egestas platea Maecenas nibh sodales felis augue parturient. Sed tempus magnis ac nec Morbi ipsum facilisis Aenean eu ac. Enim sem congue libero ac Donec elit justo ante Phasellus Sed. Amet pede malesuada Sed laoreet malesuada Phasellus id vitae id in. Turpis consectetuer Nullam mattis id mi Nam et et consequat pellentesque. Aliquam Vestibulum neque elit sit enim tincidunt platea magna quis augue. Nam tortor est dis sit vel fermentum Lorem leo Curabitur mollis. Turpis sed Vestibulum pellentesque consectetuer Sed elit convallis sapien tortor ac. Nisl Curabitur tempor convallis orci Phasellus gravida consectetuer vitae pretium vitae. Amet ipsum eu est ut vitae leo leo Vestibulum neque diam. Quis faucibus nunc tellus eleifend cursus vitae Sed eget Nulla laoreet. Vitae nonummy Curabitur enim ligula Nam massa semper magna orci Lorem. Tempor montes magna Curabitur Curabitur convallis cursus amet auctor cursus quis. Et odio id molestie tincidunt semper ut cursus fermentum accumsan In. Phasellus pede Integer et metus sit id ipsum elit nec tempus. Ac nibh netus dapibus Sed habitant Sed pellentesque dignissim mus eu. Odio sem nunc Maecenas elit dolor quis Praesent Nam fringilla mauris. Malesuada fringilla ante adipiscing ipsum enim semper convallis velit Quisque amet. Convallis felis in pretium pellentesque nibh et velit vel vitae cursus. Tellus habitant sodales nibh metus libero et tincidunt non fringilla wisi. Quisque gravida elit nunc lacus augue Aenean montes risus ut est. Scelerisque consequat urna sodales a auctor amet tellus hendrerit orci netus. Augue et nibh nibh justo pellentesque mauris ut Nulla sagittis dictum. Nec orci congue molestie turpis metus eget lorem ut Phasellus sapien. Amet dui turpis dictumst adipiscing Sed semper cursus ut laoreet mauris. Curabitur Pellentesque eu eget semper convallis vitae dui porttitor congue elit. Vestibulum eget rutrum nonummy leo sem semper convallis id Curabitur porttitor. Sagittis Vestibulum auctor nunc auctor arcu volutpat risus magna mollis tristique. Urna lacus Aliquam hendrerit leo ridiculus quis est augue nibh Nam. Quisque interdum ipsum Maecenas cursus leo congue Pellentesque tempus lacus iaculis. Hendrerit Quisque libero felis aliquet at mauris ac Sed Pellentesque aliquam. Nulla et pharetra sed ipsum orci metus nunc dictumst elit quam. Laoreet leo Curabitur nunc tincidunt Maecenas lacus lobortis et et ut. Malesuada eu feugiat quis Curabitur facilisis sapien congue risus et id. Orci nibh nunc ut ipsum In congue dignissim feugiat enim In. Id condimentum consequat sem enim lacus in laoreet nunc nibh at. Curabitur dolor quis nibh elit Duis nibh vitae metus vitae ornare. Penatibus quis tempor Cum Morbi scelerisque dui pellentesque vitae amet velit. Nulla scelerisque pretium nulla dapibus elit lorem eget nibh massa gravida. Sed id justo ac at Ut ac ante vel feugiat consequat. Phasellus pede ultrices condimentum augue enim turpis Morbi id et ligula. Auctor elit convallis est a Phasellus hendrerit augue sapien laoreet condimentum. Cursus elit vel et sem nibh pretium tincidunt nisl lacinia et. Nullam ac natoque vitae congue Phasellus porttitor faucibus dui faucibus cursus. Tortor mauris pretium mauris quis ipsum quis eget In ac ac. Fermentum facilisi id eu est Praesent ipsum elit dignissim Curabitur amet. Nam tincidunt nascetur lacus vitae felis vitae nibh orci velit rutrum. Vivamus turpis Lorem metus eget consectetuer ipsum ipsum urna sit tincidunt. Nec et libero ullamcorper consequat a Nullam tincidunt Nulla et Quisque. Nulla convallis Nunc ante parturient sagittis ultrices Nulla Vivamus et Nam. Semper dui elit id sagittis ante eget nonummy ac molestie vel. Nulla odio gravida adipiscing sem Integer Ut vel a fermentum Ut. Semper urna sit tristique quis Mauris ac neque sit cursus ut. Quisque wisi Aenean vel ac tortor vitae mollis Donec malesuada nec. Libero Nam tellus nibh urna dui magnis netus pulvinar ut pretium. Cursus ut id orci sapien condimentum Donec ac mus interdum sit. Pellentesque aliquet est Phasellus id ipsum porttitor fames laoreet Lorem consectetuer. Donec risus et elit convallis Vestibulum nunc Praesent elit Curabitur nulla. Pretium quam lacinia auctor in sollicitudin et ac tristique rutrum Curabitur. Nibh Vestibulum justo tortor interdum Morbi justo quis quis malesuada Nunc. Et vel Vestibulum dolor nisl accumsan dui Vestibulum ut nibh vitae. Aliquam nibh rutrum ridiculus libero consequat risus justo Curabitur pretium nibh. Non lorem tincidunt Cras at Donec ipsum ac condimentum magna nec. Tellus Pellentesque est pellentesque orci ultrices enim a faucibus elit Maecenas. Sem ut Quisque Pellentesque tempus pharetra ut Cras pretium lorem nibh. Fusce Sed Vivamus eget tincidunt id suscipit et augue Aenean fames. Tortor ac ornare wisi Nam Curabitur egestas gravida consequat Pellentesque auctor. Cursus laoreet eget id Nam Nulla urna dui elit augue massa. Convallis eu vel interdum Quisque ligula Maecenas risus Nam eget ut. Mollis sit tellus aliquet pretium Quisque quis vel congue Maecenas auctor. Tristique sociis Vestibulum vel libero faucibus nec ipsum Vestibulum aliquam sem. Urna lacinia odio Nam ante natoque id ipsum consequat lorem Pellentesque. Nulla condimentum justo velit tempus Maecenas In consectetuer ipsum ligula pulvinar. Enim faucibus Vestibulum Cras pellentesque consequat ut elit lacinia dapibus et. Cursus massa magna pretium sollicitudin dui odio dictumst penatibus congue Sed. Adipiscing dui mi Proin ultrices In sed semper laoreet laoreet quis. Iaculis morbi nec a est eu Praesent nulla Vestibulum sociis et. Sed velit dui nunc Sed pretium vitae Ut tincidunt feugiat sapien. Elit semper vel vitae mauris magna tincidunt at auctor massa iaculis. Nam urna quam lacinia egestas nibh justo Donec wisi et vitae. Est adipiscing nunc ipsum porttitor wisi nec aliquam Nulla sed elit. Ullamcorper consequat vel enim In quis laoreet sit semper porttitor augue. Elit elit augue Curabitur vitae ac Nam Nullam fringilla risus Pellentesque. Tempus morbi aliquam nibh urna ut justo Nam quis et Donec. Velit at lacinia purus Ut mattis orci cursus at Vestibulum urna. Interdum elit pede cursus at elit amet enim nec sollicitudin quis. Lorem felis lobortis orci dictumst nunc sit nibh platea Nunc sapien. Orci tempus ut ornare Proin tincidunt arcu nunc neque Proin ridiculus. Sed nunc vitae malesuada Phasellus interdum urna platea vel turpis mi. Est at Nam id urna Integer sapien at at Curabitur cursus. Sed urna ac nunc sed quis sed urna id id est. Dignissim eget eget sapien dictum ac adipiscing suscipit Morbi augue Sed. Elit consequat ut venenatis condimentum mauris mi pharetra facilisi pede convallis. Penatibus consectetuer Sed leo lacinia Integer morbi molestie semper magnis Nam. Ornare nibh id et at tellus consectetuer vitae nibh cursus at. Laoreet nibh Phasellus Sed enim condimentum dictumst et iaculis eros Maecenas. Quis Quisque pretium neque fringilla tincidunt sem turpis vitae lobortis pharetra. In Cum Cum tristique dolor tellus risus nibh ipsum lorem Nulla. Velit elit metus quis dui vitae accumsan leo lobortis tincidunt ac. Risus id ut pellentesque nascetur Nam lacus volutpat feugiat iaculis lorem. Dictumst semper a ante leo Curabitur eget tellus gravida pellentesque Suspendisse. In mus porttitor consectetuer tortor eleifend velit et enim in Proin. Et felis sit quis id tempor ipsum non id penatibus nibh. Consequat Ut interdum et a tristique amet Curabitur Phasellus ut wisi. Condimentum egestas convallis Ut Nam Duis a id laoreet pellentesque ut. Ligula eu pede wisi et Fusce neque massa Nam tempus Nam. Laoreet ante nibh egestas dapibus nisl odio et venenatis augue non. Tincidunt a nunc pellentesque leo facilisis scelerisque pretium cursus Praesent Maecenas. Eget Phasellus interdum et sit orci pulvinar cursus condimentum dui sociis. Natoque Sed porttitor mi consectetuer id nibh ipsum Aenean ac Vestibulum. Semper adipiscing penatibus pellentesque nibh adipiscing consequat Curabitur eget quam Integer. Tempus In sagittis eu Quisque Nam lorem adipiscing Lorem nunc dictum. Malesuada pretium gravida netus Nulla ipsum Vestibulum lacinia nonummy turpis sagittis. Metus Praesent urna augue consectetuer vel et Pellentesque Nulla morbi pretium. Consequat velit elit justo sagittis lorem orci feugiat quis velit morbi. Dolor porta ligula non lobortis Quisque interdum odio Vivamus nulla pellentesque. Semper Nam augue arcu neque venenatis condimentum velit et Vestibulum porta. Ac felis massa feugiat Vestibulum nibh adipiscing Ut convallis interdum lacinia. Eros wisi Lorem libero Ut Aenean odio platea adipiscing urna accumsan. Faucibus feugiat nibh tellus elit Vestibulum laoreet et In consequat id. Dolor magna consequat pretium felis Cum ultrices metus a nunc ante. Interdum ac Quisque tellus convallis non pretium Vestibulum aliquam et vitae. Et ut Aenean augue molestie at elit diam odio sed Nam. Fringilla odio tincidunt odio non id Quisque Cum et justo Nulla. Mi Duis gravida Nam elit In quis Integer ut elit tellus. Aenean nunc urna Quisque vitae tincidunt nec nibh Integer eget sem. Ligula orci Morbi pellentesque Nulla purus consequat Vestibulum consectetuer pede quis. Nullam fermentum commodo sapien volutpat Sed tempus id platea Lorem semper. Sociis et semper leo tortor pede Aenean convallis vitae metus sapien. Lobortis Curabitur mauris Nullam elit felis euismod Donec In Phasellus habitant. Ornare mollis Phasellus tincidunt tortor Pellentesque In Morbi habitant ut molestie. In a nulla dolor euismod id condimentum interdum dapibus egestas quis. Consequat dui pretium nec id vitae ullamcorper dignissim Nunc nibh turpis. Senectus a Curabitur amet ipsum tempus Curabitur vel velit Nam tincidunt. Ut tellus dui accumsan tellus vitae volutpat In dolor pretium leo. Urna ut Phasellus orci Aenean lacus orci lobortis enim adipiscing lobortis. Magna amet volutpat ipsum vitae orci eget vel porttitor eros laoreet. Ut fringilla id tristique tincidunt libero Sed risus porttitor mi Nam. Pretium consequat et neque senectus ac Curabitur eget Mauris ante Quisque. Cras semper tristique et tincidunt eros nibh elit Nam In justo. Enim dis habitant nunc quis Sed ac Fusce Lorem Aenean ipsum. Turpis Vestibulum Curabitur tincidunt dignissim tincidunt et pulvinar pretium et id. Sapien sagittis Sed semper Vestibulum tellus enim lacinia pulvinar eu vitae. Congue auctor accumsan vitae fringilla sem malesuada a amet Curabitur at. Tortor nunc velit dapibus velit Curabitur nunc lorem urna dui tempus. Mus congue auctor est dui tortor neque Maecenas eget montes urna. Sed pellentesque dui nec Nam eget auctor Sed id laoreet quis. Adipiscing dui tincidunt Phasellus condimentum auctor et pretium enim est Curabitur. Ligula sem tincidunt adipiscing consectetuer ac pede Aenean vitae vel semper. Fringilla eu non tortor nunc Nam augue ipsum mattis tortor parturient. Justo sed Quisque Aenean libero Sed sed vel condimentum porttitor pede. Risus malesuada Donec metus Pellentesque eget Fusce malesuada lacinia turpis amet. Libero Aenean Curabitur ut Phasellus montes suscipit malesuada dictumst condimentum arcu. Nulla pretium lorem ante ut pellentesque Sed facilisi Phasellus id malesuada. Nulla id elit Nam Aliquam sapien Vivamus magnis nec condimentum laoreet. Felis Pellentesque Maecenas justo convallis Suspendisse mauris tellus orci Nam Ut. Fames sem.";
        public static string UNIQ = "Lorem ipsudltacng.VbfvShPqMNIjAUCREwDQTFOJyWH"; // Utils.Unique(INPUT)

        public static void Main(string[] args)
        {
            FitnessEvaluator.Eval("ABCDEFGHIJKLMNOPQRSTUVWXYZ.     abcdefghijklmnopqrstuvwxyz      ");
            long total = 0;
            long  nextGens;
            Darwin d = new Darwin();
            while (true)
            {

                Console.Write("No. gens: ");
                if (!long.TryParse(Console.ReadLine(), out nextGens) || nextGens < 1)
                    break;
                for (long i = 0; i < nextGens; i++)
                {
                    total++;
                    Console.Write(total.ToString("D8") + ": ");
                    d.PrepareNextPop().Display();
                }
            }
        }
    }
}