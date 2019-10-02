using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Spring
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public static Random r = new Random();
        private class Node
        {
            public double x, y;
            public double dirX, dirY;
            public string name;
            public List<Node> links = new List<Node>();
            public List<Node> specLinks = new List<Node>();
            public bool visited = false;
            public Node(double x, double y, string name)
            {
                this.x = x; this.y = y;
                this.name = name;
            }

            // Random constructor
            public Node(string name)
            {
                this.x = r.NextDouble();
                this.y = r.NextDouble();
                this.name = name;
            }
        }

        private List<Node> nodes = new List<Node>();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void LoadGraph_Click(object sender, RoutedEventArgs e)
        {
            // Create OpenFileDialog 
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();

            // Set filter for file extension and default file extension 
            dlg.DefaultExt = ".txt";

            // Display OpenFileDialog by calling ShowDialog method 
            Nullable<bool> result = dlg.ShowDialog();

            // Get the selected file name and display in a TextBox 
            if (result == true)
            {
                // Open document 
                LoadGraphFromFile(dlg.FileName);
            }
        }

        private void LoadGraphFromFile(string filename)
        {
            string[] lines = System.IO.File.ReadAllLines(filename);
            int count = int.Parse(Regex.Match(lines[0], "[0-9]{1,}").Value);
            nodes = new List<Node>();
            for (int i = 0; i < count; i++)
                nodes.Add(new Node(i.ToString()));

            for (int i = 1; i < lines.Length; i++)
            {
                var match = Regex.Match(lines[i], "[0-9]{1,}");
                int a = int.Parse(match.Value);
                int b = int.Parse(match.NextMatch().Value);
                nodes[a - 1].links.Add(nodes[b - 1]);
                nodes[b - 1].links.Add(nodes[a - 1]);
            }
            RedrawGraph();
        }

        private void RedrawGraph()
        {
            canvasBoard.Children.Clear();
            SolidColorBrush greenBrush = new SolidColorBrush();
            greenBrush.Color = Color.FromArgb(255, 151, 239, 100);
            SolidColorBrush yellowBrush = new SolidColorBrush();
            yellowBrush.Color = Color.FromArgb(255, 215, 255, 114);
            SolidColorBrush orangeBrush = new SolidColorBrush();
            orangeBrush.Color = Color.FromArgb(255, 255, 216, 132);

            foreach (Node n in nodes)
            {
                
                Ellipse ellipse = new Ellipse();
                ellipse.Fill = greenBrush;
                ellipse.Width = ellipse.Height = 30;
                canvasBoard.Children.Add(ellipse);
                ellipse.SetValue(Canvas.LeftProperty, n.x * canvasBoard.Width);
                ellipse.SetValue(Canvas.TopProperty, n.y * canvasBoard.Height);
                Console.WriteLine(n.name);
                TextBlock textBlock = new TextBlock();
                textBlock.Text = n.name;
                textBlock.Foreground = new SolidColorBrush(Colors.Black);
                Canvas.SetTop(textBlock, n.y * canvasBoard.Height);
                canvasBoard.Children.Add(textBlock);
                textBlock.SetValue(Canvas.LeftProperty, n.x * canvasBoard.Width);
                textBlock.SetValue(Canvas.TopProperty, n.y * canvasBoard.Height);

                // each edge is drawn twice, but what the heck
                foreach (Node t in n.links)
                {
                    Line line = new Line();
                    line.Stroke = yellowBrush;
                    line.X1 = n.x * canvasBoard.Width + 15;
                    line.Y1 = n.y * canvasBoard.Height + 15;
                    line.X2 = t.x * canvasBoard.Width + 15;
                    line.Y2 = t.y * canvasBoard.Height + 15;

                    line.StrokeThickness = 2;
                    canvasBoard.Children.Add(line);

                }
                foreach (Node t in n.specLinks)
                {
                    Line line = new Line();
                    line.Stroke = orangeBrush;
                    line.X1 = n.x * canvasBoard.Width + 15;
                    line.Y1 = n.y * canvasBoard.Height + 15;
                    line.X2 = t.x * canvasBoard.Width + 15;
                    line.Y2 = t.y * canvasBoard.Height + 15;

                    line.StrokeThickness = 2;
                    canvasBoard.Children.Add(line);

                }
            }
        }

        private double Dist(Node a, Node b)
        {
            return Math.Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        }


        private const double DAMPENER = 30.0;
        private void SimulationStep()
        {
            foreach (Node n in nodes)
            {
                n.dirX = 0;
                n.dirY = 0;
                foreach(Node t in n.links)
                {
                    if(Dist(n, t) > 0.2)
                    {
                        n.dirX -= (n.x - t.x)/ DAMPENER;
                        n.dirY -= (n.y - t.y) / DAMPENER;
                    } else
                    {
                        n.dirX += (n.x - t.x) / DAMPENER;
                        n.dirY += (n.y - t.y) / DAMPENER;
                    }
                }
            }

            foreach (Node n in nodes)
            {
                n.x += n.dirX;
                n.y += n.dirY;
                if (n.x > 0.9) n.x = 0.9;
                if (n.x < 0.1) n.x = 0.1;
                if (n.y > 0.9) n.y = 0.9;
                if (n.y < 0.1) n.y = 0.1;
            }
        }

        private void SimStep_Click(object sender, RoutedEventArgs e)
        {
            SimulationStep();
            RedrawGraph();
        }

        private void DFS(Node a)
        {
            if (a.visited)
                return;
            a.visited = true; 
           
            foreach (Node t in a.links)
            {
                if(!t.visited)
                {
                    a.specLinks.Add(t);
                    t.specLinks.Add(a);
                    DFS(t);
                }
            }
        }

        private void SpanningTree_Click(object sender, RoutedEventArgs e)
        {
            foreach(Node n in nodes)
                DFS(n);
            RedrawGraph();
        }
    }
}
