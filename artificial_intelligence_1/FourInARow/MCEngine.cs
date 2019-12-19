using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FourInARow
{
    class MCEngine : Player
    {
        private int simulationsCount;
        private Game g;
        private Dictionary<int, double> scores;
        private Dictionary<int, int> visitedCounts;
        private static Random r = new Random();

        public override int selectMove()
        {
            scores.Clear();
            visitedCounts.Clear();
            foreach (var item in g.possibleMoves)
            {
                scores.Add(item, 0);
                visitedCounts.Add(item, 0);
            }

            for (int i = 0; i < simulationsCount; i++)
            {
                Game simulGame = g.clone();
                int move = simulGame.possibleMoves[r.Next(simulGame.possibleMoves.Count)];
                simulGame.playMove(simulGame.playerToMove, move);

                while (!simulGame.hasFinished)
                {
                    simulGame.playRandomMove();
                }
                switch(simulGame.winner)
                {
                    case null:
                        scores[move] += 0.5;
                        break;
                    case true:
                        scores[move] += 1;
                        break;
                    case false: //nothing here
                        break;
                }
                visitedCounts[move]++;
            }
            double bestScore = -1;
            int bestMove = -1;
            string s = "";
            foreach (var item in scores.Keys)
            {
                double score = scores[item] / visitedCounts[item];
                s += " cislo: " + item + " score: " + score;
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = item;
                }
            }
            //MessageBox.Show(s);
            return bestMove;
        }

        public override void playMove(bool isThisPlayer, int column)
        {
            g.playMove(isThisPlayer, column);
        }

        public override string getName()
        {
            return "MC engine. " + simulationsCount + " simulations.";
        }

        public MCEngine(int simulationsCount, int sizeX, int sizeY)
        {
            this.simulationsCount = simulationsCount;
            this.visitedCounts = new Dictionary<int, int>();
            this.scores = new Dictionary<int, double>();
            this.g = new Game(sizeX, sizeY); 
        }

        public override void Reset()
        {
            g.Reset();
            this.visitedCounts = new Dictionary<int, int>();
            this.scores = new Dictionary<int, double>();
            base.Reset();
        }

        public override void handleClick(int column)
        {
            //nothing here
        }
    }
}
