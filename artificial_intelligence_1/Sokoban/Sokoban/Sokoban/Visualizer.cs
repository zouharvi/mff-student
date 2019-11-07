using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows;
using System.Drawing;

namespace Sokoban
{
    public class Visualizer
    {
        private PictureBox screen;
        private Label seed;
        private Graphics g;
        private Point size;
        private int tileSize;
        private Board board;

        private bool showAccesibility = false, showDistances = false;

        private Color gridColor = Color.Black,
            obstacleColor = Color.Gray,
            targetColor = Color.Red,
            sokobanColor = Color.Blue,
            crateColor = Color.Brown;

        private Pen gridPen, targetPen;
        private Brush sokonabBrush, crateBrush, obstacleBrush;
        private string crateImgPath = @"../img/crate.png",
            sokobanImgPath = @"../img/sokoban.png",
            OKImgPath = @"../img/OK.png";
        private Image crateImage, sokobanImage, OKImage;
        private Coords lastClicked;

        public Visualizer(PictureBox p, Label l)
        {
            this.screen = p;
            this.seed = l;
            p.Image = new Bitmap(screen.Width, screen.Height);
            g = Graphics.FromImage(p.Image);
            this.size = new Point(screen.Width, screen.Height);
            this.showAccesibility = Form1.useDeadEndDetection;

            gridPen = new Pen(gridColor);
            targetPen = new Pen(targetColor, 2f);
            sokonabBrush = new SolidBrush(sokobanColor);
            crateBrush = new SolidBrush(crateColor);
            obstacleBrush = new SolidBrush(obstacleColor);
            crateImage = Image.FromFile(crateImgPath);
            sokobanImage = Image.FromFile(sokobanImgPath);
            OKImage = Image.FromFile(OKImgPath);
        }

        public Coords getCoordinatesOfLastClick()
        {
            return lastClicked;
        }

        public void visualize(Board b)
        {
			if (b == null)
				return;

            if (showAccesibility)
                b.findForbidenTiles();

            this.board = b;
            tileSize = Math.Min(size.X / b.size.x, size.Y / b.size.y) - 1;
            g.Clear(Color.BlanchedAlmond);

            drawGrid();
            drawObstaclesAndTargets();
            drawCrates();
            drawSokoban();
            if (showDistances)
                testDistances(false);

            screen.Refresh();
            if (seed != null)
                seed.Text = b.randomSeed.ToString();
        }

        private void testDistances(bool isForSokoban)
        {
            distanceTester dt = new distanceTester();
            dt.init(board);
            Random r = new Random();
            int x = r.Next(board.size.x),
                y = r.Next(board.size.y);

            for (int i = 0; i < board.size.x; i++)
                for (int j = 0; j < board.size.y; j++)
                    if (board[i, j].state != CellState.obstacle)
                        g.DrawString(dt.getDistance(x, y, i, j, isForSokoban).ToString(), new Font("Arial", 5), Brushes.Black, tileSize * i + 1, tileSize * j + 1);
        }

        private void drawGrid()
        {
            for (int i = 0; i < board.size.x + 1; i++)
            {
                g.DrawLine(gridPen, tileSize * i, 0, tileSize * i, tileSize * board.size.y);
            }
            for (int i = 0; i < board.size.y + 1; i++)
            {
                g.DrawLine(gridPen, 0, tileSize * i, tileSize * board.size.x, tileSize * i);
            }
        }

        private void drawObstaclesAndTargets()
        {
            for (int i = 0; i < board.size.x; i++)
                for (int j = 0; j < board.size.y; j++)
                {
                    if (showAccesibility && !board[i, j].isAccesibleToCrate)
                        g.FillRectangle(Brushes.LightPink, tileSize * i + 1, tileSize * j + 1, tileSize - 2, tileSize - 2);

                    if (board[i, j].state == CellState.obstacle)
                        g.FillRectangle(obstacleBrush, tileSize * i + 1, tileSize * j + 1, tileSize - 2, tileSize - 2);

                    if (board[i, j].state == CellState.target)
                    {
                        g.DrawLine(targetPen, tileSize * i + 1, tileSize * j + 1, tileSize * (i + 1) - 1, tileSize * (j + 1) - 1);
                        g.DrawLine(targetPen, tileSize * (i + 1) - 1, tileSize * j + 1, tileSize * i + 1, tileSize * (j + 1) - 1);
                    }
                }
        }

        private void drawCrates()
        {
            foreach (var item in board.crates)
            {
                g.DrawImage(crateImage, tileSize * item.location.x + 3, tileSize * item.location.y + 3, tileSize - 4, tileSize - 4);
                //g.FillEllipse(crateBrush, tileSize * item.location.x + 1, tileSize * item.location.y + 1, tileSize - 2, tileSize - 2);
                if (board[item.location].state == CellState.target)
                    g.DrawImage(OKImage, tileSize * item.location.x + 3, tileSize * item.location.y + 3, tileSize - 4, tileSize - 4);
            }
        }

        private void drawSokoban()
        {
            g.DrawImage(sokobanImage, tileSize * board.sokobanPos.x + 1, tileSize * board.sokobanPos.y + 1, tileSize - 2, tileSize - 2);
            //g.FillEllipse(sokonabBrush, tileSize * board.sokobanPos.x + 1, tileSize * board.sokobanPos.y + 1, tileSize - 2, tileSize - 2);
        }


        public void handleClick(object sender, MouseEventArgs e)
        {
            if (e.X <= this.size.X && e.Y <= this.size.Y)
            {
                lastClicked.x = (byte)(e.X / tileSize);
                lastClicked.y = (byte)(e.Y / tileSize);
            }
            else lastClicked.x = byte.MaxValue;
        }
    }
}
