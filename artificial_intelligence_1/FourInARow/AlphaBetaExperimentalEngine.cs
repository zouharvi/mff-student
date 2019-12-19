using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FourInARow
{
	class AlphaBetaExperimentalEngine : AlphaBetaEngine
	{
        int p1, p2, p3, p4;
		public AlphaBetaExperimentalEngine(int sizeX, int sizeY, int depth, bool isFirstPlayer) : base(sizeX, sizeY, depth, isFirstPlayer)
		{
            Console.WriteLine(isFirstPlayer);

            if(sizeX <= 5 && sizeY <= 5) {
                p1 = 100;
                p2 = 40;
                p3 = 10;
                p4 = 20;
            } else if(sizeX <= 9 && sizeY <= 9) {
                p1 = 100;
                p2 = 40;
                p3 = 50;
                p4 = 1;
            } else {
                if(depth <= 3) {
                    p1 = 100;
                    p2 = 20;
                    p3 = 5;
                    p4 = 10;
                } else {
                    if (!isFirstPlayer) {
                        p1 = 50;
                        p2 = 1;
                        p3 = 1;
                        p4 = 1;
                    } else {
                        p1 = 1;
                        p2 = 1;
                        p3 = 1;
                        p4 = 10;
                    }
                }
            }
		}

		protected override int eval(Game g)
		{
            int sum = 0;

            // horizontal blankets
			for(int j = 0; j < g.sizeY; j++) {
				for(int i = 0; i < g.sizeX-4; i++) {
                    int falses = 0;
                    int trues = 0;
                    for(int k = 0; k < 4; k++) {
                        if(g.board[i+k, j] == true) 
                            trues += 1;
                        if(g.board[i+k, j] == false) 
                            falses += 1;
                    }
                    if (falses != 0 && trues != 0) {
                        // nothing
                    } else {
                        sum += trues;
                        sum -= falses;
                    }
                }
            }
            // vertical blankets
			for(int j = 0; j < g.sizeY-4; j++) {
				for(int i = 0; i < g.sizeX; i++) {
                    int falses = 0;
                    int trues = 0;
                    for(int k = 0; k < 4; k++) {
                        if(g.board[i, j+k] == true) 
                            trues += 1;
                        if(g.board[i, j+k] == false) 
                            falses += 1;
                    }
                    if (falses != 0 && trues != 0) {
                        // nothing
                    } else {
                        sum += trues;
                        sum -= falses;
                    }
                }
            }
            {
            // diagonal blankets - down
			// for(int j = 0; j < g.sizeY-4; j++) {
			// 	for(int i = 0; i < g.sizeX-4; i++) {
            //         int falses = 0;
            //         int trues = 0;
            //         for(int k = 0; k < 4; k++) {
            //             if(g.board[i+k, j+k] == true) 
            //                 trues += 1;
            //             if(g.board[i+k, j+k] == false) 
            //                 falses += 1;
            //         }
            //         if (falses != 0 && trues != 0) {
            //             // nothing
            //         } else {
            //             sum += trues;
            //             sum -= falses;
            //         }
            //     }
            // }
            }
            // diagonal blankets - up
			for(int j = 4; j < g.sizeY; j++) {
				for(int i = 0; i < g.sizeX-4; i++) {
                    int falses = 0;
                    int trues = 0;
                    for(int k = 0; k < 4; k++) {
                        if(g.board[i+k, j-k] == true) 
                            trues += 1;
                        if(g.board[i+k, j-k] == false) 
                            falses += 1;
                    }
                    if (falses != 0 && trues != 0) {
                        // nothing
                    } else {
                        sum += trues;
                        sum -= falses;
                    }
                }
            }

            int[] triplets = getTripletsCount2(g);
            int[] doubles = getDoublesCount2(g);
            int[] possitionBonuses = getPositionBonuses2(g);

			// anti skip-covert
            bool[][] skipDB = {
                new bool[]{ false, true, true, true, false },
                new bool[]{ true, false, true, true, false },
                new bool[]{ false, true, true, false, true },
                new bool[]{ true, true, false, true, false },
            };

            // horizontal covert
			for(int j = 0; j < g.sizeY; j++) {
				for(int i = 0; i < g.sizeX-5; i++) {
                    foreach(var skipRule in skipDB) {
                        bool ok = true;
                        for(int k = 0; k < skipDB[0].Length; k++) {
                            if(skipRule[k] == false && g.board[i+k, j] != null) {
                                ok = false;
                                break;
                            }
                            if(skipRule[k] == true && g.board[i+k, j] != true) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) {
                            // printBoard(g);
                            // Console.WriteLine("Anti skip covert");
                            return 1000;
                        }
                    }
				}
			}

            // diagonal covert - up
            for(int j = 0; j < g.sizeY-4; j++) {
				for(int i = 0; i < g.sizeX-4; i++) {
                    foreach(var skipRule in skipDB) {
                        bool ok = true;
                        for(int k = 0; k < skipDB[0].Length; k++) {
                            if(skipRule[k] == false && g.board[i+k, j+k] != null) {
                                ok = false;
                                break;
                            }
                            if(skipRule[k] == true && g.board[i+k, j+k] != true) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) {
                            // printBoard(g);
                            // Console.WriteLine("Anti skip covert (diagonal)");
                            return 1000;
                        }
                    }
				}
			}

            // diagonal covert - down
            for(int j = 4; j < g.sizeY; j++) {
				for(int i = 0; i < g.sizeX-4; i++) {
                    foreach(var skipRule in skipDB) {
                        bool ok = true;
                        for(int k = 0; k < skipDB[0].Length; k++) {
                            if(skipRule[k] == false && g.board[i+k, j-k] != null) {
                                ok = false;
                                break;
                            }
                            if(skipRule[k] == true && g.board[i+k, j-k] != true) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) {
                            // printBoard(g);
                            // Console.WriteLine("Anti skip covert (diagonal)");
                            return 1000;
                        }
                    }
				}
			}

            return (
                (triplets[0] - triplets[1]) * p1 +
                (doubles[0] - doubles[1]) * p2 +
                (possitionBonuses[0] - possitionBonuses[1]) * p3 +
                (sum * p4)
			);
		}

		public void printBoard(Game g) {
			for(int j = 0; j < g.sizeY; j++) {
				for(int i = 0; i < g.sizeX; i++) {
					if(g.board[i, j] == true) {
						Console.Write("1");
					} else if(g.board[i, j] == false) {
						Console.Write("0");
					} else {
						Console.Write(".");
					}
				}
				Console.WriteLine();
			}
			Console.WriteLine();
		}


        public override string getName()
		{
			//zde můžete napsat jméno svého enginu
			return "Experimental " + base.getName();
		}


        public static int[] getTripletsCount2(Game g)
        {
            int[] triplets = new int[2];
            for (int s = 0; s < 2; s++)
            {
                bool side = s % 2 == 0;
                for (int i = 0; i < g.sizeX; i++)
                {
                    for (int j = 0; j < g.sizeY; j++)
                    {
                        bool hasBeenError = false;
                        for (int k = 0; k < 4; k++)
                        {
                            if (j + k >= g.sizeY || g.board[i, j + k] == !side)
                                break;
                            if (g.board[i, j + k] != side && hasBeenError)
                                break;
                            if (g.board[i, j + k] != side)
                                hasBeenError = true;
                            if (k == 3 && !hasBeenError)
                                triplets[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 4; k++)
                        {
                            if (j + k >= g.sizeY || i + k >= g.sizeX || g.board[i + k, j + k] == !side)
                                break;
                            if (g.board[i + k, j + k] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j + k] != side)
                                hasBeenError = true;
                            if (k == 3 && !hasBeenError)
                                triplets[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 4; k++)
                        {
                            if (i + k >= g.sizeX || g.board[i + k, j] == !side)
                                break;
                            if (g.board[i + k, j] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j] != side)
                                hasBeenError = true;
                            if (k == 3 && !hasBeenError)
                                triplets[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 4; k++)
                        {
                            if (j - k < 0 || i + k >= g.sizeX || g.board[i + k, j - k] == !side)
                                break;
                            if (g.board[i + k, j - k] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j - k] != side)
                                hasBeenError = true;
                            if (k == 3 && !hasBeenError)
                                triplets[side ? 0 : 1]++;
                        }
                    }
                }
            }
            return triplets;
        }


        public static int[] getPositionBonuses2(Game g)
        {
            int[] possitionBonuses = new int[2];
            int center = g.sizeX / 2;
            for (int i = 0; i < g.sizeX; i++)
            {
                possitionBonuses[0] += g.piecesPositions[true][i] * (center - Math.Abs(i - center));
                possitionBonuses[1] += g.piecesPositions[false][i] * (center - Math.Abs(i - center));
            }
            if (g.sizeX % 2 != 0)
            {
                center = g.sizeX / 2+1;
                for (int i = 0; i < g.sizeX; i++)
                {
                    possitionBonuses[0] += g.piecesPositions[true][i] * (center - Math.Abs(i - center));
                    possitionBonuses[1] += g.piecesPositions[false][i] * (center - Math.Abs(i - center));
                }
                possitionBonuses[0] /= 2;
                possitionBonuses[1] /= 2;
            }

            return possitionBonuses;
        }

		
        public static int[] getDoublesCount2(Game g)
        {
            int[] doubles = new int[2];
            for (int s = 0; s < 2; s++)
            {
                bool side = s % 2 == 0;
                for (int i = 0; i < g.sizeX; i++)
                {
                    for (int j = 0; j < g.sizeY; j++)
                    {
                        bool hasBeenError = false;
                        for (int k = 0; k < 3; k++)
                        {
                            if (j + k >= g.sizeY || g.board[i, j + k] == !side)
                                break;
                            if (g.board[i, j + k] != side && hasBeenError)
                                break;
                            if (g.board[i, j + k] != side)
                                hasBeenError = true;
                            if (k == 2 && !hasBeenError)
                                doubles[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 3; k++)
                        {
                            if (j + k >= g.sizeY || i + k >= g.sizeX || g.board[i + k, j + k] == !side)
                                break;
                            if (g.board[i + k, j + k] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j + k] != side)
                                hasBeenError = true;
                            if (k == 2 && !hasBeenError)
                                doubles[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 3; k++)
                        {
                            if (i + k >= g.sizeX || g.board[i + k, j] == !side)
                                break;
                            if (g.board[i + k, j] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j] != side)
                                hasBeenError = true;
                            if (k == 2 && !hasBeenError)
                                doubles[side ? 0 : 1]++;
                        }
                        hasBeenError = false;
                        for (int k = 0; k < 3; k++)
                        {
                            if (j - k < 0 || i + k >= g.sizeX || g.board[i + k, j - k] == !side)
                                break;
                            if (g.board[i + k, j - k] != side && hasBeenError)
                                break;
                            if (g.board[i + k, j - k] != side)
                                hasBeenError = true;
                            if (k == 2 && !hasBeenError)
                                doubles[side ? 0 : 1]++;
                        }
                    }
                }
            }
            return doubles;
        }

    }
}