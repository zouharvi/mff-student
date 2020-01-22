using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace TSP
{
    class TSPVisualizer
    {
        private PictureBox screen;
        private int width, height;
        private double xStretch, yStretch;        
        private Graphics g;
        private bool showNumbers = false;

        private float nodeSize = 5f;

        public void setShowNumbers(bool newValue)
        {
            showNumbers = newValue;
        }

        public TSPVisualizer(PictureBox p)
        {
            this.screen = p;
            screen.Image = new Bitmap(p.Width, p.Height);
            g = Graphics.FromImage(screen.Image);
            this.width = (int)(p.Width - nodeSize);
            this.height = (int)(p.Height - nodeSize);
        }

        private void drawNode(TSPPoint p)
        {
            if (showNumbers)
            {
                g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), 2, 2);
                g.DrawString(p.ID.ToString(), new Font("Arial", 15), Brushes.Blue, new PointF(
                    (float)(p.x * xStretch) - nodeSize, (float)(p.y * yStretch) - nodeSize));
            }
            else
            g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
            
        }

        private void fillNode(TSPPoint p, Color c)
        {
            g.FillRectangle(new SolidBrush (c), (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
            g.DrawRectangle(Pens.Black, (float)(p.x * xStretch), (float)(p.y * yStretch), nodeSize, nodeSize);
        }

        public void draw(TSPInput inp, bool clear = true)
        {
            if (clear)
                g.Clear(Color.WhiteSmoke);
            xStretch = width / (inp.maxValueX + 20);
            yStretch = height / (inp.maxValueY + 20);
            if (inp.nodesCount > 2000)
                nodeSize--;
            if (inp.nodesCount > 10000)
                nodeSize--;


            for (int i = 0; i < inp.nodesCount; i++)
            {
                var node = inp.getPoint(i);
                drawNode(node);
            }
            fillNode(inp.getPoint(0), Color.Green);
            screen.Refresh();
        }

        public void drawSpanningTree(TSPInput input, Dictionary<int, List<int>> successors)
        {
            draw(input);
            HashSet<int> done = new HashSet<int>();
            for (int i = 0; i < input.nodesCount; i++)
            {
                foreach (var item in successors[i])
                {
                    if (done.Contains(item))
                        continue;
                    TSPPoint first = input.getPoint(i), second = input.getPoint(item);
                    var p = new Pen(Brushes.Yellow, 2);
                    g.DrawLine(p, (float)(first.x * xStretch + nodeSize / 2), (float)(first.y * yStretch + nodeSize / 2),
                        (float)(second.x * xStretch + nodeSize / 2), (float)(second.y * yStretch + nodeSize / 2));
                }
                done.Add(i);
            }
            screen.Refresh();
        }

        public void draw(TSPSolution sol, bool clear = true)
        {
            draw(sol.problem, clear);
            int j = 0, previous = 0;
            for (int i = 0; i < sol.problem.nodesCount; i++)
            {
                TSPPoint first = sol.problem.getPoint(j), second = sol.problem.getPoint(sol.getSuccessor(j, previous));
                Pen pen = Pens.BlueViolet;
                for (int k = 0; k < sol.problem.nodesCount; k++)
                {
                    if (Edge.isCrossing(first, second, sol.problem.getPoint(k), sol.problem.getPoint(sol.getSuccessor(k))) &&
                        Edge.isCrossing(sol.problem.getPoint(k), sol.problem.getPoint(sol.getSuccessor(k)), first, second))
                    {
                        pen = Pens.Red;
                        break;
                    }
                }
                //TODO vybarvit cervene ty co se krizi - hotovo
                g.DrawLine(pen, (float)(first.x * xStretch + nodeSize / 2), (float)(first.y * yStretch + nodeSize / 2),
                    (float)(second.x * xStretch + nodeSize / 2), (float)(second.y * yStretch + nodeSize / 2));
                int pom = j;
                j = sol.getSuccessor(j, previous);
                previous = pom;
            }
            screen.Refresh();
        }
    }
}
