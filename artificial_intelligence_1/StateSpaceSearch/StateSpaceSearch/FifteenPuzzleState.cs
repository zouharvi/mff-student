using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace StateSpaceSearch
{
    class FifteenPuzzleState : State
    {
        public int[,] numbers;
        int voidCoordinateX, voidCoordinateY;

        public override void getSuccessors(List<StateCostPair> result)
        {
            result.Clear();
            FifteenPuzzleState succ = (FifteenPuzzleState)this.clone();
            if (succ.voidCoordinateX > 0)
            {
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY] = succ.numbers[succ.voidCoordinateX - 1, succ.voidCoordinateY];
                succ.numbers[succ.voidCoordinateX - 1, succ.voidCoordinateY] = 0;
                succ.voidCoordinateX--;
                result.Add(new StateCostPair(succ, 1));
                succ = (FifteenPuzzleState)this.clone();
            }
            if (succ.voidCoordinateY > 0)
            {
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY] = succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY - 1];
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY - 1] = 0;
                succ.voidCoordinateY--;
                result.Add(new StateCostPair(succ, 1));
                succ = (FifteenPuzzleState)this.clone();
            }
            if (succ.voidCoordinateX < numbers.GetLength(0) - 1)
            {
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY] = succ.numbers[succ.voidCoordinateX + 1, succ.voidCoordinateY];
                succ.numbers[succ.voidCoordinateX + 1, succ.voidCoordinateY] = 0;
                succ.voidCoordinateX++;
                result.Add(new StateCostPair(succ, 1));
                succ = (FifteenPuzzleState)this.clone();
            }
            if (succ.voidCoordinateY < numbers.GetLength(1) - 1)
            {
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY] = succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY + 1];
                succ.numbers[succ.voidCoordinateX, succ.voidCoordinateY + 1] = 0;
                succ.voidCoordinateY++;
                result.Add(new StateCostPair(succ, 1));
                //succ = (FifteenPuzzleState)this.clone();
            }
        }

        public FifteenPuzzleState(List<int> numbers)
        {
            int size = (int)Math.Sqrt(numbers.Count);
            this.numbers = new int[size, size];
            for (int i = 0; i < numbers.Count; i++)
            {
                if(numbers[i] == 0)
                {
                    voidCoordinateX = i % size;
                    voidCoordinateY = i / size;
                }
                this.numbers[i % size, i / size] = numbers[i];
            }
        }

        public override State clone()
        {
            return new FifteenPuzzleState(this);
        }

        public FifteenPuzzleState(FifteenPuzzleState template)
        {
            this.p = template.p;
            this.voidCoordinateX = template.voidCoordinateX;
            this.voidCoordinateY = template.voidCoordinateY;
            this.numbers = new int[template.numbers.GetLength(0), template.numbers.GetLength(1)];
            for (int i = 0; i < template.numbers.GetLength(0); i++)
            {
                for (int j = 0; j < template.numbers.GetLength(1); j++)
                {
                    this.numbers[i, j] = template.numbers[i, j];
                }
            }
        }

        public override bool Equals(object obj)
        {
            if (!(obj is FifteenPuzzleState))
                return false;
            FifteenPuzzleState s = (FifteenPuzzleState)obj;
            for (int i = 0; i < s.numbers.GetLength(0); i++)
            {
                for (int j = 0; j < s.numbers.GetLength(1); j++)
                {
                    if (this.numbers[i, j] != s.numbers[i, j])
                        return false;
                }
            }
            return true;
        }

        public override int GetHashCode()
        {
            int result = 0, step = this.numbers.GetLength(0) * this.numbers.GetLength(1);
            for (int i = 0; i < this.numbers.GetLength(0); i++)
            {
                for (int j = 0; j < this.numbers.GetLength(1); j++)
                {
                    result += step * this.numbers[i, j];
                    step += this.numbers.GetLength(0) * this.numbers.GetLength(1);
                }
            }
            return result;
        }

		public int simpleHeur()
		{
			if (isFinal())
				return 0;
			int distance = 0;
			for (int i = 0; i < numbers.GetLength(0); i++)
			{
				for (int j = 0; j < numbers.GetLength(1); j++)
				{
					distance += getDistance(i, getCorrectRow(numbers[i, j]));
					distance += getDistance(j, getCorrectCollumn(numbers[i, j]));
				}
			}
			return distance;
		}

		private int getDistance(int first, int second)
		{
			return first > second ? first - second : second - first;
		}

		private int getCorrectRow(int number)
		{
			return number / numbers.GetLength(0);
		}

		private int getCorrectCollumn(int number)
		{
			return (number-1) % numbers.GetLength(1);
		}

	}

    class FifteenPuzzleProblem : Problem
    {
        int size;

        public override void readFromFile(string filePath)
        {
            using (var reader = new System.IO.StreamReader(filePath))
            {
                this.size = int.Parse(reader.ReadLine());
                List<int> numbers = new List<int>();
                for (int i = 0; i < size*size; i++)
                {
                    numbers.Add(int.Parse(reader.ReadLine()));
                }

                this.initialState = new FifteenPuzzleState(numbers);
                this.initialState.p = this;
            }
        }

        public override bool isFinal(State s)
        {
            if (!(s is FifteenPuzzleState))
                return false;
            FifteenPuzzleState state = (FifteenPuzzleState)s;
            for (int i = 0; i < state.numbers.GetLength(1); i++)
            {
                for (int j = 0; j < state.numbers.GetLength(0); j++)
                {
                    if (i == state.numbers.GetLength(1) - 1 && j >= state.numbers.GetLength(1) - 3)
                        continue;
                    if (state.numbers[j, i] != i * state.numbers.GetLength(1) + j + 1)
                        return false;
                }   
            }
            return true;
        }

    }

    class FifteenPuzzleVisualizer : Visualizer
    {
        int tileSize, gapSize = 5;
        Pen gridPen = Pens.Black;
        Brush numberBrush = Brushes.Blue;

        public override void visualize(State s)
        {
            g.Clear(Color.White);
            if (!(s is FifteenPuzzleState))
                throw new ArgumentException();
            FifteenPuzzleState state = (FifteenPuzzleState)s;
            tileSize = (int)Math.Min(screen.Width / state.numbers.GetLength(0), screen.Height / state.numbers.GetLength(1));
            Font numberFont = new Font("Arial", tileSize / (int)Math.Max(state.numbers.GetLength(0), state.numbers.GetLength(1)));
            for (int i = 0; i < state.numbers.GetLength(0); i++)
                for (int j = 0; j < state.numbers.GetLength(1); j++)
                {
                    if (state.numbers[i, j] == 0)
                        continue;
                    g.DrawRectangle(gridPen, (i + 1) * gapSize + i * tileSize,
                        (j + 1) * gapSize + j * tileSize, tileSize, tileSize);
                    g.DrawString(state.numbers[i, j].ToString(), numberFont, numberBrush,
                        (float)((i + 1) * gapSize + i * tileSize + gapSize), (float)((j + 1) * gapSize + j * tileSize + gapSize));
                }
            refresh();            
        }
    }
}
