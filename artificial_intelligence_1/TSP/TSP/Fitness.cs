using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TSP
{
    partial class TreeSolver : Form
    {
        public PictureBox treePictureBox, fitnessPictureBox;

        public TreeNode root;
        public TSPInput inp;
        public TreeEvaluator evaluator = new TreeEvaluator();
        public static Random r = new Random();
        
        public int treeDepth, leafsCount;
        public double minVal, maxVal;

        public void computeLeafs()
        {
            this.leafsCount = root.computeLeafs();
        }

        public static TreeNode buildTree(TSPInput inp, List<int> permutation = null)
        {
            TreeNode root = new TreeNode(inp);
            root.site = 0;
            if (permutation == null)
                root.createSuccessors(new HashSet<int>() { 0 }, -1);
            else
                root.createSuccessors(new HashSet<int>() { 0 }, -1, permutation);
            return root;
        }

        public void buildTree(List<int> permutation = null)
        {
            root = TreeSolver.buildTree(inp, permutation);
            this.leafsCount = root.computeLeafs();
            minVal = root.getMinimum();
            maxVal = root.getMaximum();
            treeDepth = root.getDepth();
        }

        public TreeSolver(TSPInput inp)
        {
            this.setComponents();
            this.inp = inp;
        }

        public TreeSolver()
        {
            this.setComponents();
        }

        private void setComponents()
        {
            InitializeComponent();
            this.treePictureBox = TreePictureBox;
            this.fitnessPictureBox = FitnessPictureBox;
        }

        private void searchPermutations(List<int> available, List<int> permutation)
        {

        }

        private void evalButton_Click(object sender, EventArgs e)
        {
            valueLabel.Text = evaluator.eval(this.root).ToString();
        }

        private void showPermutation(List<int> permutation)
        {
            buildTree(permutation);
            computeLeafs();
            //Length_label.Text = treeS.leafsCount.ToString();
            TreeVisualizer tviz = new TreeVisualizer(this);
            tviz.draw(root, maxVal, minVal);
            valueLabel.Text = evaluator.eval(this.root).ToString();
        }

        private void RebuildWithPermutationbutton_Click(object sender, EventArgs e)
        {
            showPermutation(createRandomPermutation(inp.nodesCount));
        }

        public static void changeToNextPermutation(List<int> permutation)
        {
            HashSet<int> available = new HashSet<int>();
            int i = permutation.Count - 1;
            //while (i > 0 && (permutation[i] < permutation[i - 1] || !available.Contains TODO - nesmi obsahovat ani nic vetsiho (permutation[i] + 1)) )
            {
                available.Add(permutation[i]);
                i--;
            }
            if (i == 0 && permutation[0] == permutation.Count - 1)
            {
                permutation = null;
                return;
            }
            available.Add(permutation[i]);
            permutation[i]++;
            available.Remove(permutation[i]);

            var f = available.ToList();
            f.Sort();

            foreach (var item in f)
            {
                i++;
                permutation[i] = item;
            }
        }

        public static List<int> createRandomPermutation(int count)
        {
            List<int> result = new List<int>(count);
            List<int> notUsed = new List<int>();
            for (int i = 1; i < count; i++)            
                notUsed.Add(i);
           
            while (notUsed.Count > 0)
            {
                int index = r.Next(notUsed.Count);
                result.Add(notUsed[index]);
                notUsed.RemoveAt(index);
            }
            //result.OrderBy(i => r.Next(2 * count));
            //result.Sort((x, y) => r.Next(2 * count));
            return result;
        }

        private void OptimalSolve_button_Click(object sender, EventArgs e)
        {
            TSPPreprocessor p = new TSPPreprocessor();
            p.findBestPermutation(this.inp);
            showPermutation(p.bestPermutation);
        }
    }

    class TreeNode
    {
        public Dictionary<int, TreeNode> successors;
        public int site, leafsCount;
        public double evaluation;
        public TreeNode parrent;
        public bool isRoot = false;

        public TSPInput input;

        public int computeLeafs()
        {
            if (this.isLeaf)
            {
                this.leafsCount = 1;
                return this.leafsCount;
            }
            int sum = 0;
            foreach (var item in successors.Values)
            {
                sum += item.computeLeafs();
            }
            this.leafsCount = sum;
            return sum;
        }

        public double getMinimum()
        {
            if (isLeaf)
                return evaluation;
            double min = double.MaxValue;
            foreach (var item in successors.Values)
            {
                double val = item.getMinimum();
                if (val < min)
                    min = val;
            }
            return min;
        }

        public double getMaximum()
        {
            if (isLeaf)
                return evaluation;
            double max = double.MinValue;
            foreach (var item in successors.Values)
            {
                double val = item.getMaximum();
                if (val > max)
                    max = val;
            }
            return max;
        }

        private TreeNode addSuccessor(int site)
        {
            TreeNode n = new TreeNode(this);
            n.site = site;
            this.successors.Add(site, n);
            return n;
        }

        private double getEvaluation()
        {
            if (!isLeaf)
                return 0;
            double sum = input.getDistance(site, 0);
            TreeNode pom = this;
            while (pom.parrent != null)
            {
                sum += input.getDistance(pom.site, pom.parrent.site);
                pom = pom.parrent;
            }
            return sum;
        }

        public void createSuccessors(HashSet<int> used, int start)
        {
            if (used.Count >= input.nodesCount)
            {
                this.evaluation = getEvaluation();
                return;
            }
            for (int i = 0; i < input.nodesCount; i++)
            {
                if (used.Contains(i))
                    continue;
                if (used.Count == input.nodesCount -1 && i <= start)
                    continue;
                used.Add(i);
                if (start < 0)
                    this.addSuccessor(i).createSuccessors(used, i);
                else
                    this.addSuccessor(i).createSuccessors(used, start);
                if (this.successors[i].successors.Count == 0 && used.Count < input.nodesCount)
                    this.removeSuccessor(i);
                
                used.Remove(i);
            }
        }

        public void createSuccessors(HashSet<int> used, int start, List<int> permutation)
        {
            if (used.Count >= input.nodesCount)
            {
                this.evaluation = getEvaluation();
                return;
            }
            foreach (var i in permutation)
            {
                if (used.Contains(i))
                    continue;
                if (used.Count == input.nodesCount - 1 && i <= start)
                    continue;
                used.Add(i);
                if (start < 0)
                    this.addSuccessor(i).createSuccessors(used, i, permutation);
                else
                    this.addSuccessor(i).createSuccessors(used, start, permutation);
                if (this.successors[i].successors.Count == 0 && used.Count < input.nodesCount)
                    this.removeSuccessor(i);

                used.Remove(i);
            }
        }

        private void removeSuccessor(int i)
        {
            this.successors.Remove(i);
        }

        public TreeNode(TSPInput input)
        {
            this.input = input;
            this.successors = new Dictionary<int, TreeNode>();
        }

        public TreeNode(TreeNode treeNode)
        {
            this.input = treeNode.input;
            this.successors = new Dictionary<int, TreeNode>();
            this.parrent = treeNode;
            
        }

        public int getDepth()
        {
            if (this.successors.Count == 0)
                return 1;
            foreach (var item in successors.Values)
            {
                return item.getDepth() + 1;
            }
            return 0;
        }

        public bool isLeaf
        {
            get
            {
                return this.successors.Count == 0;
            }
        }
    }

    class TreeVisualizer
    {
        private float nodeSize = 10;
        private PictureBox treePB, fitnessPB;
        private Graphics gTree, gFitness;
        private int width, height;
        public TreeSolver solver;
        private PointF previous;

        public void draw(TreeNode node, double max, double min)
        {
            int depth = node.getDepth();
            gTree.Clear(Color.White);
            gFitness.Clear(Color.White);
            drawNodes(node, 0, width, 0, (height / 1.5f) / depth, PointF.Empty);
            previous = PointF.Empty;
            drawValues(node, 0, width, max, min);

            treePB.Refresh();
            fitnessPB.Refresh();
        }

        private float getTransformedValue(double val, double min, double max)
        {
            return (float)((max - val) * (fitnessPB.Height - 20) / (max - min) + 10);
        }

        private void drawValues(TreeNode node, float leftBound, float rightBound, double maxVal, double minVal)
        {
            if (node.isLeaf)
            {
                float v = getTransformedValue(node.evaluation, minVal, maxVal);
                gFitness.DrawLine(Pens.Green, leftBound, v, rightBound, v);
                if (!previous.IsEmpty)
                    gFitness.DrawLine(Pens.Blue, new PointF((rightBound + leftBound) / 2, v), previous);
                previous = new PointF((rightBound + leftBound) / 2, v);
                return;
            }
            float start = leftBound;
            foreach (var item in node.successors.Values)
            {
                float newSize = item.leafsCount * (rightBound - leftBound) / node.leafsCount;
                drawValues(item, start, start + newSize, maxVal, minVal);
                start += newSize;
            }
        }

        private void drawNodes(TreeNode node, float leftBound, float rightBound, float upperBound, float horizontalStep, PointF predecessor)
        {
            PointF loc = new PointF((leftBound + rightBound) / 2, upperBound);
            //g.DrawRectangle(Pens.Black, loc.X, loc.Y, nodeSize, nodeSize);
            
            gTree.DrawString(node.site.ToString(), new Font("Arial", 10), Brushes.Blue, loc);
            if (node.isLeaf)
            {
                gTree.DrawString(((int)Math.Floor(node.evaluation)).ToString(), new Font("Arial", 10), Brushes.Blue, loc.X, loc.Y + 20);//loc.X/width * (height/2));
            }

            if (!predecessor.IsEmpty)
                gTree.DrawLine(Pens.Black, predecessor, loc);

            float start = leftBound;
            foreach (var item in node.successors.Values)
            {
                float newSize = item.leafsCount * (rightBound - leftBound) / node.leafsCount;
                drawNodes(item, start, start + newSize, upperBound + horizontalStep, horizontalStep, loc);
                start += newSize;
            }
        }

        public TreeVisualizer(TreeSolver s)
        {
            this.solver = s;
            this.treePB = s.treePictureBox;
            this.fitnessPB = s.fitnessPictureBox;

            this.width = treePB.Width;
            this.height = treePB.Height;
            this.treePB.Image = new Bitmap(width, height);
            gTree = Graphics.FromImage(treePB.Image);

            this.fitnessPB.Image = new Bitmap(fitnessPB.Width, fitnessPB.Height);
            gFitness = Graphics.FromImage(fitnessPB.Image);

        }
    }

    class TreeEvaluator
    {
        double previousValue = -1,
            distanceSum = 0;

        int minimaCount = 0;
        bool isRising = false;

        public double eval(TreeNode root, List<int> permutation = null, bool isDistance = true)
        {
            minimaCount = 0;
            isRising = false;
            previousValue = -1;
            distanceSum = 0;

            if (permutation == null || permutation.Count == 0)
                traverse(root);
            else
                traverse(root, permutation);

            if (isDistance) return distanceSum;
            else return minimaCount;
        }

        private void traverse(TreeNode node)
        {
            if (node.isLeaf)
            {
                bool newDirectionIsRising = node.evaluation > previousValue;
                if (previousValue >= 0)
                {
                    distanceSum += Math.Abs(previousValue - node.evaluation);
                    if (!isRising && newDirectionIsRising)
                        minimaCount++;
                }
                isRising = newDirectionIsRising;
                previousValue = node.evaluation;
            }
            foreach (var item in node.successors.Values)
            {
                traverse(item);
            }
        }

        private void traverse(TreeNode node, List<int> permutation)
        {
            if (node.isLeaf )
            {
                bool newDirectionIsRising = node.evaluation > previousValue;
                if (previousValue >= 0)
                {
                    distanceSum += Math.Abs(previousValue - node.evaluation);
                    if (!isRising && newDirectionIsRising)
                        minimaCount++;
                }
                isRising = newDirectionIsRising;
                previousValue = node.evaluation;
            }
            foreach (var item in permutation)
            {
                if (node.successors.ContainsKey(item))
                    traverse(node.successors[item], permutation);
            }
        }
    }
}

