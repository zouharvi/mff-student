using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace StateSpaceSearch
{
    class TSPState : State
    {
        public HashSet<int> notVisited;
		public List<int> path;
        public int currentPosition;

        public override State clone()
        {
            return new TSPState(this);
        }

        public TSPState(TSPState template)
        {
            this.p = template.p;
            this.currentPosition = template.currentPosition;
            this.notVisited = new HashSet<int>(template.notVisited);
			this.path = new List<int>(template.path);
        }

        public override void getSuccessors(List<StateCostPair> result)
        {
            result.Clear();
            TSPProblem p = (TSPProblem)this.p;
            foreach (var item in notVisited)
            {
                TSPState succ = (TSPState)this.clone();
                succ.notVisited.Remove(item);
                succ.currentPosition = item;
				succ.path.Add(item);
                result.Add(new StateCostPair(succ, p.getDistance(this.currentPosition, succ.currentPosition)));
            }
        }

        public override bool Equals(object obj)
        {
            if (!(obj is TSPState))
                return false;
            TSPState state = (TSPState)obj;
            if (state.currentPosition != this.currentPosition)
                return false;
            if (this.notVisited.Count != state.notVisited.Count)
                return false;
            foreach (var item in this.notVisited)
            {
                if (!state.notVisited.Contains(item))
                    return false;
            }
			for (int i = 0; i < path.Count; i++)
			{
				if (path[i] != state.path[i])
					return false;
			}
            return true;
        }

        public override int GetHashCode()
        {
            int result = 1;
            result += this.currentPosition * 7733;
            foreach (var item in this.notVisited)
            {
                result += item;
            }
			int mult = 7;
			for (int i = 0; i < path.Count; i++)
			{
				result += (path[i] + 1) * mult * (i + 1);
			}
            return result;
        }

        public TSPState(TSPProblem p)
        {
            this.notVisited = new HashSet<int>();
			this.path = new List<int>();
            this.p = p;
        }

		public override string ToString()
		{
			string res = "";
			res += "pos=" + currentPosition + "not visited:";
			foreach (var item in notVisited)
			{
				res = res + item + ",";
			}
			return res;
		}

	}

    public struct intPair
    {
        public int x, y;

        public intPair(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class TSPProblem : Problem
    {
        public int citiesCount;
        protected int[,] distances;
        public List<intPair> positions;

        public int getDistance(int from, int to)
        {
            return distances[from, to];
        }

        public override bool isFinal(State s)
        {
            return ((TSPState)s).notVisited.Count == 0;
        }

		public static TSPProblem createRandom(int citiesCount, Random r)
		{
			TSPProblem p = new TSPProblem();
			p.positions = new List<intPair>();
			p.citiesCount = citiesCount;
			for (int i = 0; i < citiesCount; i++)
			{
				p.positions.Add(new intPair(r.Next(1000), r.Next(1000)));
			}
			TSPState s = new TSPState(p);
			s.notVisited = new HashSet<int>();
			s.currentPosition = 0;
			for (int i = 0; i < citiesCount; i++)
			{
				s.notVisited.Add(i);
			}
			p.initialState = s;
			p.computeDistances();
			return p;
		}

        public override void readFromFile(string filePath)
        {
            positions = new List<intPair>();
            using(var reader = new System.IO.StreamReader(filePath))
            {
                this.citiesCount = int.Parse(reader.ReadLine());
                for (int i = 0; i < citiesCount; i++)
                {
                    positions.Add(new intPair(int.Parse(reader.ReadLine()), int.Parse(reader.ReadLine())));
                }
            }
            TSPState s = new TSPState(this);
            s.notVisited = new HashSet<int>();
            s.currentPosition = 0;
            for (int i = 0; i < citiesCount; i++)
            {
                s.notVisited.Add(i);
            }
            this.initialState = s;
            computeDistances();
        }

        private void computeDistances()
        {
            this.distances = new int[citiesCount, citiesCount];
            for (int i = 0; i < citiesCount; i++)
            {
                for (int j = 0; j < citiesCount; j++)
                {
                    distances[i, j] = (int)Math.Sqrt((positions[i].x - positions[j].x) * (positions[i].x - positions[j].x) +
                        (positions[i].y - positions[j].y) * (positions[i].y - positions[j].y));
                    distances[j, i] = distances[i, j];
                }
            }
        }

    }

    class TSPVisualizer : Visualizer
    {
        private double xStretch, yStretch;
        private bool showNumbers = false, clear = true;
        private int width, height;
        public TSPProblem problem;

        private float nodeSize = 7f;

        public void setShowNumbers(bool newValue)
        {
            showNumbers = newValue;
        }

        public override void init(PictureBox p)
        {
            base.init(p);
            this.width = (int)(p.Width - nodeSize);
            this.height = (int)(p.Height - nodeSize);
        }

        private void drawNode(int city)
        {
            intPair p = problem.positions[city];
            if (showNumbers)
            {
                g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), 2, 2);
                g.DrawString(city.ToString(), new Font("Arial", 15), Brushes.Blue, new PointF(
                    (float)(p.x * xStretch) - nodeSize, (float)(p.y * yStretch) - nodeSize));
            }
            else
                g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
        }

        private void fillNode(int city, Color c)
        {
            intPair p = problem.positions[city];
            g.FillRectangle(new SolidBrush(c), (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
            g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
        }

		private void drawLine(int city1, int city2)
		{
			intPair p1 = problem.positions[city1];
			intPair p2 = problem.positions[city2];
			g.DrawLine(Pens.Blue, (float)(p1.x * xStretch) + nodeSize/2, (float)(p1.y * yStretch) + nodeSize/2,
				(float)(p2.x * xStretch) + nodeSize / 2, (float)(p2.y * yStretch) + nodeSize / 2);
		}

        public override void visualize(State s)
        {
            this.problem = (TSPProblem)s.p;
            TSPState state = (TSPState)s;
            int maxValueX = problem.positions.Max(x => x.x),
                maxValueY = problem.positions.Max(x => x.y);

            if (clear)
                g.Clear(Color.WhiteSmoke);
            xStretch = (double)width / (maxValueX + 20);
            yStretch = (double)height / (maxValueY + 20);
            if (problem.citiesCount > 2000)
                nodeSize--;
            if (problem.citiesCount > 10000)
                nodeSize--;

			for (int i = 0; i < state.path.Count-1; i++)
			{
				drawLine(state.path[i], state.path[i + 1]);
			}

            for (int i = 0; i < problem.citiesCount; i++)
            {
                drawNode(i);
                if (state.notVisited.Contains(i))
                    fillNode(i, Color.Red);
                else
                    fillNode(i, Color.Black);
            }
            fillNode(state.currentPosition, Color.Green);
            screen.Refresh();
        }
    }

}
