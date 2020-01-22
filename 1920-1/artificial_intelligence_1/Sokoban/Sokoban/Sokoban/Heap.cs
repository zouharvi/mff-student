using System;
using System.Collections.Generic;
using System.Linq;

namespace Sokoban
{
	public interface IHeap<Key, Value> where Key : IComparable
    {
        void insert(Key k, Value v);
        Value getMin();
		Key getMinKey();
        Value removeMin();
        bool remove(Value v);
        bool change(Value v, Key newKey);
        int size();
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

        #endregion
    }

    public class LeftistHeap<Value> : IHeap<int, Value>
    {
        private class TreeNode<Key, TheValue> where Key : IComparable
        {
            public TheValue val { get; set; }
            public Key key { get; set; }
            public int npl { get; set; }
            public TreeNode<Key, TheValue> ancestor,
                leftSuccesor,
                rightSuccesor;

            public bool isRoot()
            {
                return this.ancestor == null;
            }

            public bool isLeaf()
            {
                return leftSuccesor == null;
            }

            public TreeNode(TheValue value, Key k, int npl)
            {
                this.val = value;
                this.key = k;
                this.npl = npl;
            }

            public override string ToString()
            {
                return "Key: " + key + " npl: " + npl;
            }
        }

        private TreeNode<int, Value> root;
        private int count;

        private int getNpl(TreeNode<int, Value> node)
        {
            if (node == null)
                return -1;
            return node.npl;
        }

        private TreeNode<int, Value> merge(TreeNode<int, Value> first, TreeNode<int, Value> second)
        {
            if (first == null)
                return second;
            if (second == null)
                return first;
            if (first.key > second.key)
                return merge(second, first);

            TreeNode<int, Value> newRight = merge(first.rightSuccesor, second);
            first.rightSuccesor = newRight;
            newRight.ancestor = first;
            if (getNpl(first.rightSuccesor) > getNpl(first.leftSuccesor))
            {
                TreeNode<int, Value> stored = first.leftSuccesor;
                first.leftSuccesor = first.rightSuccesor;
                first.rightSuccesor = stored;
            }
            first.npl = getNpl(first.rightSuccesor) + 1;

            return first;
        }

        #region IHeap<int,Value> Members

        public void insert(int k, Value v)
        {
            TreeNode<int, Value> newNode = new TreeNode<int, Value>(v, k, 0);
            root = merge(root, newNode);
            count++;
        }

        public Value getMin()
        {
            return root.val;
        }

        public Value removeMin()
        {
            Value result = root.val;
            root = merge(root.leftSuccesor, root.rightSuccesor);
            count--;
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
            return count;
        }

        public int getMinKey()
        {
            return root.key;
        }

        #endregion

        #region Constructors

        public LeftistHeap()
        {
            this.root = null;
            this.count = 0;
        }

        private LeftistHeap(TreeNode<int, Value> root, int size)
        {
            this.root = root;
            this.count = size;
        }

        #endregion Constructors

    }

    public class BinomialHeap<Value> : IHeap<int, Value>
    {
        private class TreeNode<Key, TheValue> where Key : IComparable
        {
            public TheValue val { get; set; }
            public Key key { get; set; }
            public int rank;
            public TreeNode<Key, TheValue> ancestor;
            public List<TreeNode<Key, TheValue>> succesors;

            public bool isRoot()
            {
                return this.ancestor == null;
            }

            public bool isLeaf()
            {
                return succesors.Count == 0;
            }

            public TreeNode(TheValue value, Key k, int rank)
            {
                this.val = value;
                this.key = k;
                this.rank = rank;
                this.succesors = new List<BinomialHeap<Value>.TreeNode<Key, TheValue>>();
            }

            public override string ToString()
            {
                return "Key: " + key;
            }
        }

        private int count = 0;

        private TreeNode<int, Value> join(TreeNode<int, Value> first, TreeNode<int, Value> second)
        {
            if (first.key > second.key)
                return join(second, first);
            second.ancestor = first;
            first.succesors.Add(second);
            first.rank += 1;
            return first;
        }

        private LinkedList<TreeNode<int, Value>> trees;

        private LinkedList<TreeNode<int, Value>> merge(LinkedList<TreeNode<int, Value>> first,
            LinkedList<TreeNode<int, Value>> second)
        {
            first.AddLast(second.First);
            return first;
        }

        private LinkedList<TreeNode<int, Value>> repair(List<TreeNode<int, Value>>[] list)
        {
            LinkedList<TreeNode<int, Value>> result = new LinkedList<BinomialHeap<Value>.TreeNode<int, Value>>();
            for (int i = 0; i < list.Length; i++)
            {
                while(list[i].Count > 1)
                {
                    TreeNode<int, Value> first = list[i][0];
                    TreeNode<int, Value> second = list[i][1];
                    list[i].RemoveAt(1);
                    list[i].RemoveAt(0);
                    list[i + 1].Add(join(first, second));
                }
                if (list[i].Count > 0)
                    result.AddLast(new LinkedListNode<TreeNode<int,Value>>(list[i][0]));
            }
            return result;
        }

        #region Constructors

        public BinomialHeap()
        {
            this.count = 0;
            this.trees = new LinkedList<BinomialHeap<Value>.TreeNode<int, Value>>();
        }

        #endregion Constructors

        #region IHeap<int,Value> Members

        public void insert(int k, Value v)
        {
            LinkedListNode<TreeNode<int, Value>> newnode = 
                new LinkedListNode<TreeNode<int,Value>>(new TreeNode<int, Value>(v, k, 0));
            trees.AddFirst(newnode);
            count++;
        }

        public Value getMin()
        {
            if (trees.First == null)
                return default(Value);
            TreeNode<int, Value> min = trees.First.Value;
            List<TreeNode<int, Value>>[] byRank =
                new List<BinomialHeap<Value>.TreeNode<int, Value>>[(int)Math.Log(count, 2) + 1];
            byRank.Initialize();
            foreach (TreeNode<int, Value> item in trees)
            {
                if (item.key < min.key)
                    min = item;
                byRank[item.rank].Add(item);
            }
            trees = repair(byRank);

            return min.val;
        }

        public Value removeMin()
        {
            if (trees.First == null)
                return default(Value);
            TreeNode<int, Value> min = trees.First.Value;
            List<TreeNode<int, Value>>[] byRank =
                new List<BinomialHeap<Value>.TreeNode<int, Value>>[(int)Math.Log(count, 2) + 1];
            for (int i = 0; i < byRank.Length; i++)
            {
                byRank[i] = new List<TreeNode<int, Value>>();
            }
            foreach (TreeNode<int, Value> item in trees)
            {
                if (item.key < min.key)
                    min = item;
                byRank[item.rank].Add(item);
            }
            byRank[min.rank].Remove(min);
            foreach (TreeNode<int, Value> item in min.succesors)
            {
                byRank[item.rank].Add(item);
            }
            trees = repair(byRank);
            count--;
            return min.val;
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
            return count;
        }

        public int getMinKey()
        {
            return trees.Min(a => a.key);
        }

        #endregion

    }

    public class SortedListHeap<Value> : IHeap<int, Value>
    {
        private SortedList<int, Value> items;

        #region IHeap<int,Value> Members

        public void insert(int k, Value v)
        {
            items.Add(k, v);
        }

        public Value getMin()
        {
            foreach (var item in items.Keys)
            {
                return items[item];
            }
            return default(Value);
        }

        public Value removeMin()
        {
            foreach (var item in items.Keys)
            {
                Value result = items[item];
                items.Remove(item);
                return result;
            }
            return default(Value);
        }

        public bool remove(Value v)
        {
            if (items.ContainsValue(v))
            {
                items.RemoveAt(items.IndexOfValue(v));
                return true;
            }
            return false;
        }

        public bool change(Value v, int newKey)
        {
            if (remove(v))
            {
                insert(newKey, v);
                return true;
            }
            insert(newKey, v);
            return false;
        }

        public int size()
        {
            return items.Count;
        }

        public int getMinKey()
        {
            foreach (var item in items.Keys)
            {
                return item;
            }
            return -1;
        }

        #endregion

        public SortedListHeap()
        {
            items = new SortedList<int, Value>();
        }

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
			this.structure = new Wintellect.PowerCollections.OrderedBag<Wintellect.PowerCollections.Pair<int, Value>>((a, b) => (int)(a.First - b.First));
		}
	}

	public class FibonacciHeap<TValue> : IHeap<int, TValue>
	{
		private List<Node> _root = new List<Node>();
		int _count;
		Node _min;

		public void insert(int k, TValue v)
		{
			Insert(new Node
			{
				Key = k,
				Value = v
			});
		}

		public KeyValuePair<int, TValue> Pop()
		{
			if (_min == null)
				throw new InvalidOperationException();
			var min = ExtractMin();
			return new KeyValuePair<int, TValue>(min.Key, min.Value);
		}

		void Insert(Node node)
		{
			_count++;
			_root.Add(node);
			if (_min == null)
			{
				_min = node;
			}
			else if (node.Key < _min.Key)
			{
				_min = node;
			}
		}

		Node ExtractMin()
		{
			var result = _min;
			if (result == null)
				return null;
			foreach (var child in result.Children)
			{
				child.Parent = null;
				_root.Add(child);
			}
			_root.Remove(result);
			if (_root.Count == 0)
			{
				_min = null;
			}
			else
			{
				_min = _root[0];
				Consolidate();
			}
			_count--;
			return result;
		}

		void Consolidate()
		{
			var a = new Node[UpperBound()];
			for (int i = 0; i < _root.Count; i++)
			{
				var x = _root[i];
				var d = x.Children.Count;
				while (true)
				{
					var y = a[d];
					if (y == null)
						break;
					if (x.Key > y.Key)
					{
						var t = x;
						x = y;
						y = t;
					}
					_root.Remove(y);
					i--;
					x.AddChild(y);
					y.Mark = false;
					a[d] = null;
					d++;
				}
				a[d] = x;
			}
			_min = null;
			for (int i = 0; i < a.Length; i++)
			{
				var n = a[i];
				if (n == null)
					continue;
				if (_min == null)
				{
					_root.Clear();
					_min = n;
				}
				else
				{
					if (n.Key < _min.Key)
					{
						_min = n;
					}
				}
				_root.Add(n);
			}
		}

		int UpperBound()
		{
			return (int)Math.Floor(Math.Log(_count, (1.0 + Math.Sqrt(5)) / 2.0)) + 1;
		}

		class Node
		{
			public int Key;
			public TValue Value;
			public Node Parent;
			public List<Node> Children = new List<Node>();
			public bool Mark;

			public void AddChild(Node child)
			{
				child.Parent = this;
				Children.Add(child);
			}

			public override string ToString()
			{
				return string.Format("({0},{1})", Key, Value);
			}
		}

		public int getMinKey()
		{
			if (_min == null)
				throw new InvalidOperationException();
			return _min.Key;
		}

		public TValue getMin()
		{
			if (_min == null)
				throw new InvalidOperationException();
			return _min.Value;
		}

		public TValue removeMin()
		{
			if (_min == null)
				throw new InvalidOperationException();
			var min = ExtractMin();
			return min.Value;
		}

		public bool remove(TValue v)
		{
			throw new NotImplementedException();
		}

		public bool change(TValue v, int newKey)
		{
			throw new NotImplementedException();
		}

		public int size()
		{
			return this._count;
		}

		public void clear()
		{
			_root = new List<Node>();
			_count = 0;
			_min = null;
		}

		public string getName()
		{
			return "Fibbonaci heap";
		}
	}


}
