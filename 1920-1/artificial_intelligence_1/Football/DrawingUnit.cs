using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace Football
{
    class DrawingUnit
    {
        private int sizeX, sizeY;
        private Graphics g;
        private Playground p;
        private Brush b = new SolidBrush(Color.Black);
        private int margin = 20;
        private PictureBox pictureBox;
        private Label firstTeamName, secondTeamName, scoreBoard;

        public void drawPoints(List<Point> points)
        {
            foreach (Point p in points)
            {
                g.FillEllipse(b, p.X + margin, p.Y + margin, 7, 7);
            }
        }

        public DrawingUnit(PictureBox pictureBox, Playground p, Label firstName, Label secondName, Label scoreBoard)
        {
            this.pictureBox = pictureBox;
            sizeX = pictureBox.Width;
            sizeY = pictureBox.Height;
            pictureBox.Image = new Bitmap(sizeX, sizeY);
            g = Graphics.FromImage(pictureBox.Image);
            this.p = p;
            drawEmptyField();
            this.firstTeamName = firstName;
            this.secondTeamName = secondName;
            this.scoreBoard = scoreBoard;
        }

        public void showScore(TeamAI first, TeamAI second, Point score)
        {
            Font f = new Font("Arial", 15);
            firstTeamName.Text = first.getName();
            firstTeamName.ForeColor = first.getColor();
            firstTeamName.Font = f;
            secondTeamName.Text = second.getName();
            secondTeamName.ForeColor = second.getColor();
            secondTeamName.Font = f;
            scoreBoard.Text = score.X + " - " + score.Y;
            scoreBoard.Font = f;
        }

        private void drawWhiteLines()
        {
            Pen white = new Pen(Color.White);

            //boarding lines
            g.DrawLines(white, new Point[] {new Point(margin, margin), new Point(margin, p.sizeY+margin), 
                new Point(p.sizeX+margin, p.sizeY+margin),new Point(p.sizeX+margin, margin),
                new Point(margin, margin)});
            //central line
            g.DrawLine(white, p.sizeX / 2 + margin, margin, p.sizeX / 2 + margin, margin + p.sizeY);
            //central circle
            g.DrawEllipse(white, margin + p.sizeX / 2 - 90, margin + p.sizeY / 2 - 90, 180, 180);
            //left goal
            g.DrawLine(white, margin, margin + p.sizeY / 2 - p.goalSize / 2,
                margin - 15, margin + p.sizeY / 2 - p.goalSize / 2);
            g.DrawLine(white, margin - 15, margin + p.sizeY / 2 - p.goalSize / 2,
                margin - 15, margin + p.sizeY / 2 + p.goalSize / 2);
            g.DrawLine(white, margin - 15, margin + p.sizeY / 2 + p.goalSize / 2,
                margin, margin + p.sizeY / 2 + p.goalSize / 2);
            //right goal
            g.DrawLine(white, margin + p.sizeX, margin + p.sizeY / 2 - p.goalSize / 2,
                margin + p.sizeX + 15, margin + p.sizeY / 2 - p.goalSize / 2);
            g.DrawLine(white, margin + p.sizeX + 15, margin + p.sizeY / 2 - p.goalSize / 2,
                margin + p.sizeX + 15, margin + p.sizeY / 2 + p.goalSize / 2);
            g.DrawLine(white, margin + p.sizeX + 15, margin + p.sizeY / 2 + p.goalSize / 2,
                margin + p.sizeX, margin + p.sizeY / 2 + p.goalSize / 2);
            //left penalty
            g.DrawLine(white, margin, margin + p.sizeY / 2 + p.goalSize / 2 + 50,
                margin + 50, margin + p.sizeY / 2 + p.goalSize / 2 + 50);
            g.DrawLine(white, margin, margin + p.sizeY / 2 - p.goalSize / 2 - 50,
                margin + 50, margin + p.sizeY / 2 - p.goalSize / 2 - 50);
            g.DrawLine(white, margin + 50, margin + p.sizeY / 2 + p.goalSize / 2 + 50,
                margin + 50, margin + p.sizeY / 2 - p.goalSize / 2 - 50);
            //right penalty
            g.DrawLine(white, margin + p.sizeX, margin + p.sizeY / 2 + p.goalSize / 2 + 50,
                margin + p.sizeX - 50, margin + p.sizeY / 2 + p.goalSize / 2 + 50);
            g.DrawLine(white, margin + p.sizeX, margin + p.sizeY / 2 - p.goalSize / 2 - 50,
                margin + p.sizeX - 50, margin + p.sizeY / 2 - p.goalSize / 2 - 50);
            g.DrawLine(white, margin + p.sizeX - 50, margin + p.sizeY / 2 + p.goalSize / 2 + 50,
                margin + p.sizeX - 50, margin + p.sizeY / 2 - p.goalSize / 2 - 50);
        }

        private void drawEmptyField()
        {
            g.Clear(p.backColor);
            drawWhiteLines();
        }

        public void draw(List<MovingObject> objects)
        {
            drawEmptyField();
            foreach (var particle in objects)
            {
                draw(particle);
            }
            pictureBox.Refresh();
        }

        private void draw(MovingObject o)
        {
            b = new SolidBrush(o.getColor());
            g.FillEllipse(b, (float)(o.getLocation().X - o.getRadius() + margin), (float)(o.getLocation().Y - o.getRadius() + margin),
                (float)(o.getRadius() * 2), (float)(o.getRadius() * 2));
            //g.DrawString(o.data.ToString(), new Font("Arial", 10), Brushes.White, o.getLocation());
        }
    }
}
