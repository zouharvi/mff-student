using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StateSpaceSearch
{
	class Vertex {
		public byte s1;
		public byte s2;
		public byte s3;
		public int p1;
		public int p2;
		public int p3;
		public sbyte z;
		public sbyte y;
		public sbyte x;
		public Vertex(byte s1, byte s2, byte s3, int p1, int p2, int p3, sbyte z, sbyte y, sbyte x) {
			this.s1 = s1;
			this.s2 = s2;
			this.s3 = s3;
			this.p1 = p1;
			this.p2 = p2;
			this.p3 = p3;
			this.z = z;
			this.y = y;
			this.x = x;
		}
	}

	class Edge {
		public byte s1;
		public byte s2;
		public int p1;
		public int p2;
		public sbyte z;
		public sbyte y;
		public sbyte x;
		public Edge(byte s1, byte s2, int p1, int p2, sbyte z, sbyte y, sbyte x) {
			this.s1 = s1;
			this.s2 = s2;
			this.p1 = p1;
			this.p2 = p2;
			this.z = z;
			this.y = y;
			this.x = x;
		}
	}

	class Cube : State
	{
		//   0
		// 1 2 3 4
		//   5
		private const int NIC = 6;
		private static int rozmer1 = 0; // HACK toto nema byt static									
		public int rozmer;
		public byte[][] strany;

		private static List<Vertex> vertices = new List<Vertex>();
		private static List<Edge> edges = new List<Edge>();
		// indexovano barvami
		private static int[,,] spravnaPolohaVrcholu;
		private static int[,,] spravnaOrientaceVrcholu;
		private static int[,] spravnaPolohaHrany;
		private static int[,] spravnaOrientaceHrany;
		private static void spoj(Vertex vertex)
		{
			int cisloRohu = vertices.Count;
			spravnaPolohaVrcholu[vertex.s1, vertex.s2, vertex.s3] = cisloRohu;
			spravnaPolohaVrcholu[vertex.s2, vertex.s3, vertex.s1] = cisloRohu;
			spravnaPolohaVrcholu[vertex.s3, vertex.s1, vertex.s2] = cisloRohu;

			spravnaOrientaceVrcholu[vertex.s1, vertex.s2, vertex.s3] = 0;
			spravnaOrientaceVrcholu[vertex.s2, vertex.s3, vertex.s1] = 1;
			spravnaOrientaceVrcholu[vertex.s3, vertex.s1, vertex.s2] = 2;
			vertices.Add(vertex);
		}
		private static void spoj(Edge edge)
		{
			int edgeNumber = edges.Count;
			spravnaPolohaHrany[edge.s1, edge.s2] = edgeNumber;
			spravnaPolohaHrany[edge.s2, edge.s1] = edgeNumber;
			spravnaOrientaceHrany[edge.s1, edge.s2] = 0;
			spravnaOrientaceHrany[edge.s2, edge.s1] = 1;
			edges.Add(edge);
		}
		private static void generujRohy(int rozmer)
		{
			int levy_horni = 0;
			int levy_dolni = (rozmer - 1) * rozmer;
			int pravy_horni = rozmer - 1;
			int pravy_dolni = rozmer * rozmer - 1;
			spoj(new Vertex(0, 1, 2, levy_dolni, pravy_horni, levy_horni, 0, 0, 0));
			spoj(new Vertex(0, 2, 3, pravy_dolni, pravy_horni, levy_horni, 0, 0, 1));
			spoj(new Vertex(0, 3, 4, pravy_horni, pravy_horni, levy_horni, 0, 1, 1));
			spoj(new Vertex(0, 4, 1, levy_horni, pravy_horni, levy_horni, 0, 1, 0));

			spoj(new Vertex(2, 1, 5, levy_dolni, pravy_dolni, levy_horni, 1, 0, 0));
			// 3, 2, 5 musi byt posledni, protoze to je ten fixovany roh, ktery se nezapocitava do uniqueVertexNumber
			spoj(new Vertex(4, 3, 5, levy_dolni, pravy_dolni, pravy_dolni, 1, 1, 1));
			spoj(new Vertex(1, 4, 5, levy_dolni, pravy_dolni, levy_dolni, 1, 1, 0));

			spoj(new Vertex(3, 2, 5, levy_dolni, pravy_dolni, pravy_horni, 1, 0, 1));
		}

		private static void generujHrany()
		{
			int horni = 1;
			int leva = 3;
			int prava = 5;
			int dolni = 7;
			spoj(new Edge(0, 4, horni, horni, -1, 1, 0));
			spoj(new Edge(0, 2, dolni, horni, -1, -1, 0));
			spoj(new Edge(1, 0, horni, leva, -1, 0, -1));
			spoj(new Edge(1, 5, dolni, leva, 1, 0, -1));

			spoj(new Edge(2, 1, leva, prava, 0, -1, -1));
			spoj(new Edge(2, 3, prava, leva, 0, -1, 1));
			spoj(new Edge(3, 0, horni, prava, -1, 0, 1));
			spoj(new Edge(3, 5, dolni, prava, 1, 0, 1));

			spoj(new Edge(4, 3, leva, prava, 0, 1, 1));
			spoj(new Edge(4, 1, prava, leva, 0, 1, -1));
			spoj(new Edge(5, 2, horni, dolni, 1, -1, 0));
			spoj(new Edge(5, 4, dolni, dolni, 1, 1, 0));
		}

		const int numberOfVertices = 8;
		const int numberOfOrientations = 2187 / 3; // 3^7/3
		const int numberOfEdges = 12;

		static Cube()
		{
			//generujRohy();
			spravnaPolohaVrcholu = new int[6 + 1, 6 + 1, 6 + 1];
			spravnaOrientaceVrcholu = new int[6 + 1, 6 + 1, 6 + 1];
			spravnaPolohaHrany = new int[6 + 1, 6 + 1];
			spravnaOrientaceHrany = new int[6 + 1, 6 + 1];
			for (int x = 0; x < 7; x++)
				for (int y = 0; y < 7; y++)
				{
					spravnaPolohaHrany[x, y] = -1;
					spravnaOrientaceHrany[x, y] = -1;
					for (int z = 0; z < 7; z++)
					{
						spravnaPolohaVrcholu[x, y, z] = -1;
						spravnaOrientaceVrcholu[x, y, z] = -1;
					}
				}
		}

		public Cube(int rozmer)
		{
			if (Cube.rozmer1 == 0) { generujRohy(rozmer); generujHrany(); }
			if ((Cube.rozmer1 != 0) && (Cube.rozmer1 != rozmer)) throw new NotImplementedException();
			Cube.rozmer1 = rozmer;
			this.rozmer = rozmer;
			strany = new byte[6][];
			for (byte i = 0; i < 6; i++)
			{
				strany[i] = new byte[rozmer * rozmer];
				for (int j = 0; j < strany[i].Length; j++)
					strany[i][j] = i;
			}
		}
		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();
			for (int y = 0; y < rozmer; y++)
			{
				for (int x = 0; x < rozmer + 1; x++) sb.Append("  ");
				for (int x = 0; x < rozmer; x++)
				{
					sb.Append(strany[0][y * rozmer + x]);
					sb.Append(" ");
				}
				sb.Append(Environment.NewLine);
			}
			sb.Append(Environment.NewLine);
			for (int y = 0; y < rozmer; y++)
			{
				for (int strana = 1; strana <= 4; strana++)
				{
					for (int x = 0; x < rozmer; x++)
					{
						sb.Append(strany[strana][y * rozmer + x]);
						sb.Append(" ");
					}
					sb.Append("  ");
				}
				sb.Append(Environment.NewLine);
			}
			sb.Append(Environment.NewLine);
			for (int y = 0; y < rozmer; y++)
			{
				for (int x = 0; x < rozmer + 1; x++) sb.Append("  ");
				for (int x = 0; x < rozmer; x++)
				{
					sb.Append(strany[5][y * rozmer + x]);
					sb.Append(" ");
				}
				sb.Append(Environment.NewLine);
			}
			//sb.Append(popis);
			sb.Append(Environment.NewLine);
			return sb.ToString();
		}
		private byte[] select(int strana, int start, int diff)
		{
			byte[] result = new byte[rozmer];
			for (int i = 0; i < rozmer; i++)
			{
				result[i] = strany[strana][(start + i * diff + rozmer * rozmer) % (rozmer * rozmer)];
			}
			return result;
		}
		private void set(int strana, int start, int diff, byte[] vysledek)
		{
			int[] result = new int[rozmer];
			for (int i = 0; i < rozmer; i++)
			{
				strany[strana][(start + i * diff + rozmer * rozmer) % (rozmer * rozmer)] = vysledek[i];
			}
		}
		private byte[] otocDoprava(byte[] strana)
		{
			byte[] result = new byte[strana.Length];
			for (int y = 0; y < rozmer; y++)
				for (int x = 0; x < rozmer; x++)
					result[x * rozmer + (rozmer - 1 - y)] = strana[y * rozmer + x];
			return result;
		}
		private byte[] otocDoleva(byte[] strana)
		{
			byte[] result = new byte[strana.Length];
			for (int y = 0; y < rozmer; y++)
				for (int x = 0; x < rozmer; x++)
					result[y * rozmer + x] = strana[x * rozmer + (rozmer - 1 - y)];
			return result;
		}
		public void rotaceVodorovne(int radek)
		{
			/*if (radek == 0) popis += "U ";
			else if (radek == 1) popis += "E' ";
			else if (radek == 2) popis += "D' ";*/
			var temp = select(1, radek * rozmer, 1);
			set(1, radek * rozmer, 1, select(2, radek * rozmer, 1));
			set(2, radek * rozmer, 1, select(3, radek * rozmer, 1));
			set(3, radek * rozmer, 1, select(4, radek * rozmer, 1));
			set(4, radek * rozmer, 1, temp);
			if (radek == 0) strany[0] = otocDoprava(strany[0]);
			else if (radek == rozmer - 1) strany[5] = otocDoleva(strany[5]);
		}
		public void rotaceVodorovne2(int radek)
		{
			/*if (radek == 0) popis += "U' ";
			else if (radek == 1) popis += "E ";
			else if (radek == 2) popis += "D ";*/
			var temp = select(1, radek * rozmer, 1);
			set(1, radek * rozmer, 1, select(4, radek * rozmer, 1));
			set(4, radek * rozmer, 1, select(3, radek * rozmer, 1));
			set(3, radek * rozmer, 1, select(2, radek * rozmer, 1));
			set(2, radek * rozmer, 1, temp);
			if (radek == 0) strany[0] = otocDoleva(strany[0]);
			else if (radek == rozmer - 1) strany[5] = otocDoprava(strany[5]);
		}
		public void rotaceSvisle(int sloupec)
		{
			/*if (sloupec == 0) popis += "L' ";
			else if (sloupec == 1) popis += "M' ";
			else if (sloupec == 2) popis += "R ";*/
			var temp = select(0, sloupec, rozmer);
			set(0, sloupec, rozmer, select(2, sloupec, rozmer));
			set(2, sloupec, rozmer, select(5, sloupec, rozmer));
			set(5, sloupec, rozmer, select(4, -1 - sloupec, -rozmer));
			set(4, -1 - sloupec, -rozmer, temp);
			if (sloupec == 0) strany[1] = otocDoleva(strany[1]);
			else if (sloupec == rozmer - 1) strany[3] = otocDoprava(strany[3]);
		}
		public void rotaceSvisle2(int sloupec)
		{
			/*if (sloupec == 0) popis += "L ";
			else if (sloupec == 1) popis += "M ";
			else if (sloupec == 2) popis += "R' ";*/
			var temp = select(0, sloupec, rozmer);
			set(0, sloupec, rozmer, select(4, -1 - sloupec, -rozmer));
			set(4, -1 - sloupec, -rozmer, select(5, sloupec, rozmer));
			set(5, sloupec, rozmer, select(2, sloupec, rozmer));
			set(2, sloupec, rozmer, temp);
			if (sloupec == 0) strany[1] = otocDoprava(strany[1]);
			else if (sloupec == rozmer - 1) strany[3] = otocDoleva(strany[3]);
		}
		private int doprava() { return 1; }
		private int dolu() { return rozmer; }
		private int doleva() { return -1; }
		private int nahoru() { return -rozmer; }
		public void rotaceDokola(int j)
		{
			/*if (j == 0) popis += "B ";
			else if (j == 1) popis += "S' ";
			else if (j == 2) popis += "F' ";*/
			var temp = select(0, j * rozmer, 1);
			set(0, j * rozmer, doprava(), select(3, rozmer - 1 - j, dolu()));
			set(3, rozmer - 1 - j, dolu(), select(5, (rozmer - 1 - j) * rozmer + (rozmer - 1), doleva()));
			set(5, (rozmer - 1 - j) * rozmer + rozmer - 1, doleva(), select(1, (rozmer - 1) * rozmer + j, nahoru()));
			set(1, (rozmer - 1) * rozmer + j, nahoru(), temp);
			if (j == 0) strany[4] = otocDoprava(strany[4]);
			else if (j == rozmer - 1) strany[2] = otocDoleva(strany[2]);
		}
		public void rotaceDokola2(int j)
		{
			/*if (j == 0) popis += "B' ";
			else if (j == 1) popis += "S ";
			else if (j == 2) popis += "F ";*/
			var temp = select(0, j * rozmer, 1);
			set(0, j * rozmer, doprava(), select(1, (rozmer - 1) * rozmer + j, nahoru()));
			set(1, (rozmer - 1) * rozmer + j, nahoru(), select(5, (rozmer - 1 - j) * rozmer + (rozmer - 1), doleva()));
			set(5, (rozmer - 1 - j) * rozmer + rozmer - 1, doleva(), select(3, rozmer - 1 - j, dolu()));
			set(3, rozmer - 1 - j, dolu(), temp);
			if (j == 0) strany[4] = otocDoleva(strany[4]);
			else if (j == rozmer - 1) strany[2] = otocDoprava(strany[2]);
		}
		private Cube klon()
		{
			Cube duplikat = (Cube)this.MemberwiseClone();
			duplikat.strany = new byte[strany.Length][];
			for (int i = 0; i < strany.Length; i++)
			{
				duplikat.strany[i] = new byte[strany[i].Length];
				for (int j = 0; j < strany[i].Length; j++)
					duplikat.strany[i][j] = strany[i][j];
			}
			return duplikat;
		}
		public IEnumerable<Cube> MozneTahy()
		{
			Cube duplikat;
			// Je nutne fixovat roh, aby se nerozbilo UniqueVertexNumber
			for (int i = 0; i < rozmer - 1; i++)
			{
				duplikat = klon();
				duplikat.rotaceDokola(i);
				yield return duplikat;
				duplikat = klon();
				duplikat.rotaceSvisle(i);
				yield return duplikat;
				duplikat = klon();
				duplikat.rotaceVodorovne(i);
				yield return duplikat;
				duplikat = klon();
				duplikat.rotaceDokola2(i);
				yield return duplikat;
				duplikat = klon();
				duplikat.rotaceSvisle2(i);
				yield return duplikat;
				duplikat = klon();
				duplikat.rotaceVodorovne2(i);
				yield return duplikat;
			}
			/*
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceDokola(i);
			yield return duplikat;
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceSvisle(i);
			yield return duplikat;
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceVodorovne(i);
			yield return duplikat;
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceDokola2(i);
			yield return duplikat;
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceSvisle2(i);
			yield return duplikat;
			duplikat = klon();
			for (int i = 0; i < rozmer - 1; i++)
				duplikat.rotaceVodorovne2(i);
			yield return duplikat;
			*/
		}
		public override int GetHashCode()
		{
			unchecked
			{
				int hash = 0;
				for (int i = 0; i < strany.Length; i++)
					for (int j = 0; j < strany[i].Length; j++)
						hash = hash * 7 + strany[i][j];// == 0 ? 0 : 1);
				return hash;
			}
		}

		public override bool Equals(object obj)
		{
			Cube druha = (Cube)obj;
			for (int i = 0; i < strany.Length; i++)
				for (int j = 0; j < strany[i].Length; j++)
					if (strany[i][j] != druha.strany[i][j]) return false;
			return true;
		}

		public override bool isFinal()
		{
			for (int i = 0; i < strany.Length; i++)
				for (int j = 0; j < strany[i].Length; j++)
					if ((strany[i][j] != i) && (strany[i][j] != 6)) return false;
			return true;
		}

		public override State clone()
		{
			return klon();
		}

		public override void getSuccessors(List<StateCostPair> result)
		{
			result.Clear();
			foreach (var item in MozneTahy())
			{
				result.Add(new StateCostPair(item, 1));
			}
		}

		public Cube RandomAction(Random rand, int walkLength = 1)
		{
			Cube state = this;
			for (int i = 0; i < walkLength; i++)
			{
				var neigbourStates = state.MozneTahy().ToArray();
				state = neigbourStates[rand.Next(neigbourStates.Length)];
			}
			return state;
		}

	}

	class RubicsCubeProblem : Problem
	{
		public override bool isFinal(State s)
		{
			return (s as Cube).isFinal();
		}

		public override void readFromFile(string dimension)
		{
			this.initialState = new Cube(int.Parse(dimension)).RandomAction(new Random(123), 15);
		}
	}

	class CubeVisualizer : Visualizer
	{
		public static void ColorizedWrite(object obj)
		{
			string str = obj.ToString();
			for (int i = 0; i < str.Length; i++)
			{
				Console.ForegroundColor = ConsoleColor.White;
				Console.BackgroundColor = ConsoleColor.Black;

				if (Char.IsDigit(str[i]))
				{
					Console.ForegroundColor = ConsoleColor.Black;
					switch (int.Parse(str[i].ToString()))
					{
						case 0: Console.BackgroundColor = ConsoleColor.Yellow; break;
						case 1: Console.BackgroundColor = ConsoleColor.Green; break;
						case 2: Console.BackgroundColor = ConsoleColor.Red; break;
						case 3: Console.BackgroundColor = ConsoleColor.Blue; break;
						case 4: Console.BackgroundColor = ConsoleColor.DarkRed; break;
						case 5: Console.BackgroundColor = ConsoleColor.Black; Console.ForegroundColor = ConsoleColor.White; break;
						case 6: Console.BackgroundColor = ConsoleColor.Gray; Console.ForegroundColor = ConsoleColor.Gray; break;
					}
					Console.Write(str[i]);
					i++;
					Console.Write(str[i]);
				}
				else
				{
					//Console.BackgroundColor = ConsoleColor.White;
					Console.Write(str[i]);
				}
			}
		}

		public override void visualize(State s)
		{
			ColorizedWrite(s);
			Console.WriteLine("----------------");
		}
	}

}
