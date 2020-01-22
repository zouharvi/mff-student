using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FourInARow
{
    class Game
    {
        private Random r;

        public Dictionary<bool, Dictionary<int, int>> piecesPositions;

        public int lastMove = -1;

        public int sizeX
        {
            get;
            private set;
        }
        public int sizeY
        {
            get;
            private set;
        }

        public bool?[,] board
        {
            get;
            private set;
        }

        public bool hasFinished
        {
            get;
            private set;
        }
        public bool? winner = null;

        public bool playerToMove = true;

        private int[] freeTiles;
        public List<int> possibleMoves
        {
            get;
            private set;
        }

        public void playMove(bool isFirstPlayer, int column)
        {
            if(column < 0 || column >= sizeX)
                return;
            piecesPositions[isFirstPlayer][column]++;
            for (int i = 0; i < sizeY; i++)
            {
                if (board[column, i] == null)
                {
                    board[column, i] = isFirstPlayer;
                    freeTiles[column]--;
                    if (freeTiles[column] == 0)
                        possibleMoves.Remove(column);
                    checkFinished(column, i);
                    playerToMove = !isFirstPlayer;
                    lastMove = column;
                    return;
                }
            }
        }

        private void checkFinished(int column, int row)
        {
            if (possibleMoves.Count == 0)
            {
                hasFinished = true;
                return;
            }

            bool? side = board[column, row];
            for (int i = 0; i < sizeX; i++)
            {
                for (int j = 0; j < sizeY; j++)
                {
                    if (board[i, j] != side)
                        continue;
                    for (int k = 0; k < 4; k++)
                    {
                        if (j + k >= sizeY || board[i, j + k] != side)
                            break;
                        if (k == 3)
                        {
                            hasFinished = true;
                            winner = side;
                            return;
                        }
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        if (j + k >= sizeY || i + k >= sizeX || board[i + k, j + k] != side)
                            break;
                        if (k == 3)
                        {
                            hasFinished = true;
                            winner = side;
                            return;
                        }
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        if (i + k >= sizeX || board[i + k, j] != side)
                            break;
                        if (k == 3)
                        {
                            hasFinished = true;
                            winner = side;
                            return;
                        }
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        if (j - k < 0 || i + k >= sizeX || board[i + k, j - k] != side)
                            break;
                        if (k == 3)
                        {
                            hasFinished = true;
                            winner = side;
                            return;
                        }
                    } 
                }
            }
        }

        public List<Action> generatePossibleActions()
        {
            List<Action> result = new List<Action>();
            foreach (var item in possibleMoves)
            {
                result.Add(new Action(item, playerToMove));
            }
            return result;
        }

        public void Reset()
        {
            this.board = new bool?[sizeX, sizeY];
            this.hasFinished = false;
            freeTiles = new int[sizeX];
            possibleMoves = new List<int>();
            this.piecesPositions = new Dictionary<bool, Dictionary<int, int>>();
            this.piecesPositions[true] = new Dictionary<int, int>();
            this.piecesPositions[false] = new Dictionary<int, int>();
            for (int i = 0; i < sizeX; i++)
            {
                freeTiles[i] = sizeY;
                possibleMoves.Add(i);
                this.piecesPositions[true].Add(i, 0);
                this.piecesPositions[false].Add(i, 0);
            }
            playerToMove = true;
            winner = null;
        }

        public Game(int sizeX, int sizeY)
        {
            this.r = Program.r;
            this.sizeX = sizeX;
            this.sizeY = sizeY;
            Reset();
        }

        private bool isWinningMove(int column)
        {
            if (column < 0 || column >= sizeX)
                return false;
            for (int i = 0; i < sizeY; i++)
            {
                if (board[column, i] == null)
                {
                    board[column, i] = playerToMove;
                    checkFinished(column, i);
                    bool copy = hasFinished;
                    hasFinished = false;
                    board[column, i] = null;
                    return hasFinished;
                }
            }
            return false;
        }

        public void playRandomMove()
        {
            /*
            foreach (var item in possibleMoves)
            {
                if (isWinningMove(item))
                {
                    playMove(playerToMove, item);
                    return;
                }
            }
             */
            playMove(playerToMove, possibleMoves[r.Next(possibleMoves.Count)]);
        }

        public Game clone()
        {
            Game g = new Game(this.sizeX, sizeY);
            g.winner = this.winner;
            g.possibleMoves = new List<int>(this.possibleMoves);
            g.hasFinished = this.hasFinished;

            this.freeTiles.CopyTo(g.freeTiles, 0);

            for (int i = 0; i < sizeX; i++)
            {
                for (int j = 0; j < sizeY; j++)
                {
                    g.board[i, j] = this.board[i, j];
                }   
            }
            return g;
        }

        public void undoMove(int move)
        {
            int i = sizeY - 1; ;
            while (board[move, i] == null)
                i--;
            piecesPositions[(bool)board[move, i]][move]--;
            board[move, i] = null;
            if (freeTiles[move] == 0)
                this.possibleMoves.Insert(0, move);
            freeTiles[move]++;
            this.hasFinished = false;
            this.lastMove = -1;
            this.playerToMove = !playerToMove;
            
        }
    
    }
}























