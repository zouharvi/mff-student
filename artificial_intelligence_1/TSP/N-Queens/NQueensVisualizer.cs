using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;


namespace N_Queens
{
    class NQueensVisualizer
    {
        PictureBox screen;
        Graphics g;

        float tileSize;
        bool[] isError;
        Pen gridPen = Pens.Black;
        Brush errorBrush = Brushes.Red, queenBrush = Brushes.BlueViolet;

        public void Draw(NQueensCandidateSol sol)
        {
            DrawGrid(sol.problem);
            determineErrors(sol);

            for (int i = 0; i < sol.data.Length; i++)
            {
                if (isError[i])
                    g.FillRectangle(errorBrush, sol.data[i] * tileSize, i * tileSize, tileSize - 1, tileSize - 1);
                g.FillEllipse(queenBrush, sol.data[i] * tileSize, i * tileSize, tileSize - 1, tileSize - 1);
            }
            screen.Refresh();
        }

        public NQueensVisualizer(PictureBox screen)
        {
            this.screen = screen;
            screen.Image = new Bitmap(screen.Width, screen.Height);
            g = Graphics.FromImage(screen.Image);
        }

        private void determineErrors(NQueensCandidateSol sol)
        {
            isError = new bool[sol.data.Length];

            for (int i = 0; i < sol.data.Length; i++)
            {
                if (isError[i])
                    continue;
                for (int j = i + 1; j < sol.data.Length; j++)
                {
                    if (sol.data[j] == sol.data[i]) //same column
                    {
                        isError[i] = true;
                        isError[j] = true;
                    }
                    if (NQueensCandidateSol.IsSameDiagoval(i, sol.data[i], j, sol.data[j]))
                    {
                        isError[i] = true;
                        isError[j] = true;
                    }
                }
            }

        }

        public void DrawGrid(NQueensProblem p)
        {
            tileSize = Math.Min((float)screen.Width / p.boardSize, (float)screen.Height / p.boardSize);
            g.Clear(Color.WhiteSmoke);
            for (int i = 0; i <= p.boardSize; i++)
            {
                g.DrawLine(gridPen, i * tileSize, 0, i * tileSize, p.boardSize * tileSize);
                g.DrawLine(gridPen, 0, i * tileSize, p.boardSize * tileSize, i * tileSize);
            }
            screen.Refresh();
        }

    }
}
