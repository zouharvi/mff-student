using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FourInARow
{
    class Action
    {
        public int number;
        public bool player;

        public Action(int number, bool player)
        {
            this.number = number;
            this.player = player;
        }
    }

    class MCTSTreeNode
    {
        public static readonly double desiredBias = 0.9;
        private static readonly int minSuccesorPruningLimit = 4, minVisitedPruningLimit = 50;
        private static double realBias = 0.2;
        public static int visitedBeforeExpansion = 10;
        private static double minScore = 1, maxScore = 0;
        private MCTSTreeNode parrent;
        public List<MCTSTreeNode> succesors;
        private bool isLeaf, isFinished = false;
        public Action action; //action that leads from position represented by parrent node to this position
        public Game position;
        public double scoreSum, nVisited;
        public int subtreeSize = 0, subtreeDepth = 0;

        public void updateSubtreeDepth(int newDepth)
        {
            if (newDepth > subtreeDepth)
            {
                //desiredBias *= 1.001;
                //desiredBias *= 0.9999;
                subtreeDepth = newDepth;
                if (parrent != null)
                    parrent.updateSubtreeDepth(subtreeDepth + 1);
            }
            //else
                //desiredBias *= 1.001;
        }

        public int recalculateSubtreeSize()
        {
            if (isLeaf)
                return 1;
            int size = 0;
            foreach (var item in succesors)
            {
                size += item.recalculateSubtreeSize();
            }
            size = size + 1;
            this.subtreeSize = size;
            return size;
        }

        public void updateSubtreeSize(int additionalNodesCount)
        {
            this.subtreeSize += additionalNodesCount;
            if (this.parrent != null)
                parrent.updateSubtreeSize(additionalNodesCount);
        }

        private MCTSTreeNode(MCTSTreeNode parrent)
        {
            this.parrent = parrent;
            this.scoreSum = 0;
            this.nVisited = 1;
            succesors = new List<MCTSTreeNode>();
        }

        private MCTSTreeNode()
        {
        }

        public static MCTSTreeNode createRoot(Game position)
        {
            MCTSTreeNode node = new MCTSTreeNode();
            node.succesors = new List<MCTSTreeNode>();
            node.parrent = null;
            node.scoreSum = 0;
            node.nVisited = 1;
            node.isLeaf = true;
            node.position = position;
            return node;
        }

        public void expand()
        {
            if (isFinished)
                return;
            if (position.hasFinished)
            {
                isFinished = true;
                return;
            }
            this.isLeaf = false;
            List<Action> possibleActions = position.generatePossibleActions();
            if (possibleActions.Count == 0)
            {
                throw new Exception();
            }
            foreach (var item in possibleActions)
            {
                MCTSTreeNode succesor = createLeaf(this, item);
                succesor.position = this.position.clone();
                succesor.position.playMove(item.player, item.number);
                succesors.Add(succesor);
                if (succesor.position == null)
                {
                    throw new Exception();
                }
            }
            this.position = null;
            this.updateSubtreeSize(possibleActions.Count);
            this.updateSubtreeDepth(1);
        }

        public static MCTSTreeNode createLeaf(MCTSTreeNode parrent, Action move)
        {
            MCTSTreeNode node = new MCTSTreeNode(parrent);
            node.isLeaf = true;
            node.action = move;
            return node;
        }

        private void updateBias(double score)
        {
            //desiredBias *= 0.9999;
            if (score < minScore)
                minScore = score;
            if (score > maxScore)
                maxScore = score;
            realBias = desiredBias * (maxScore - minScore) + minScore;
        }

        public void update(double score)
        {
            this.nVisited++;
            this.scoreSum += score;
            if (this.parrent != null)
                parrent.update(score);
            else
                updateBias(score);
        }

        public double eval()
        {
            double expectation = scoreSum / nVisited;
            double urgency = realBias * Math.Sqrt(Math.Log(parrent.nVisited) / nVisited);
            return expectation + urgency;
        }

        private double getExpectation()
        {
            return scoreSum / nVisited;
        }

        public void prune()
        {
            if (nVisited < minVisitedPruningLimit)
                return;
            int worst = 0, best = 0;
            for (int i = 0; i < succesors.Count; i++)
            {
                if (succesors[i].getExpectation() < succesors[worst].getExpectation())
                    worst = i;
                if (succesors[i].getExpectation() > succesors[best].getExpectation())
                    best = i;
                succesors[i].prune();
            }
            //succesors[best].prune();
            if (succesors.Count > minSuccesorPruningLimit)
                succesors.RemoveAt(worst);
        }

        public MCTSTreeNode selectSuccesor()
        {
            if (this.isLeaf)
                return this;
            double max = -10;
            MCTSTreeNode bestSuccesor = null;
            foreach (var item in succesors)
            {
                if (item.isFinished)
                {
                    continue;
                }
                double val = item.eval();
                if (val > max)
                {
                    max = val;
                    bestSuccesor = item;
                }
            }
            if (bestSuccesor == null)
            {
                this.isFinished = true;
                bestSuccesor = succesors[0];
            }
            return bestSuccesor.selectSuccesor();
        }
    }
}
