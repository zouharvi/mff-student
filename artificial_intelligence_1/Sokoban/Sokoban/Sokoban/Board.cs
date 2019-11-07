using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sokoban
{
	public static class Extensions
	{
		public static string ToStringArray(this Coords[] arrayCoords)
		{
			StringBuilder sb = new StringBuilder();
			foreach (var item in arrayCoords)
			{
				sb.Append(item.ToString() + ", ");
			}
			return sb.ToString();
		}
	}

    public enum CellState
    {
        empty,
        obstacle,
        //crate,
        //sokoban,
        target,
        //sokobanOnTarget
    }

    public enum Direction
    {
        left,
        right,
        up,
        down
    }

    public struct Coords
    {
        public static int[,] hashValuesTable;
        public static int accessigbleTilesCount;

        public byte x, y;

        public void change(Direction d)
        {
            switch (d)
            {
                case Direction.down:
                    y++;
                    break;
                case Direction.left:
                    x--;
                    break;
                case Direction.right:
                    x++;
                    break;
                case Direction.up:
                    y--;
                    break;
            }
        }

        public Coords(int x, int y)
        {
            this.x = (byte)x;
            this.y = (byte)y;
        }

        public override int GetHashCode()
        {
            /*
            if(hashValuesTable[x, y] != 0)
                return hashValuesTable[x, y];
            */
            unchecked
            {
                int hash = x;
                hash *= 137;
                hash += y;
				hash *= 139;
				return hash + Coords.accessigbleTilesCount;
            }
        }

        public override bool Equals(object obj)
        {
            if (obj is Coords)
            {
                Coords o = (Coords)obj;
                return this.x == o.x && this.y == o.y;
            }
            else return false;
        }

        public override string ToString()
        {
            return "[" + x + ", " + y + "]";
        }
        public string ToPrintString()
        {
            return x + " " + y;
        }
    }


	public class Cell
    {
        public CellState state;
        public Crate content;
        private bool _data;
        public bool isAccesibleToCrate
        {
            get { return Form1.useDeadEndDetection ? this._data : true; }
            set { _data = value; }
        }

        public Cell(CellState state, Crate content)
        {
            this.state = state;
            this.content = content;
        }

        public static Cell border = new Cell(CellState.obstacle, null);
    }

    public class Crate
    {
        public Coords location;

        public override string ToString()
        {
            return location.ToPrintString();
        }
    }

    public class Board
    {
        public Board()
        {
            this.crates = new List<Crate>();
        }

        public Board(int sizeX, int sizeY)
        {
            this.size.x = (byte)sizeX;
            this.size.y = (byte)sizeY;
            this.crates = new List<Crate>();
            this.cells = new Cell[this.size.x, this.size.y];
            for (int i = 0; i < size.x; i++)
                for (int j = 0; j < size.y; j++)
                    this.cells[i, j] = new Cell(CellState.empty, null);
        }

		/// <summary>
		/// Size of the board
		/// </summary>
		public Coords size;

		/// <summary>
		/// Position of Sokoban (in the initial state)
		/// </summary>
		public Coords sokobanPos;

		/// <summary>
		/// List of all crates and their locations (in the initial state)
		/// </summary>
		public List<Crate> crates;

        public int randomSeed;

        Cell[,] cells;
        private bool forbidenTilesComputed = false;

        public void move(Direction d)
        {
            if (!canMove(d))
                return;
            if (this[sokobanPos, d].content != null)
                moveCrate(this[sokobanPos, d], d);
            sokobanPos.change(d);
        }
            
        private void moveCrate(Cell cell, Direction d)
        {
            Coords originalLoc = cell.content.location;
            this[cell.content.location, d].content = cell.content;
            cell.content.location.change(d);
            this[originalLoc].content = null;
        }

        public bool canBePushed(Crate c, Direction d)
        {
            if (c == null)
                return true;
            Cell target = this[c.location, d];
            return target.isAccesibleToCrate && target.state != CellState.obstacle && target.content == null;
        }

        public bool canMove(Direction d)
        {
            return this[sokobanPos, d].state != CellState.obstacle && 
                canBePushed(this[sokobanPos, d].content, d);
        }
        /// <summary>
        /// Deprecated. Use computeForbidenTiles() instead.
        /// </summary>
        private void computeForbidenTiles2()
        {
            Cell.border.isAccesibleToCrate = false;
            for (int i = 0; i < size.x; i++)
                for (int j = 0; j < size.y; j++)
                {
                    Cell item = cells[i, j];
                    item.isAccesibleToCrate = true;
                    if (item.state == CellState.obstacle)
                    {
                        item.isAccesibleToCrate = false;
                        continue;
                    }
                    if (Solver.isCorner(new Coords(i, j), this) && item.state != CellState.target)
                    {
                        item.isAccesibleToCrate = false;
                        continue;
                    }

                    if (Solver.isOnBorder(new Coords(i, j), this))
                    {
                        bool targetFound = false;
                        if (i == 0 || i == this.size.x - 1)
                        {
                            for (int k = 0; k < size.y; k++)
                            {
                                if (this[i, k].state == CellState.target)
                                {
                                    targetFound = true;
                                    break;
                                }
                            }
                        }

                        if (j == 0 || j == size.y - 1)
                        {
                            for (int k = 0; k < size.x; k++)
                            {
                                if (this[k, j].state == CellState.target)
                                {
                                    targetFound = true;
                                    break;
                                }
                            }
                        }
                        if (!targetFound)
                            item.isAccesibleToCrate = false;
                    }
                }
        }

        /// <summary>
        /// For each tile, the method computes whether or not it is favorable to move the crate to that tile. For example, it never allows to move the crate into a corner and so on.
        /// </summary>
        public void findForbidenTiles()
        {
            if (forbidenTilesComputed || !Form1.useDeadEndDetection || cells == null)
                return;
            Cell.border.isAccesibleToCrate = false;
            List<Coords> openList = new List<Coords>();
            bool[,] visited = new bool[size.x, size.y];

            for (int i = 0; i < size.x; i++)
                for (int j = 0; j < size.y; j++)
                {
                    Cell item = cells[i, j];
                    item.isAccesibleToCrate = false;
                    if (item.state == CellState.target)
                    {
                        item.isAccesibleToCrate = true;
                        openList.Add(new Coords(i, j));
                    }
                }
            Coords target = new Coords(), origin = new Coords();
            while (openList.Count > 0)
            {
                Coords current = openList[0];
                openList.RemoveAt(0);
                if (visited[current.x, current.y])
                    continue;
                visited[current.x, current.y] = true;
                foreach (var dir in Solver.allDirections)
                {
                    target.x = current.x;
                    target.y = current.y;
                    target.change(dir);
                    if (this[target].state == CellState.obstacle)
                        continue;
                    origin.x = target.x;
                    origin.y = target.y;
                    origin.change(dir);
                    if (this[origin].state == CellState.obstacle)
                        continue;
                    openList.Add(new Coords(target.x, target.y));
                    this[target].isAccesibleToCrate = true;
                }
            }
            forbidenTilesComputed = true;
        }

        public Cell this[int indexX, int indexY]
        {
            get
            {
                if (indexX < 0 || indexX >= size.x || indexY < 0 || indexY >= size.y)
                    return Cell.border;
                return cells[indexX, indexY];
            }

            private set
            {
                cells[indexX, indexY] = value;
            }
        }

        public Cell this[Coords c]
        {
            get
            {
                if (c.x < 0 || c.x >= size.x || c.y < 0 || c.y >= size.y)
                    return Cell.border;
                return cells[c.x, c.y];
            }

            private set
            {
                cells[c.x, c.y] = value;
            }
        }

        /// <summary>
        /// Acceses the grid on the location in specified direction from specified cell. Returns the content or "obstacle" if the index is out of range
        /// </summary>
        /// <param name="c"></param>
        /// <param name="d"></param>
        /// <returns></returns>
        public Cell this[Coords c, Direction d]
        {
            get
            {
                switch (d)
                {
                    case Direction.right:
                        if (c.x == size.x - 1)
                            return Cell.border;
                        return cells[c.x + 1, c.y];
                    case Direction.left:
                        if (c.x == 0)
                            return Cell.border;
                        return cells[c.x - 1, c.y];
                    case Direction.down:
                        if (c.y == size.y - 1)
                            return Cell.border;
                        return cells[c.x, c.y + 1];
                    case Direction.up:
                        if (c.y == 0)
                            return Cell.border;
                        return cells[c.x, c.y - 1];
                    default:
                        return Cell.border;
                }
            }

            private set
            {
                switch (d)
                {
                    case Direction.down:
                        if (c.x == size.x)
                            return;
                        cells[c.x + 1, c.y] = value;
                        break;
                    case Direction.up:
                        if (c.x == 0)
                            return;
                        cells[c.x - 1, c.y] = value;
                        break;
                    case Direction.right:
                        if (c.y == size.y)
                            return;
                        cells[c.x, c.y + 1] = value;
                        break;
                    case Direction.left:
                        if (c.y == 0)
                            return;
                        cells[c.x, c.y - 1] = value;
                        break;
                }
            }
        }

        public void randomize(int seed = -1)
        {
            Random r = new Random();
            if (seed > 0)
                this.randomSeed = seed;
            else
                this.randomSeed = r.Next(10000);
            r = new Random(this.randomSeed);
            this.size = new Coords(r.Next(15) + 5, r.Next(10) + 5);
            double obstaclesRatio = r.NextDouble() / 5 + 0.20;
            int obstacles = (int)(size.x * size.y * obstaclesRatio);
            this.cells = new Cell[size.x, size.y];
            this.crates.Clear();

            int x, y;

            for (int i = 0; i < size.x; i++)
                for (int j = 0; j < size.y; j++)
                    this.cells[i, j] = new Cell(CellState.empty, null);

            for (int i = 0; i < obstacles; i++)
            {
                x = r.Next(size.x);
                y = r.Next(size.y);
                while (cells[x, y].state != CellState.empty)
                {
                    x = r.Next(size.x);
                    y = r.Next(size.y);
                }
                cells[x, y].state = CellState.obstacle;
            }

            int crates = r.Next(4) + 1;

            for (int i = 0; i < crates; i++)
            {
                Crate c = new Crate();

                x = r.Next(size.x);
                y = r.Next(size.y);
                while (cells[x, y].state != CellState.empty || cells[x, y].content != null)
                {
                    x = r.Next(size.x);
                    y = r.Next(size.y);
                }
                cells[x, y].content = c;
                c.location = new Coords(x, y);
                this.crates.Add(c);
            }

            for (int i = 0; i < crates; i++)
            {
                x = r.Next(size.x);
                y = r.Next(size.y);
                while (cells[x, y].state != CellState.empty)
                {
                    x = r.Next(size.x);
                    y = r.Next(size.y);
                }
                cells[x, y].state = CellState.target;
            }

            x = r.Next(size.x);
            y = r.Next(size.y);
            while (cells[x, y].state != CellState.empty || cells[x, y].content != null)
            {
                x = r.Next(size.x);
                y = r.Next(size.y);
            }

            this.sokobanPos = new Coords(x, y);
            /*
            Solver s = new Solver();
            while (s.solve(this, 10) == null)
                this.randomize();
            */
        }

        public void createSimple()
        {
            this.size.x = 5;
            this.size.y = 5;
            this.cells = new Cell[size.x, size.y];
            this.crates.Clear();

            for (int i = 0; i < size.x; i++)
                for (int j = 0; j < size.y; j++)
                    this.cells[i, j] = new Cell(CellState.empty, null);

            this.cells[0, 4].state = CellState.obstacle;
            this.cells[2, 3].state = CellState.target;

            Crate c = new Crate();
            cells[1, 3].content = c;
            c.location = new Coords(1, 3);
            this.crates.Add(c);

            this.sokobanPos = new Coords(2, 2);
        }

        public void load(string file)
        {
			if (System.IO.Path.GetExtension(file) == ".xsb")
			{
				loadXSB(file);
				return;
			}

            this.forbidenTilesComputed = false;
            using (var reader = new System.IO.StreamReader(file))
            {
                string line = reader.ReadLine();
                string[] splitted = line.Split(' ');
                size = new Coords(int.Parse(splitted[0]), int.Parse(splitted[1]));

                line = reader.ReadLine();
                splitted = line.Split(' ');
                sokobanPos = new Coords(int.Parse(splitted[0]), int.Parse(splitted[1]));

                int cratesCount = int.Parse(reader.ReadLine());
                this.crates = new List<Crate>();
                for (int i = 0; i < cratesCount; i++)
                {
                    line = reader.ReadLine();
                    splitted = line.Split(' ');
                    Crate c = new Crate();
                    c.location = new Coords(int.Parse(splitted[0]), int.Parse(splitted[1]));
                    crates.Add(c);
                }

                cells = new Cell[size.x, size.y];
                for (int i = 0; i < size.x; i++)
                {
                    for (int j = 0; j < size.y; j++)
                    {
                        line = reader.ReadLine();
                        switch (line)
                        {
                            case "empty":
                                cells[i, j] = new Cell(CellState.empty, null);
                                break;
                            case "target":
                                cells[i, j] = new Cell(CellState.target, null);
                                break;
                            case "obstacle":
                                cells[i, j] = new Cell(CellState.obstacle, null);
                                break;
                        }
                    }
                }
                foreach (var item in crates)
                {
                    this[item.location].content = item;
                }
            }
        }

		public void loadXSB(string file)
		{
			var lines = System.IO.File.ReadAllLines(file).TakeWhile(g => !string.IsNullOrWhiteSpace(g)).ToList();
			List<List<Cell>> cells = new List<List<Cell>>();
			int i = -1;
			foreach (var item in lines)
			{
				i++;
				List<Cell> thisLine = new List<Cell>();
				int j = -1;
				foreach (var symbol in item)
				{
					j++;
					switch (symbol)
					{
						case '#':
							thisLine.Add(new Cell(CellState.obstacle, null));
							break;
						case ' ':
							thisLine.Add(new Cell(CellState.empty, null));
							break;
						case '$':
							thisLine.Add(new Cell(CellState.empty, new Crate()));
							break;
						case '.':
							thisLine.Add(new Cell(CellState.target, null));
							break;
						case '*':
							thisLine.Add(new Cell(CellState.target, new Crate()));
							break;
						case '@':
							thisLine.Add(new Cell(CellState.empty, null));
							this.sokobanPos = new Coords(i, j);
							break;
						case '+':
							thisLine.Add(new Cell(CellState.target, null));
							this.sokobanPos = new Coords(i, j);
							break;
						default:
							break;
					}
				}
				cells.Add(thisLine);
			}
			this.size = new Coords(lines.Count(), lines.Max(l => l.Count()));
			this.cells = new Cell[size.x, size.y];
			i = -1;
			this.crates.Clear();
			foreach (var item in cells)
			{
				i++;
				int j = - 1;
				foreach (var state in item)
				{
					j++;
					this.cells[i, j] = new Cell(state.state, state.content);
					if (state.content != null)
					{
						this.crates.Add(state.content);
						state.content.location = new Coords(i, j);
					}
				}
				j++;
				for (; j < size.y; j++)
				{
					this.cells[i, j] = new Cell(CellState.empty, null);
				}
			}
			this.forbidenTilesComputed = false;
		}

        public void save(string file)
        {
            using (var writer = new System.IO.StreamWriter(file))
            {
                writer.WriteLine(size.ToPrintString());
                writer.WriteLine(sokobanPos.ToPrintString());
                writer.WriteLine(crates.Count);
                foreach (var item in crates)
                {
                    writer.WriteLine(item.ToString());
                }
                foreach (var item in cells)
                {
                    writer.WriteLine(item.state);
                }
            }
            string newFile = file.Substring(0, file.Length - 3) + "txt";
            using (var writer = new System.IO.StreamWriter(newFile))
            {
                for (int j = 0; j < size.y; j++)
                {
                    for (int i = 0; i < size.x; i++)
                    {
                        if (sokobanPos.x == i && sokobanPos.y == j)
                        {
                            writer.Write("S");
                            continue;
                        }
                        if (crates.Any(c => c.location.x == i && c.location.y == j))
                        {
                            writer.Write("B");
                            continue;
                        }
                        switch (cells[i, j].state)
                        {
                            case CellState.empty:
                                writer.Write(".");
                                break;
                            case CellState.obstacle:
                                writer.Write("X");
                                break;
                            case CellState.target:
                                writer.Write("C");
                                break;
                        }
                    }
                    writer.WriteLine();
                }
            }
        }

        #region editaion methods

        public void edit_ClearTile(Coords tile)
        {
            if (this[tile].content != null)
            {
                crates.Remove(this[tile].content);
                this[tile].content = null;
            }
            this[tile].state = CellState.empty;
        }

        public void edit_SetTarget(Coords tile)
        {
            this[tile].state = CellState.target;
        }

        public void edit_SetObstacle(Coords tile)
        {
            if (this[tile].content != null)
            {
                crates.Remove(this[tile].content);
                this[tile].content = null;
            }
            this[tile].state = CellState.obstacle;
        }

        public void edit_AddCrate(Coords tile)
        {
            if (this[tile].content != null || this[tile].state == CellState.obstacle)
            {
                return;
            }
            Crate c = new Crate();
            c.location = tile;
            this[tile].content = c;
            crates.Add(c);
        }

        public void edit_AddSokoban(Coords tile)
        {
            if (this[tile].state == CellState.obstacle)
                return;
            if (this[tile].content != null)
            {
                crates.Remove(this[tile].content);
                this[tile].content = null;
            }
            this.sokobanPos = tile;
        }
        
        #endregion

    }
}
