﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FourInARow
{
    class AlphaBetaEngine : Player
    {
        private int depth;
        private Game g;
        private bool isFirstPlayer;

        public override int selectMove()
        {
            int move = checkWinningMoves();
            if (move >= 0) return move;

            List<int> moves = new List<int>(g.possibleMoves);
            int value, bestMove = -1, bestValue = (isFirstPlayer ? -2000 : 2000);
            if (isFirstPlayer)
            {
                foreach (var item in moves)
                {
                    g.playMove(true, item);
                    value = abSearchMin(depth - 1, -2000, 2000);
                    if (value > bestValue)
                    {
                        bestValue = value;
                        bestMove = item;
                    }
                    g.undoMove(item);
                }
                return bestMove;
            }
            else
            {
                foreach (var item in moves)
                {
                    g.playMove(false, item);
                    value = abSearchMax(depth - 1, -2000, 2000);
                    if (value < bestValue)
                    {
                        bestValue = value;
                        bestMove = item;
                    }
                    g.undoMove(item);
                }
                return bestMove;
            }
        }

        private int checkWinningMoves()
        {
            int result = -1;
            List<int> moves = new List<int>(g.possibleMoves);
            foreach (var item in moves)
            {
                g.playMove(true, item);
                if (g.hasFinished)
                    result = item;
                g.undoMove(item);
                if (result != -1)
                    return result;
                g.playMove(false, item);
                if (g.hasFinished)
                    result = item;
                g.undoMove(item);
                if (result != -1)
                    return result;
            }
            return result;
        }

        public static int[] getTripletsCount(Game g)
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
                            if (k == 3)
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
                            if (k == 3)
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
                            if (k == 3)
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
                            if (k == 3)
                                triplets[side ? 0 : 1]++;
                        }
                    }
                }
            }
            return triplets;
        }

        public static int[] getPositionBonuses(Game g)
        {
            int[] possitionBonuses = new int[2];
            int center = g.sizeX / 2;
            for (int i = 0; i < g.sizeX; i++)
            {
                possitionBonuses[0] += g.piecesPositions[true][i] * (center - Math.Abs(i - center));
                possitionBonuses[1] += g.piecesPositions[false][i] * (center - Math.Abs(i - center));
            }
            return possitionBonuses;
        }

        protected virtual int eval(Game g)
        {
            int[] triplets = getTripletsCount(g);
            int[] possitionBonuses = getPositionBonuses(g);

            return (triplets[0] - triplets[1]) * 100 +
                possitionBonuses[0] - possitionBonuses[1];
        }

        private int abSearchMax(int depth, int alpha, int beta)
        {
            if (g.hasFinished)
            {
                switch (g.winner)
                {
                    case true:
                        return 1000 + depth;
                    case false: 
                        return -1000 - depth;
                    case null:
                        return 0;
                }
            }

            int a = alpha;

            if (depth <= 0)
                return eval(g);

            List<int> moves = new List<int>(g.possibleMoves);
            int value, bestMove = -1, bestValue = -2000;
            foreach (var item in moves)
            {
                g.playMove(true, item);
                value = abSearchMin(depth - 1, a, beta);
                if (value > bestValue)
                {
                    bestValue = value;
                    bestMove = item;
                }
                g.undoMove(item);
                if (bestValue >= beta)
                    return bestValue;
                a = Math.Max(a, value);
            }
            return bestValue;
        }

        private int abSearchMin(int depth, int alpha, int beta)
        {
            if (g.hasFinished)
            {
                switch (g.winner)
                {
                    case true:
                        return 1000 + depth;
                    case false:
                        return -1000 - depth;
                    case null:
                        return 0;
                }
            }

            int b = beta;

            if (depth <= 0)
                return eval(g);

            List<int> moves = new List<int>(g.possibleMoves);
            int value, bestMove = -1, bestValue = 2000;
            foreach (var item in moves)
            {
                g.playMove(false, item);
                value = abSearchMax(depth - 1, alpha, b);
                if (value < bestValue)
                {
                    bestValue = value;
                    bestMove = item;
                }
                g.undoMove(item);
                if (bestValue <= alpha)
                    return bestValue;
                b = Math.Min(b, value);
            }
            return bestValue;
        }

        public override void playMove(bool isThisPlayer, int column)
        {
            g.playMove(isFirstPlayer == isThisPlayer, column);
        }
         
        public override string getName()
        {
            return "Alpha Beta engine, depth " + depth;
        }

        public override void handleClick(int column)
        {
            //nothing here
        }

        public AlphaBetaEngine(int sizeX, int sizeY, int depth, bool isFirstPlayer)
        {
            g = new Game(sizeX, sizeY);
            this.depth = depth;
            this.isFirstPlayer = isFirstPlayer;
        }

        public override void Reset()
        {
            g.Reset();
            base.Reset();
        }
    }
}