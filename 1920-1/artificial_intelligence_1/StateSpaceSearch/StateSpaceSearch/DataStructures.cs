using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StateSpaceSearch
{
    //Frontu a zasobnik najdete v System.Collections.Generic.Queue<> a System.Collections.Generic.Stack<>

    public interface IHeap<Key, Value> where Key : IComparable
    {
        void insert(Key k, Value v);
        Value getMin();
        int getMinKey();
        Value removeMin();
        bool remove(Value v);
        bool change(Value v, Key newKey);
        int size();
        void clear();
        string getName();
    }

    public class RedBlackTreeHeap<Value> : IHeap<int, Value>
    {
        Wintellect.PowerCollections.OrderedBag<Wintellect.PowerCollections.Pair<int, Value>> structure;

        public void insert(int k, Value v)
        {
            structure.Add(new Wintellect.PowerCollections.Pair<int, Value>(k, v));
        }

        public Value getMin()
        {
            throw new NotImplementedException();
        }

        public int getMinKey()
        {
            throw new NotImplementedException();
        }

        public Value removeMin()
        {
            return structure.RemoveFirst().Second;
        }

        public bool remove(Value v)
        {
            throw new NotImplementedException();
        }

        public bool change(Value v, int newKey)
        {
            throw new NotImplementedException();
        }

        public int size()
        {
            return structure.Count;
        }
        public string getName()
        {
            return "Wintelect Red-Black Tree Heap";
        }
        public void clear()
        {
            this.structure.Clear();
        }

        public RedBlackTreeHeap()
        {
            this.structure = new Wintellect.PowerCollections.OrderedBag<Wintellect.PowerCollections.Pair<int, Value>>((a, b) => a.First - b.First);
        }
    }

    public class IHeapBasic<Value> : IHeap<int, Value> {
        public virtual void insert(int k, Value v)
        {
            throw new NotImplementedException();
        }
        public virtual Value getMin()
        {
            throw new NotImplementedException();
        }
        public virtual int getMinKey()
        {
            throw new NotImplementedException();
        }
        public virtual Value removeMin()
        {
            throw new NotImplementedException();
        }
        public virtual bool remove(Value v)
        {
            throw new NotImplementedException();
        }
        public virtual bool change(Value v, int newKey)
        {
            throw new NotImplementedException();
        }
        public virtual int size()
        {
            throw new NotImplementedException();
        }
        public virtual string getName()
        {
            throw new NotImplementedException();
        }
        public virtual void clear()
        {
            throw new NotImplementedException();
        }
    }

    public class QueueFIFO<Value> : IHeapBasic<Value>
    {
        Queue<Value> structure = new Queue<Value>();

        public override void insert(int _k, Value v)
        {
            structure.Enqueue(v);
        }

        public override Value removeMin()
        {
            return structure.Dequeue();
        }

        public override int size()
        {
            return structure.Count;
        }
        public override string getName()
        {
            return "FIFO Queue";
        }
        public override void clear()
        {
            this.structure.Clear();
        }
    }

    public class StackLIFO<Value> : IHeapBasic<Value>
    {
        Stack<Value> structure = new Stack<Value>();

        public override void insert(int _k, Value v)
        {
            structure.Push(v);
        }

        public override Value removeMin()
        {
            return structure.Pop();
        }

        public override int size()
        {
            return structure.Count;
        }
        public override string getName()
        {
            return "LIFO Stack";
        }
        public override void clear()
        {
            this.structure.Clear();
        }
    }

    public class RegularBinaryHeap<Value> : IHeap<int, Value>
    {
        private class TreeNode<Key, TheValue> where Key : IComparable
        {
            public TheValue val { get; set; }
            public Key key { get; set; }
            public int index { get; set; }

            public TreeNode(TheValue value, Key k, int index)
            {
                this.val = value;
                this.key = k;
                this.index = index;
            }

            public override string ToString()
            {
                return "Key :" + key + " index:" + index;
            }
        }

        private IList<TreeNode<int, Value>> tree;

        private bool isRoot(TreeNode<int, Value> t)
        {
            return t.index == 0;
        }

        private bool isLeaf(TreeNode<int, Value> t)
        {
            return getLeftSuccesor(t) == null;
        }

        private TreeNode<int, Value> getPredecessor(TreeNode<int, Value> t)
        {
            return t.index == 0 ? null : tree[(t.index - 1) / 2];
        }

        private TreeNode<int, Value> getLeftSuccesor(TreeNode<int, Value> t)
        {
            int index = t.index * 2 + 1;
            return tree.Count > index ? tree[index] : null;
        }

        private TreeNode<int, Value> getRightSuccesor(TreeNode<int, Value> t)
        {
            int index = t.index * 2 + 2;
            return tree.Count > index ? tree[index] : null;
        }

        public bool isEmpty()
        {
            return tree.Count == 0;
        }

        private void checkUp(TreeNode<int, Value> node)
        {
            TreeNode<int, Value> current = node,
                predecessor = getPredecessor(current);
            while (!isRoot(current) && current.key < predecessor.key)
            {
                swap(current, predecessor);
                predecessor = getPredecessor(current);
            }
        }

        private void swap(TreeNode<int, Value> current, TreeNode<int, Value> predecessor)
        {
            TreeNode<int, Value> stored = tree[current.index];

            tree[current.index] = tree[predecessor.index];
            tree[predecessor.index] = stored;

            int storedIndex = current.index;
            current.index = predecessor.index;
            predecessor.index = storedIndex;
        }

        private void checkDown(TreeNode<int, Value> node)
        {
            TreeNode<int, Value> current = node,
                succesor = null,
                succesorLeft = getLeftSuccesor(current),
                succesorRight = getRightSuccesor(current);

            if (succesorLeft != null)
            {
                if (succesorRight == null)
                    succesor = succesorLeft;
                else
                    succesor = (succesorLeft.key < succesorRight.key ? succesorLeft : succesorRight);

                while (succesor.key < current.key && !isLeaf(current))
                {
                    swap(current, succesor);

                    succesorLeft = getLeftSuccesor(current);
                    succesorRight = getRightSuccesor(current);
                    if (succesorLeft != null)
                    {
                        if (succesorRight == null)
                            succesor = succesorLeft;
                        else
                            succesor = (succesorLeft.key < succesorRight.key ? succesorLeft : succesorRight);
                    }
                }
            }
        }

        public RegularBinaryHeap()
        {
            this.tree = new List<TreeNode<int, Value>>();
        }

        #region Heap<int,Value> Members

        public void insert(int k, Value v)
        {
            TreeNode<int, Value> newNode = new TreeNode<int, Value>(v, k, tree.Count);
            tree.Add(newNode);
            checkUp(newNode);
        }

        public Value getMin()
        {
            return (tree.Count > 0 ? tree[0].val : default(Value));
        }

        public Value removeMin()
        {
            Value result = tree[0].val;
            swap(tree[0], tree[tree.Count - 1]);
            tree.RemoveAt(tree.Count - 1);
            if (!isEmpty())
                checkDown(tree[0]);
            return result;
        }

        public bool remove(Value v)
        {
            throw new NotImplementedException();
        }

        public bool change(Value v, int newKey)
        {
            throw new NotImplementedException();
        }

        public int size()
        {
            return tree.Count;
        }

        public int getMinKey()
        {
            return (tree.Count > 0 ? tree[0].key : -1);
        }

        public string getName()
        {
            return "Regular binary heap";
        }
        public void clear()
        {
            this.tree = new List<TreeNode<int, Value>>();
        }

        #endregion
    }


}
