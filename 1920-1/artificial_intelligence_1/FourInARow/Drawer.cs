using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace FourInARow
{
    class Drawer
    {
        #region Colors

        private Pen boardPen = new Pen(Brushes.Black, 5);
        private Brush FirstPlayer = Brushes.Red,
            SecondPlayer = Brushes.Blue;
        private Color background = Color.DarkGoldenrod;

        #endregion

        private PictureBox box;
        private Graphics g;
        private Game game;
        private int pieceSize;
        private refreshMethod rm;

        private delegate void refreshMethod();

        public Drawer(Game game, PictureBox b)
        {
            this.box = b;
            this.game = game;

            this.box.Image = new Bitmap(box.Width, box.Height);
            g = Graphics.FromImage(box.Image);
            this.pieceSize = Math.Min(box.Width / game.sizeX, box.Height / game.sizeY);
            rm += box.Refresh;
        }

        private void drawGrid()
        {
            g.DrawLine(boardPen, game.sizeX * pieceSize, 0, game.sizeX * pieceSize, game.sizeY * pieceSize);
            g.DrawLine(boardPen, 0, game.sizeY * pieceSize, game.sizeX * pieceSize, game.sizeY * pieceSize);

            for (int i = 0; i < game.sizeX; i++)
            {
                g.DrawLine(Pens.Black, i * pieceSize, 0, i * pieceSize, game.sizeY * pieceSize);
            }

            for (int i = 0; i < game.sizeY; i++)
            {
                g.DrawLine(Pens.Black, 0, i * pieceSize, game.sizeX * pieceSize, i * pieceSize);
            }
        }

        public void drawGameState()
        {
            this.pieceSize = Math.Min(box.Width / game.sizeX, box.Height / game.sizeY);
            g.Clear(background);
            int[] triplets = AlphaBetaEngine.getTripletsCount(game);
            int[] bonuses = AlphaBetaEngine.getPositionBonuses(game);
			int score = triplets[0] * 100 + bonuses[0] - triplets[1] * 100 - bonuses[1];
            drawGrid();
            g.DrawString((triplets[0] * 100 + bonuses[0]) + "\t" + (triplets[1] * 100 + bonuses[1]) + "\t" + (score > 0 ? "+" : "") + score, new Font("Arial", 12), Brushes.Black, 0, 0);
            for (int i = 0; i < game.sizeX; i++)
            {
                for (int j = 0; j < game.sizeY; j++)
                {
                    if (game.board[i, j] != null)
                    {
                        Brush b = game.board[i, j] == true ? FirstPlayer : SecondPlayer;
                        g.FillEllipse(b, i * pieceSize, (game.sizeY - j - 1) * pieceSize, pieceSize, pieceSize);
                    }
                }
            }
            for (int i = game.sizeY - 1; i >= 0; i--)
            {
                if (game.board[game.lastMove, i] != null)
                {
                    g.FillEllipse(Brushes.Black, (game.lastMove + 0.25f) * pieceSize, (game.sizeY - i - 0.75f) * pieceSize, pieceSize/2, pieceSize/2);
                    break;
                }
            }
            box.Invoke(rm);
        }

        public int handleClick(int coordX, int coordY)
        {
            return coordX / pieceSize;
        }
    }
}
