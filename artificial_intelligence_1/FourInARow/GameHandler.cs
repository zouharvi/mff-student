using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;

namespace FourInARow
{
    class GameHandler
    {
        private Player first, second;
        private Game g;
        private Drawer d;
        Task<int> playFirst, playSecond;
        PictureBox pb;

        public void Restart()
        {
            g.Reset();
            first.Reset();
            second.Reset();
        }

        public GameHandler(Player first, Player second, int sizeX, int sizeY, PictureBox box)
        {
            this.first = first;
            this.second = second;
            g = new Game(sizeX, sizeY);
            this.d = new Drawer(g, box);
            playFirst = new Task<int>(first.selectMove);
            playSecond = new Task<int>(second.selectMove);
            this.pb = box;
        }

        public void HandleResize()
        {
            d = new Drawer(g, pb);
            d.drawGameState();
        }

        public void start(System.Action finishedCallback)
        {
            while (!g.hasFinished)
            {
                playFirst = new Task<int>(first.selectMove);
                playSecond = new Task<int>(second.selectMove);

                playFirst.Start();
                    
                int move = playFirst.Result;

                if (!g.possibleMoves.Contains(move))
                    throw new Exception();

                first.playMove(true, move);
                second.playMove(false, move);
                g.playMove(true, move);
                d.drawGameState();

                if (g.hasFinished)
                {
                    showResults();
                    break;
                }

                //-----
                playSecond.Start();
                move = playSecond.Result;

                if (!g.possibleMoves.Contains(move))
                    throw new Exception();

                first.playMove(false, move);
                second.playMove(true, move);
                g.playMove(false, move);
                d.drawGameState();

                if (g.hasFinished)
                {
                    showResults();
                    break;
                }
            }
            finishedCallback();
        }

        private void showResults()
        {
            string message = "Red: " + first.getName() + "\nBlue: " + second.getName() + "\n";
                
            if (g.winner == null)
                message += "\nDraw!";
            else
                message += (g.winner == true ? "\nRed" : "\nBlue") + " wins!";

            MessageBox.Show(message, "Game over");
        }

        public void handleClick(int coordX, int coordY)
        {
            int column = d.handleClick(coordX, coordY);
            if (g.playerToMove)
                first.handleClick(column);
            else second.handleClick(column);
        }
    
    }
}
