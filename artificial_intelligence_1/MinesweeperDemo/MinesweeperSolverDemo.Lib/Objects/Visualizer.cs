using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MinesweeperSolverDemo.Lib.Objects
{

    public partial class Visualizer : Form
    {
        private PictureBox box;
        private int tileSize, sizeX, sizeY;
        private Graphics g;
        private Pen blackPen = Pens.Black;
        private Brush mine = Brushes.Red;
        private Color empty = Color.Gray;
        private Font font;
        private Dictionary<int, Brush> brushes;
        GraphicalBoard board;

        public void setBoard(GraphicalBoard b)
        {
            this.board = b;
            sizeX = board.Width;
            sizeY = board.Height;
            this.tileSize = (int)Math.Min(box.Width / (double)sizeX, box.Height / (double)sizeY);
            font = new Font("Arial", tileSize * 0.6f);
        }

        public void refresh()
        {
            box.Refresh();
        }

        public void visualize(List<Panel> Panels)
        {
            g.Clear(empty);
            foreach (var item in Panels)
            {
                int i = item.X - 1, j = item.Y - 1;

                g.DrawRectangle(blackPen, i * tileSize, j * tileSize, tileSize, tileSize);
                if (item.IsRevealed)
                {
                    if (item.IsMine)
                        g.FillRectangle(Brushes.Red, i * tileSize, j * tileSize, tileSize, tileSize);
                    else
                    {
                        g.FillRectangle(Brushes.White, i * tileSize + 1, j * tileSize + 1, tileSize - 1, tileSize - 1);
                        if (item.AdjacentMines == 0)
                            continue;
                        g.DrawString(item.AdjacentMines.ToString(), font,
                            brushes[item.AdjacentMines], new PointF(i * tileSize + 2, j * tileSize + 2));
                    }
                }
                if (item.IsFlagged)
                {
                    g.FillRectangle(Brushes.White, i * tileSize + 1, j * tileSize + 1, tileSize - 1, tileSize - 1);
                    g.DrawEllipse(Pens.Black, i * tileSize + 2, j * tileSize + 2,
                        tileSize - 2, tileSize - 2);
                    g.DrawString("X", font, Brushes.Red,
                        new PointF(i * tileSize + 2, j * tileSize + 2));
                }

            }
            box.Invoke(new MethodInvoker(refresh));
        }

        public Visualizer()
        {
            InitializeComponent();
            this.box = pictureBox1;
            box.Image = new Bitmap(box.Width, box.Height);
            g = Graphics.FromImage(box.Image);

            brushes = new Dictionary<int, Brush>();
            brushes.Add(0, Brushes.Gray);
            brushes.Add(1, Brushes.Blue);
            brushes.Add(2, Brushes.Green);
            brushes.Add(3, Brushes.Red);
            brushes.Add(4, Brushes.Orange);
            brushes.Add(5, Brushes.Gold);
            brushes.Add(6, Brushes.LightBlue);
            brushes.Add(7, Brushes.LightGreen);
            brushes.Add(8, Brushes.Purple);
        }
    }
}
