using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sokoban
{
    class CoordListComparer : IEqualityComparer<Coords[]>
    {
        #region IEqualityComparer<Coords[]> Members

        public int equalsCalls = 0;
        public int hashCodeCalls = 0;
        public int colissions = 0;

        public bool Equals(Coords[] x, Coords[] y)
        {
            unchecked
            {
				/*
                equalsCalls++;
                if (GetHashCode1(x) == GetHashCode1(y) && !Equals1(x, y))
                    colissions++;
				*/

                if (x == y)
                    return true;

                if (x.Length != y.Length)
                    return false;

                for (int i = x.Length - 1; i >= 0; i--)
                {
                    if (!x[i].Equals(y[i]))
                        return false;
                }
                return true;    //217 sec. x 227 sec perfect hashing, 223 perfect + weird stuff at the end
            }
        }

        private int GetHashCode1(Coords[] obj)
        {
            unchecked
            {
                /*
                int hash = 17;
                for (int i = obj.Length - 1; i >= 0; i--)
                {
                    hash = hash * 31 + obj[i].GetHashCode();
                }
                return hash;
                */
                
                const int p = 16777619;
                int hash = (int)2166136261;

                for (int i = 0; i < obj.Length; i++)
                    hash = (hash ^ obj[i].GetHashCode()) * p;

                hash += hash << 13;
                hash ^= hash >> 7;
                hash += hash << 3;
                hash ^= hash >> 17;
                hash += hash << 5;
                return hash;
                 
                
            }
        }

        private bool Equals1(Coords[] x, Coords[] y)
        {
            unchecked
            {
                if (x == y)
                    return true;

                if (x.Length != y.Length)
                    return false;

                for (int i = x.Length - 1; i >= 0; i--)
                {
                    if (!x[i].Equals(y[i]))
                        return false;
                }
                return true;
            }
        }

        public int GetHashCode(Coords[] obj)
        {
            unchecked
            {
                //hashCodeCalls++;
                
                /*
                int hash = 17;
                for (int i = obj.Length - 1; i >= 0; i--)
                {
                    hash = hash * 31 + obj[i].GetHashCode();
                }
                return hash;
                */
                
                
                const int p = 16777619;
                int hash = (int)2166136261;

                for (int i = 0; i < obj.Length; i++)
                    hash = (hash ^ obj[i].GetHashCode()) * p;

                hash += hash << 13;
                hash ^= hash >> 7;
                hash += hash << 3;
                hash ^= hash >> 17;
                hash += hash << 5;
                return hash;
                
                /*
                int hash = 0;
                for (int i = 0; i < obj.Length; i++)
                    hash = (hash * Coords.accessigbleTilesCount + obj[i].GetHashCode());
                return hash;
                */
            }
        }

        #endregion
    }

    struct Pair
    {
        public Coords[] state;
        public int gValue;

        public Pair(Coords[] state, int val)
        {
            this.state = state;
            this.gValue = val;
        }
    }

    abstract class Heuristic
    {
        public abstract void init(Board b);
        public abstract int getValue(Coords[] state);
    }

    class WeightedHeuristic : Heuristic
    {
        private Heuristic h;
        private int weight;

        public WeightedHeuristic(Heuristic h, int weight)
        {
            this.h = h;
            this.weight = weight;
        }

        public override void init(Board b)
        {
            h.init(b);
        }

        public override int getValue(Coords[] state)
        {
            return weight * h.getValue(state);
        }
    }

    abstract class DistanceHeuristic : Heuristic
    {
        private int limit;
        protected Dictionary<Coords, Dictionary<Coords, int>> distancesSokoban;
        protected Dictionary<Coords, Dictionary<Coords, int>> distancesCrate;
        protected void computeDistances(Board b)
        {
            b.findForbidenTiles();
            distancesSokoban = new Dictionary<Coords, Dictionary<Coords, int>>();
            distancesCrate = new Dictionary<Coords, Dictionary<Coords, int>>();
            limit = b.size.x * b.size.y * 2;
            for (int i = 0; i < b.size.x; i++)
            {
                for (int j = 0; j < b.size.y; j++)
                {
                    if (b[i, j].state == CellState.obstacle)
                        continue;
                    UpdateDistance(i, j, i, j, 0, true);
                    UpdateDistance(i, j, i, j, 0, false);

                    Coords target = new Coords(), origin = new Coords();
                    foreach (var dir in Solver.allDirections)
                    {
                        target.x = (byte)i;
                        target.y = (byte)j;
                        target.change(dir);
                        if (b[target].state == CellState.obstacle)
                            continue;
                        UpdateDistance(i, j, target.x, target.y, 1, true);

                        origin.x = target.x;
                        origin.y = target.y;
                        origin.change(dir);
                        if (b[origin].state == CellState.obstacle)
                            continue;
                        UpdateDistance(target.x, target.y, i, j, 1, false);
                    }
                    /*
                    if (b[i + 1, j].state != CellState.obstacle)
                    {
                        UpdateDistance(i, j, i + 1, j, 1, true);
                        UpdateDistance(i, j, i + 1, j, 1, false);
                    }
                    if (b[i, j + 1].state != CellState.obstacle)
                    {
                        UpdateDistance(i, j, i, j + 1, 1, true);
                        UpdateDistance(i, j, i, j + 1, 1, false);
                    }
                      */
                }
            }
            
            for (int x1 = 0; x1 < b.size.x; x1++)
                for (int y1 = 0; y1 < b.size.y; y1++)
                    for (int x2 = 0; x2 < b.size.x; x2++)
                        for (int y2 = 0; y2 < b.size.y; y2++)
                            for (int x3 = 0; x3 < b.size.x; x3++)
                                for (int y3 = 0; y3 < b.size.y; y3++)
                                {
                                    int dist_2_1 = getDistance(x2, y2, x1, y1, true);
                                    int dist_1_3 = getDistance(x1, y1, x3, y3, true);
                                    int dist_2_3 = getDistance(x2, y2, x3, y3, true);
                                    if (dist_2_3 > dist_2_1 + dist_1_3)
                                        UpdateDistance(x2, y2, x3, y3, dist_2_1 + dist_1_3, true);

                                    //if (Solver.isCorner(new Coords(x1, y1), b))
                                    if (!b[x1, y1].isAccesibleToCrate)
                                        continue;
                                    dist_2_1 = getDistance(x2, y2, x1, y1, false);
                                    dist_1_3 = getDistance(x1, y1, x3, y3, false);
                                    dist_2_3 = getDistance(x2, y2, x3, y3, false);
                                    if (dist_2_3 > dist_2_1 + dist_1_3)
                                        UpdateDistance(x2, y2, x3, y3, dist_2_1 + dist_1_3, false);
                                }
        }

        private int getDistance(int x1, int y1, int x2, int y2, bool isForSokoban)
        {
            Coords c1 = new Coords(x1, y1),
            c2 = new Coords(x2, y2);
            if (isForSokoban)
            {
                if (!distancesSokoban.ContainsKey(c1) || !distancesSokoban[c1].ContainsKey(c2))
                    return limit;
                return distancesSokoban[c1][c2];
            }
            else
            {
                if (!distancesCrate.ContainsKey(c1) || !distancesCrate[c1].ContainsKey(c2))
                    return limit;
                return distancesCrate[c1][c2];
            }
        }

        /// <summary>
        /// Updates distance from [x1,y1] to [x2,y2]. Distances for sokoban are symmetric, for crates they are not.
        /// </summary>
        /// <param name="x1"></param>
        /// <param name="y1"></param>
        /// <param name="x2"></param>
        /// <param name="y2"></param>
        /// <param name="distance"></param>
        /// <param name="isForSokoban"></param>
        private void UpdateDistance(int x1, int y1, int x2, int y2, int distance, bool isForSokoban)
        {
            Coords c1 = new Coords(x1, y1),
            c2 = new Coords(x2, y2);
            if (isForSokoban)
            {
                if (!distancesSokoban.ContainsKey(c1))
                    distancesSokoban.Add(c1, new Dictionary<Coords, int>());

                if (!distancesSokoban.ContainsKey(c2))
                    distancesSokoban.Add(c2, new Dictionary<Coords, int>());

                if (!distancesSokoban[c1].ContainsKey(c2))
                    distancesSokoban[c1].Add(c2, distance);
                else distancesSokoban[c1][c2] = distance;

                if (!distancesSokoban[c2].ContainsKey(c1))
                    distancesSokoban[c2].Add(c1, distance);
                else distancesSokoban[c2][c1] = distance;
            }
            else
            {
                if (!distancesCrate.ContainsKey(c1))
                    distancesCrate.Add(c1, new Dictionary<Coords, int>());

                /*if (!distancesCrate.ContainsKey(c2))
                    distancesCrate.Add(c2, new Dictionary<Coords, int>());
                 //distance for crates are NOT symmetric!
                */
                if (!distancesCrate[c1].ContainsKey(c2))
                    distancesCrate[c1].Add(c2, distance);
                else distancesCrate[c1][c2] = distance;
                /*
                if (!distancesCrate[c2].ContainsKey(c1))
                    distancesCrate[c2].Add(c1, distance);
                else distancesCrate[c2][c1] = distance;
                 */
            }
        }

        protected int getDistance(Coords c1, Coords c2, bool isForSokoban)
        {
            if (isForSokoban)
            {
                if (!distancesSokoban.ContainsKey(c1) || !distancesSokoban[c1].ContainsKey(c2))
                    return limit;
                return distancesSokoban[c1][c2];
            }
            else
            {
                if (!distancesCrate.ContainsKey(c1) || !distancesCrate[c1].ContainsKey(c2))
                    return limit;
                return distancesCrate[c1][c2];
            }
        }
    }

    class distanceTester : DistanceHeuristic
    {
        public override void init(Board b)
        {
            computeDistances(b);
        }

        public override int getValue(Coords[] state)
        {
            return 0;
        }

        public int getDistance(int i, int j, int k, int l, bool isForSokoban)
        {
            return getDistance(new Coords(i, j), new Coords(k, l), isForSokoban);
        }
    }

    class SimpleDistanceHeuristic : DistanceHeuristic
    {
        Coords[] targets;
        public override void init(Board b)
        {
            computeDistances(b);
            List<Coords> targetsList = new List<Coords>();
            for (int i = 0; i < b.size.x; i++)
            {
                for (int j = 0; j < b.size.y; j++)
                {
                    if (b[i, j].state == CellState.target)
                        targetsList.Add(new Coords(i, j));
                }
            }
            targets = targetsList.ToArray();
        }

        public override int getValue(Coords[] state)
        {
            int toNearestCrate = int.MaxValue;
            for (int i = 0; i < state.Length - 1; i++)
            {
                int dist = getDistance(state[i], state[state.Length - 1], true);
                if (toNearestCrate > dist)
                    toNearestCrate = dist;
            }
            int result = toNearestCrate;
            foreach (var item in targets)
            {
                toNearestCrate = int.MaxValue;
                for (int i = 0; i < state.Length - 1; i++)
                {
                    int dist = getDistance(state[i], item, true);
                    if (toNearestCrate > dist)
                        toNearestCrate = dist;
                }
                result += toNearestCrate;
            }
            return result;
        }
    }

    class AdvancedDistanceHeuristic : DistanceHeuristic
    {
        Coords[] targets;
        Board b;
        public override void init(Board b)
        {
            this.b = b;
            computeDistances(b);
            List<Coords> targetsList = new List<Coords>();
            for (int i = 0; i < b.size.x; i++)
            {
                for (int j = 0; j < b.size.y; j++)
                {
                    if (b[i, j].state == CellState.target)
                        targetsList.Add(new Coords(i, j));
                }
            }
            targets = targetsList.ToArray();
        }

        public override int getValue(Coords[] state)
        {
            List<int> notProcessedCrates = new List<int>();
            int toNearestCrate = int.MaxValue;
            for (int i = 0; i < state.Length - 1; i++)
            {
                notProcessedCrates.Add(i);
                if (b[state[i]].state == CellState.target)
                    continue;
                int dist = getDistance(state[i], state[state.Length - 1], true);
                if (toNearestCrate > dist)
                    toNearestCrate = dist;
            }
            if (toNearestCrate == int.MaxValue) //is goal state
                return 0;
            int result = toNearestCrate;
            foreach (var item in targets)
            {
                toNearestCrate = int.MaxValue;
                int nearestCrate = -1;
                for (int i = 0; i < notProcessedCrates.Count; i++)
                {
                    int dist = getDistance(state[notProcessedCrates[i]], item, false);
                    if (toNearestCrate > dist)
                    {
                        toNearestCrate = dist;
                        nearestCrate = i;
                    }
                }
                result += toNearestCrate;
                notProcessedCrates.RemoveAt(nearestCrate);
            }
            return result;
        }
    }

    class BlindHeuristicVilda : Heuristic
    {
        Board board;
        List<Coords> targets;
        public override void init(Board b)
        {
            this.board = b;
            targets = new List<Coords>();
            
			for (int i = 0; i < b.size.x; i++)
			{
				for (int j = 0; j < b.size.y; j++)
				{
                    if(b[i,j].state == CellState.target)
                        targets.Add(new Coords(i,j));
                }
            }
        }

        public bool isTarget(Coords crate, List<Coords> targets) {
            foreach(Coords target in targets) {
                if (target.x == crate.x && target.y == crate.y)
                    return true;
            }
            return false;
        }

        private int getDistance(Coords c1, Coords c2)
        {
            return Math.Abs(c1.x-c2.x) + Math.Abs(c1.y-c2.y);
        }
        public override int getValue(Coords[] state)
        {
            int distance = 0;
            int nearestCrateDist = int.MaxValue;
            Coords sokobanPos = state.Last();
			for(int i = 0; i < state.Length-1; i++)
			{
                // Targets
                int nearestTargetDist = int.MaxValue;
                foreach(Coords target in targets) {
                    nearestTargetDist = Math.Min(nearestTargetDist, getDistance(target, state[i]));
                }
                distance += 2*nearestTargetDist;

                // Crates in corners are really bad
                if(Solver.isCorner(state[i], this.board) && !isTarget(state[i], targets)) {
                    distance += 1000;
                }

                // User to crate
                nearestCrateDist = Math.Min(nearestCrateDist, getDistance(sokobanPos, state[i]));
                // Console.WriteLine(getDistance(sokobanPos, state[i]));
            }
            // Console.WriteLine(nearestCrateDist);
            distance += 2*(nearestCrateDist-1);
            return distance;
        }
    }
    class BlindHeuristic : Heuristic
    {
        public override void init(Board b)
        {
        }

        public override int getValue(Coords[] state)
        {
            return 0;
        }
    }

	abstract class Solver
	{
		protected CellState[,] grid;
		protected int cratesCount;
		protected Board input;
		protected Heuristic h;
		protected List<Coords[]> successorPlaceHolder;
		protected List<int> successorsCostsPlaceHolder;
		protected Coords[] initialState;
		protected CoordListComparer comparer;
		private CoordsComparer orderComparer = new CoordsComparer();
		protected Dictionary<Coords[], Pair> visited;

		private List<Coords> openList;
		private List<int> g_values;
		private HashSet<Coords> closedList;


		public static List<Direction> allDirections = new Direction[] { Direction.down, Direction.up, Direction.left, Direction.right }.ToList();
		public static List<List<Direction>> allNeighbourDirections =
			new List<Direction>[] { new Direction[] { Direction.down, Direction.left}.ToList(),
				new Direction[] { Direction.left, Direction.up}.ToList(),
				new Direction[] { Direction.up, Direction.right}.ToList(),
				new Direction[] { Direction.right, Direction.down}.ToList()}.ToList();

		protected void init(Board b)
		{
			this.successorPlaceHolder = new List<Coords[]>();
			this.successorsCostsPlaceHolder = new List<int>();

			this.input = b;
			this.cratesCount = b.crates.Count;
			List<Coords> initialStateList = new List<Coords>();
			foreach (var item in b.crates)
			{
				initialStateList.Add(item.location);
			}
			initialStateList.Add(input.sokobanPos);
			this.initialState = initialStateList.ToArray();

			Coords.hashValuesTable = new int[input.size.x, input.size.y];
			Coords.accessigbleTilesCount = 0;

			grid = new CellState[input.size.x, input.size.y];
			for (int i = 0; i < input.size.x; i++)
			{
				for (int j = 0; j < input.size.y; j++)
				{
					grid[i, j] = input[i, j].state;
					if (grid[i, j] == CellState.obstacle || isCorner(new Coords(i, j), input))
					{
						Coords.hashValuesTable[i, j] = 0;
					}
					else
					{
						Coords.accessigbleTilesCount++;
						Coords.hashValuesTable[i, j] = Coords.accessigbleTilesCount;
					}
				}
			}
			comparer = new CoordListComparer();
			openList = new List<Coords>();
			closedList = new HashSet<Coords>();
			g_values = new List<int>();
			visited = new Dictionary<Coords[], Pair>(comparer);
			input.findForbidenTiles();
		}

		public void setHeuristic(Heuristic h)
		{
			this.h = h;
		}

		public static bool isCorner(Coords tile, Board input)
		{
			foreach (var item in allNeighbourDirections)
			{
				if (input[tile, item[0]].state == CellState.obstacle &&
					input[tile, item[1]].state == CellState.obstacle)
					return true;
			}
			return false;
		}

		protected bool isPromissing(Coords[] state, int crateIndex)
		{
			return true;
			if (input[state[crateIndex]].state == CellState.target)
				return true;

			if (isCorner(state[crateIndex], input))
				return false;

			if (isOnBorder(state[crateIndex], input))
			{
				bool targetFound = false;
				if (state[crateIndex].x == 0 || state[crateIndex].x == input.size.x - 1)
				{
					for (int i = 0; i < input.size.y; i++)
					{
						if (input[state[crateIndex].x, i].state == CellState.target)
						{
							targetFound = true;
							break;
						}
					}
				}

				if (state[crateIndex].y == 0 || state[crateIndex].y == input.size.y - 1)
				{
					for (int i = 0; i < input.size.x; i++)
					{
						if (input[i, state[crateIndex].y].state == CellState.target)
						{
							targetFound = true;
							break;
						}
					}
				}
				if (!targetFound)
					return false;
			}

			return true;
		}

		public static bool isOnBorder(Coords c, Board input)
		{
			return (c.x == 0 || c.y == 0 || c.x == input.size.x - 1 || c.y == input.size.y);
		}

		public static Direction getOpositeDirection(Direction dir)
		{
			switch (dir)
			{
				case Direction.down:
					return Direction.up;
				case Direction.left:
					return Direction.right;
				case Direction.right:
					return Direction.left;
				case Direction.up:
					return Direction.down;
			}
			return Direction.down;
		}

		public static Direction getTransferDirection(Coords from, Coords to)
		{
			if (to.x == from.x)
			{
				if (to.y < from.y)
					return Direction.up;
				else return Direction.down;
			}
			else
			{
				if (to.x < from.x)
					return Direction.left;
				else return Direction.right;
			}
		}

		protected bool isGoalState(Coords[] state)
		{
			for (int i = 0; i < state.Length - 1; i++)
			{
				if (grid[state[i].x, state[i].y] != CellState.target)
					return false;
			}
			return true;
		}

		protected bool canPush(Coords crate, Direction dir, Coords[] state)
		{
			if (input[crate, dir].state == CellState.obstacle)
				return false;
			Coords target = crate;
			target.change(dir);
			if (!input[target].isAccesibleToCrate)
				return false;
			for (int i = 0; i < state.Length - 1; i++)
			{
				if (state[i].Equals(target))
					return false;
			}
			return true;
		}

		protected Direction getTransferAction(Coords[] successor, Coords[] predecessor)
		{
			return getTransferDirection(predecessor[predecessor.Length - 1], successor[successor.Length - 1]);
		}

		protected List<Direction> extractSolution(Coords[] state)
		{
			List<Direction> solution = new List<Direction>();

			Coords[] currentState = state;
			while (currentState != null)
			{
				Coords[] pred = visited[currentState].state;
				if (pred != null)
					solution.Insert(0, getTransferAction(currentState, pred));
				currentState = pred;
			}

			return solution;
		}

		protected List<Direction> findPath(Coords from, Coords to, Coords[] state)
		{
			List<Direction> result = new List<Direction>();
			Dictionary<Coords, Direction> predecessoronPath = new Dictionary<Coords, Direction>();
			List<Coords> pathSearchFrontier = new List<Coords>();

			pathSearchFrontier.Add(from);
			while (pathSearchFrontier.Count > 0)
			{
				Coords c = pathSearchFrontier[0];
				pathSearchFrontier.RemoveAt(0);

				if (c.Equals(to))
					break;

				foreach (var dir in allDirections)
				{
					Coords succ = c;
					succ.change(dir);
					if (input[succ].state == CellState.obstacle || state.Contains(succ) || predecessoronPath.ContainsKey(succ))
						continue;
					predecessoronPath.Add(succ, dir);
					pathSearchFrontier.Add(succ);
				}
			}
			Coords current = to;
			while (!current.Equals(from))
			{
				result.Insert(0, predecessoronPath[current]);
				current.change(getOpositeDirection(predecessoronPath[current]));
			}

			return result;
		}

		protected List<Direction> extractSolutionAdvanced(Coords[] state)
		{
			List<Direction> solution = new List<Direction>();

			Coords[] currentState = state;
			while (currentState != null)
			{
				Coords[] pred = visited[currentState].state;
				if (pred != null)
				{
					//solution.Insert(0, getTransferAction(currentState, pred));
					//Direction d = getTransferDirection(currentState[pred.ToList().IndexOf(currentState[currentState.Length - 1])], currentState[currentState.Length - 1]);
					Direction d = getTransferDirection(currentState.Take(currentState.Length - 1).ToList().Where(p => !pred.Take(pred.Length - 1).Contains(p)).Single(), currentState[currentState.Length - 1]);
					Coords c = currentState[currentState.Length - 1];
					c.change(d);
					solution.Insert(0, getOpositeDirection(d));
					solution.InsertRange(0, findPath(pred[pred.Length - 1], c, pred));
				}
				currentState = pred;
			}

			return solution;
		}

		protected List<Coords[]> getSuccessors(Coords[] state)
		{
			successorPlaceHolder.Clear();
			successorsCostsPlaceHolder.Clear();

			foreach (var direct in allDirections)
			{
				if (input[state[cratesCount], direct].state == CellState.obstacle)
					continue;
				Coords target = state[cratesCount];
				target.change(direct);
				if (state.Contains(target)) //is push action
				{
					Coords pushTarget = target;
					pushTarget.change(direct);
					if (input[pushTarget].state == CellState.obstacle ||
						state.Contains(pushTarget) || !input[pushTarget].isAccesibleToCrate)
						continue;   //cannot push
					else
					{
						Coords[] copy = new Coords[state.Length];
						int indexOfTarget = 0;
						int indexOfChange = 0;
						for (int i = 0; i < state.Length; i++)
						{
							if (state[i].Equals(target))
							{
								indexOfTarget = i;
								copy[i] = pushTarget;
								indexOfChange = i;
							}
							else copy[i] = state[i];
						}
						//int indexOfTarget = copy.IndexOf(target);
						//copy[indexOfTarget] = pushTarget;
						if (isPromissing(copy, indexOfTarget))
						{
							copy[cratesCount] = target;
							sortState(copy, indexOfChange);
							successorPlaceHolder.Add(copy);
							successorsCostsPlaceHolder.Add(1);
						}
					}
				}
				else // is move action
				{
					Coords[] copy = new Coords[state.Length];
					for (int i = 0; i < state.Length; i++)
						copy[i] = state[i];

					copy[cratesCount] = target;
					successorPlaceHolder.Add(copy);
					successorsCostsPlaceHolder.Add(1);
				}
			}

			return successorPlaceHolder;
		}

		protected List<Coords[]> getSuccessorsAdvanced(Coords[] state)
		{
			successorPlaceHolder.Clear();
			successorsCostsPlaceHolder.Clear();
			closedList.Clear();
			//addedSuccessors.Clear();
			openList.Clear();
			openList.Add(state[state.Length - 1]);
			g_values.Add(0);
			while (openList.Count > 0)
			{
				Coords current = openList[0];
				openList.RemoveAt(0);
				int currentGVal = g_values[0];
				g_values.RemoveAt(0);

				if (closedList.Contains(current))
					continue;
				closedList.Add(current);

				foreach (var dir in allDirections)
				{
					Coords target = current;
					target.change(dir);
					if (input[target].state == CellState.obstacle)
						continue;
					bool isCrate = false;
					for (int i = 0; i < state.Length - 1; i++)
					{
						if (state[i].Equals(target))    //is crate
						{
							isCrate = true;
							if (canPush(target, dir, state))
							{
								Coords pushtarget = target;
								pushtarget.change(dir);
								/*if (isCorner(pushtarget, input) && input[pushtarget].state != CellState.target)
                                    continue;*/

								Coords[] successor = new Coords[state.Length];
								for (int g = 0; g < state.Length; g++)
									successor[g] = state[g];

								successor[i] = pushtarget;
								successor[successor.Length - 1] = target;
								sortState(successor, i);
								successorPlaceHolder.Add(successor);
								successorsCostsPlaceHolder.Add(currentGVal + 1);
							}
							break;
						}
					}
					if (!isCrate)
					{
						if (!closedList.Contains(target))
						{
							openList.Add(target);
							g_values.Add(currentGVal + 1);
						}
					}
				}
			}
			return successorPlaceHolder;
		}

		public abstract List<Direction> solve(Board b, TimeSpan maxTime);

		protected void sortState(Coords[] state, int indexOfChange)
		{
			if (Form1.useSymmetryBreaking == false)
				return;
			Coords placeholder;
			for (int i = indexOfChange; i < state.Length - 2; i++)
			{
				if (orderComparer.Compare(state[i], state[i + 1]) == 1)
				{
					placeholder = state[i + 1];
					state[i + 1] = state[i];
					state[i] = placeholder;
				}
				else break;
			}
			for (int i = indexOfChange; i > 0; i--)
			{
				if (orderComparer.Compare(state[i], state[i - 1]) == -1)
				{
					placeholder = state[i - 1];
					state[i - 1] = state[i];
					state[i] = placeholder;
				}
				else break;
			}
		}

		protected void sortState(Coords[] state)
		{
			if (Form1.useSymmetryBreaking == false)
				return;
			Array.Sort(state, 0, state.Length - 1, orderComparer);
		}

		class CoordsComparer : Comparer<Coords>
		{
			public override int Compare(Coords first, Coords second)
			{
				if (first.x < second.x)
					return -1;
				if (first.x > second.x)
					return 1;
				if (first.y < second.y)
					return -1;
				if (first.y > second.y)
					return 1;
				return 0;
			}
		}
	}

	class Astar : Solver
    {
        IHeap<int, Coords[]> openList;

        public Astar()
        {
            
        }

        public override List<Direction> solve(Board b, TimeSpan maxtime)
        {
            init(b);
            return solve(maxtime);
        }

        private new void init(Board b)
        {
            base.init(b);

            /*
            //h = new BlindHeuristic();
            //h = new SimpleDistanceHeuristic();
            h = new AdvancedDistanceHeuristic();
            //h = new WeightedHeuristic(new AdvancedDistanceHeuristic(), 10000);

             */

            h.init(b);

            //openList = new RegularBinaryHeap<Coords[]>();
			openList = new RedBlackTreeHeap<Coords[]>();
		}

        private List<Direction> solve(TimeSpan maxTime)
        {
            Console.WriteLine("Search started");
			System.Diagnostics.Stopwatch stopWatch = System.Diagnostics.Stopwatch.StartNew();

            openList.insert(0, initialState);
            visited.Add(initialState, new Pair(null, 0));
			long iterations = 0, minimalHValue = long.MaxValue, maxGValue = 0;
            double totalExpansions = 0, totalBranching = 0,
                heuristicCalls = 0, totalHeuristicValue = 0;

            while (openList.size() > 0)
            {
                iterations++;
                if (iterations % 10000 == 0)
                {
                    Console.WriteLine();
                    Console.WriteLine("Time elapsed: " + stopWatch.Elapsed.TotalSeconds + " seconds");
                    Console.WriteLine("Closed nodes: " + visited.Keys.Count);
                    Console.WriteLine("Open nodes: " + openList.size());
					Console.WriteLine("Max GValue: " + maxGValue);
					Console.WriteLine("Speed: " + visited.Count / stopWatch.Elapsed.TotalSeconds + " nodes per second");
                    Console.WriteLine("Average branching: " + totalBranching / totalExpansions);
                    Console.WriteLine("Average heuristic value: " + totalHeuristicValue / heuristicCalls);
                    Console.WriteLine("Minimal heuristic value: " + minimalHValue);
                    //Console.WriteLine("Hash code calls: " + comparer.hashCodeCalls);
                    //Console.WriteLine("Equals calls: " + comparer.equalsCalls + " (" + ((double)comparer.hashCodeCalls / comparer.equalsCalls) + " : 1)");
                    //Console.WriteLine("Hash colissions: " + comparer.colissions +  " (" + ((double)visited.Keys.Count / comparer.colissions) + " : 1)");

                    if (stopWatch.Elapsed > maxTime)
                    {
                        Console.WriteLine("Time limit expired");
                        break;
                    }
                }

                Coords[] state = openList.removeMin();
                int gVal = visited[state].gValue;
				if (gVal > maxGValue)
					maxGValue = gVal;

				if (isGoalState(state))
                {
                    Console.WriteLine();
                    Console.WriteLine("Search ended in " + stopWatch.Elapsed.TotalSeconds + " seconds");
                    Console.WriteLine("Solution length " + visited[state].gValue);
                    Console.WriteLine("Closed nodes: " + visited.Keys.Count);
                    Console.WriteLine("Open nodes: " + openList.size());
					Console.WriteLine("Max GValue: " + maxGValue);
					Console.WriteLine("Speed: " + visited.Count / stopWatch.Elapsed.TotalSeconds + " nodes per second");
                    Console.WriteLine("Average branching: " + totalBranching / totalExpansions);
                    Console.WriteLine("Average heuristic value: " + totalHeuristicValue / heuristicCalls);
                    Console.WriteLine("Minimal heuristic value: " + minimalHValue);
                    Console.WriteLine();
                    Console.WriteLine("------------------ END ------------------");
                    Console.WriteLine();
                    return Form1.useAdvancedSuccessorsGeneration ? extractSolutionAdvanced(state) : extractSolution(state);
                    //return extractSolution(state);
                }

                //successorPlaceHolder = getSuccessors(state);
                successorPlaceHolder = Form1.useAdvancedSuccessorsGeneration ? getSuccessorsAdvanced(state) : getSuccessors(state);

                totalBranching += successorPlaceHolder.Count;
                totalExpansions++;

                for (int i = 0; i < successorPlaceHolder.Count; i++)
                {
                    Coords[] succesor = successorPlaceHolder[i];
					int successorGVal = gVal + successorsCostsPlaceHolder[i];
					if (visited.ContainsKey(succesor))
					{
						if (visited[succesor].gValue <= successorGVal)
							continue;
						else
						{
							//a shorter path found to previously visited (but not expanded) node. Updating its GVal and predecessor.
							var stateInfo = visited[succesor];
							stateInfo.gValue = successorGVal;
							stateInfo.state = state;
							visited[succesor] = stateInfo;
						}
					}
					else
						visited.Add(succesor, new Pair(state, gVal + successorsCostsPlaceHolder[i]));

                    int hVal = h.getValue(succesor);
                    
                    heuristicCalls++;
                    totalHeuristicValue += hVal;
                    if (hVal < minimalHValue)
                        minimalHValue = hVal;

					openList.insert(successorGVal + hVal, succesor);
                }
            }
            Console.WriteLine("No solution found");
            return null;
        }
    }

    class EnforcedHillClimbing : Solver
    {
        private List<Coords[]> frontier;
     
        private List<Direction> solve(TimeSpan maxTime)
        {
            List<Direction> result = new List<Direction>();

            Coords[] state = initialState;
            int heuristicEstimate = h.getValue(state);
            visited.Add(state, new Pair(null, 0));

            while (!isGoalState(state))
            {
                getSuccessorsAdvanced(state);
				if (successorPlaceHolder.Count == 0)
				{
					Console.WriteLine("Dead-end reached");
					return new List<Direction>();
				}
                bool foundBetter = false;
                foreach (var succ in successorPlaceHolder)
                {
                    int succHeuristic = h.getValue(succ);
                    if (succHeuristic < heuristicEstimate)
                    {
                        visited.Add(succ, new Pair(state, 0));
                        state = succ;
                        heuristicEstimate = succHeuristic;
                        foundBetter = true;
                        //break;
                    }
                }
                if (foundBetter)
                    continue;   // hillclimbing phase

                // BFS phase
                result.AddRange(extractSolutionAdvanced(state));

                frontier.Clear();
                visited.Clear();

                frontier.Add(state);
                visited.Add(state, new Pair(null, 0));

                while (frontier.Count > 0)
                {
                    Coords[] currentState = frontier[0];
                    frontier.RemoveAt(0);
                    int hValue = h.getValue(currentState);
                    if (hValue < heuristicEstimate)
                    {
                        state = currentState;
                        heuristicEstimate = hValue;
                        result.AddRange(extractSolutionAdvanced(currentState));

                        break;
                    }

                    getSuccessorsAdvanced(currentState);
                    foreach (var item in successorPlaceHolder)
                    {
                        if (!visited.ContainsKey(item))
                            visited.Add(item, new Pair(currentState, 0));
                    }
                    if (frontier.Count == 0)
					{
						Console.WriteLine("Dead-end reached");
						return new List<Direction>();
					}
				}


            }
            result.AddRange(extractSolutionAdvanced(state));
            return result;
        }

        private new void init(Board b)
        {
            base.init(b);
            //h = new WeightedHeuristic(new AdvancedDistanceHeuristic(), 10000);
            h = new AdvancedDistanceHeuristic();
            h.init(b);
            frontier = new List<Coords[]>();
        }

        public override List<Direction> solve(Board b, TimeSpan maxTime)
        {
            init(b);
            return solve(maxTime);
        }
    }

} 
