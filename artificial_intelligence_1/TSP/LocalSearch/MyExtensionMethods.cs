using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalSearch
{
    public static class MyExtensionMethods
    {
        public static T ArgMin<T, Q>(this IEnumerable<T> source, Func<T, Q> criterion) where Q : IComparable<Q>
        {
            T best = source.First();
            Q bestVal = criterion(best);

            foreach (var item in source)
            {
                var val = criterion(item);
                if (val.CompareTo(bestVal) < 0)
                {
                    bestVal = val;
                    best = item;
                }
            }
            return best;
        }

        public static bool NextBool(this Random source)
        {
            return source.NextDouble() < 0.5d;
        }
    }

    public static class Combinatorics
    {
        /// <summary>
        /// Gets all variations without repetition with given <paramref name="size"/> from given <paramref name="items"/>.
        /// Variations are always generated in sorted order based on indices, i.e. first all variations that start with the first elemented are generated, then variations that starts with the second element...
        /// E.g. if items = { 1, 2, 3 } and size = 2, this returns {{1, 2}, {1, 3}, {2, 1}, {2, 3}, {3, 1}, {3, 2}}
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="items"></param>
        /// <returns></returns>
        public static IEnumerable<List<T>> GetAllVariationsNonRepeating<T>(ICollection<T> items, int size)
        {
            if (items.Count < size)
                throw new ArgumentException("There must be at least as much items in the collection as the required size of variation");


            var list = new MyLinkedList<T>(items);
            MyLinkedListNode<T>[] selectedNodes = new MyLinkedListNode<T>[size];
            T[] res = new T[size];
            int i = 0;
            while (true)
            {
                var node = list.head.next;
                for (; i < size; i++)
                {
                    selectedNodes[i] = node;
                    res[i] = node.data;
                    var prev = node;
                    node = node.next;
                    prev.Disconnect();
                }
                // .ToList() is unnececary. By ommiting this one can decrease
                // asymptotic time complexity. But array would be reused.
                yield return res.ToList();
                i = size - 1;
                while (selectedNodes[i].next == list.tail)
                {
                    selectedNodes[i].ReinsertNode();
                    i--;
                    if (i < 0) yield break;
                }
                // i je index prvniho vybraneho cisla, ktere lze zvetsit
                selectedNodes[i].ReinsertNode();
                selectedNodes[i] = selectedNodes[i].next;
                res[i] = selectedNodes[i].data;
                selectedNodes[i].Disconnect();
                i++;
            }
        }

        /// <summary>
        ///		Generates all permutations
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="items"></param>
        /// <returns></returns>
        public static IEnumerable<List<T>> GetAllPermutations<T>(IList<T> items)
        {
            bool[] wasItemUsed = items.Select(t => false).ToArray();
            return getPermutationsRecur(new List<T>(), wasItemUsed, items, 0);
        }

        /// <summary>
        ///		Generates all permutations using linked list of unused items
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="items"></param>
        /// <returns></returns>
        public static IEnumerable<List<T>> GetAllPermutations2<T>(IList<T> items)
        {
            var unusedItems = new MyLinkedList<T>(items);
            return getPermutationsRecur2(new T[items.Count], unusedItems, 0, items.Count);
        }
        private static void fillStack<T>(Stack<IEnumerator<MyLinkedListNode<T>>> stack, MyLinkedList<T> unusedItems)
        {
            while (!unusedItems.IsEmpty())
            {
                var e = unusedItems.GetEnumerator();
                e.MoveNext();
                e.Current.Disconnect();
                stack.Push(e);
            }
        }
        private static bool moveNext<T>(IEnumerator<MyLinkedListNode<T>> e)
        {
            e.Current.ReinsertNode();
            if (e.MoveNext())
            {
                e.Current.Disconnect();
                return true;
            }
            else return false;
        }

        /// <summary>
        ///		Generates all permutations using linked list of unused items. Warning each permutation is reversed.
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="items"></param>
        /// <returns></returns>
        public static IEnumerable<List<T>> GetAllPermutations3<T>(IList<T> items)
        {
            // Nastavit se na prvni permutaci
            T[] currentPermutation = items.ToArray();
            var stack = new Stack<IEnumerator<MyLinkedListNode<T>>>();
            var unusedItems = new MyLinkedList<T>(items);

            do
            {
                fillStack(stack, unusedItems);
                // Vratit permutaci
                yield return new List<T>(stack.Select(e => e.Current.data));
                // Posun na dalsi permutaci, pokud nelze, tak vypnout
                while ((stack.Count != 0) && (!moveNext(stack.Peek())))
                    stack.Pop();
            } while (stack.Count != 0);
        }

        private static IEnumerable<List<T>> getPermutationsRecur2<T>(T[] currentPermutation, MyLinkedList<T> unusedItems, int currentLength, int max)
        {
            if (currentLength == max)
            {
                yield return new List<T>(currentPermutation);
            }
            else
            {
                foreach (var item in unusedItems)
                {
                    item.Disconnect();
                    currentPermutation[currentLength] = item.data;
                    var permuteRest = getPermutationsRecur2(currentPermutation, unusedItems, currentLength + 1, max);
                    foreach (var perm in permuteRest) yield return perm;
                    item.ReinsertNode();
                }
            }
        }

        private static IEnumerable<List<T>> getPermutationsRecur<T>(List<T> currentPermutation, bool[] wasItemUsed, IList<T> allItems, int currentLength)
        {
            if (currentLength == allItems.Count)
            {
                yield return new List<T>(currentPermutation);
            }
            else
            {
                for (int i = 0; i < allItems.Count; i++)
                {
                    if (!wasItemUsed[i])
                    {
                        currentPermutation.Add(allItems[i]);
                        wasItemUsed[i] = true;
                        foreach (var item in getPermutationsRecur(currentPermutation, wasItemUsed, allItems, currentLength + 1))
                        {
                            yield return item;
                        }
                        currentPermutation.RemoveAt(currentPermutation.Count - 1);
                        wasItemUsed[i] = false;
                    }
                }
            }
        }

        /// <summary>
        /// Returns a sequence of all subsets of a set [0, 1, 2, .., <paramref name="mainSetSize"/> - 1]. If subsetMaxSize is specified, it will only return subsets with the size up to the limit, otherwise it will return all of them.
        /// Each subset is represented as a sorted list of integers.
        /// </summary>
        /// <param name="mainSetSize"></param>
        /// <param name="subsetMaxSize"></param>
        /// <param name="includeEmptySet"></param>
        /// <returns></returns>
        public static IEnumerable<List<int>> GetAllSubsets(int mainSetSize, int subsetMaxSize = -1, bool includeEmptySet = true)
        {
            var elements = Enumerable.Range(0, mainSetSize).ToList();
            var res = gatherSubsetsRecur(elements, new List<int>(), 0, subsetMaxSize < 0 ? mainSetSize : subsetMaxSize);
            if (!includeEmptySet)
                res = res.Where(x => x.Count > 0);
            return res;
        }

        /// <summary>
        /// Returns a sequence of all subsets of given (multi)set. Subset are returned as lists of elements sorted in the same order as they apear in the original set.
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="multiSet"></param>
        /// <param name="subsetMaxSize"></param>
        /// <param name="includeEmptySet"></param>
        /// <returns></returns>
        public static IEnumerable<List<T>> GetAllSubsets<T>(IList<T> multiSet, int subsetMaxSize = -1, bool includeEmptySet = true)
        {
            foreach (var item in GetAllSubsets(multiSet.Count, subsetMaxSize, includeEmptySet))
            {
                yield return item.Select(x => multiSet[x]).ToList();
            }
        }

        private static IEnumerable<List<int>> gatherSubsetsRecur(List<int> elements, List<int> selectedElements, int index, int maxSize)
        {
            if (selectedElements.Count == maxSize || index >= elements.Count)
            {
                yield return new List<int>(selectedElements);
            }
            else
            {
                selectedElements.Add(elements[index]);
                foreach (var item in gatherSubsetsRecur(elements, selectedElements, index + 1, maxSize))
                {
                    yield return item;
                }
                selectedElements.RemoveAt(selectedElements.Count - 1);
                foreach (var item in gatherSubsetsRecur(elements, selectedElements, index + 1, maxSize))
                {
                    yield return item;
                }
            }
        }

        /// <summary>
        /// Returns all combinations with repetition. Results are returned in a lexicographical order.
        /// Example: <paramref name="combinationSize"/> = 2, <paramref name="domainSize"/> = 3 returns {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}
        /// </summary>
        /// <param name="combinationSize"></param>
        /// <param name="domainSize"></param>
        /// <returns></returns>
        public static IEnumerable<int[]> GetAllCombinationsWithRepetitions(int combinationSize, int domainSize)
        {
            return enumerateCombinationsRecur(new List<int>(), 0, combinationSize, domainSize);
        }

        private static IEnumerable<int[]> enumerateCombinationsRecur(List<int> current, int index, int combSize, int domainSize)
        {
            if (index >= combSize)
                yield return current.ToArray();
            else
            {
                for (int i = 0; i < domainSize; i++)
                {
                    current.Add(i);
                    foreach (var item in enumerateCombinationsRecur(current, index + 1, combSize, domainSize))
                        yield return item;
                    current.RemoveAt(current.Count - 1);
                }
            }
        }

    }

    public class MyLinkedListNode<T>
    {
        public T data;
        public MyLinkedListNode<T> next;
        public MyLinkedListNode<T> prev;
        public MyLinkedListNode(T data, MyLinkedListNode<T> prev, MyLinkedListNode<T> next)
        {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
        public MyLinkedListNode<T> InsertAfter(T data)
        {
            var newNode = new MyLinkedListNode<T>(data, this, this.next);
            this.next.prev = newNode;
            this.next = newNode;
            return this.next;
        }
        public void ReinsertNode()
        {
            this.prev.next = this;
            this.next.prev = this;
        }
        public void Disconnect()
        {
            this.prev.next = this.next;
            this.next.prev = this.prev;
        }
    }
    public class MyLinkedListEnumerator<T> : IEnumerator<MyLinkedListNode<T>>
    {
        private MyLinkedList<T> list;
        public MyLinkedListNode<T> Current { get; protected set; }

        public MyLinkedListEnumerator(MyLinkedList<T> list)
        {
            this.Current = list.head;
            this.list = list;
        }


        object IEnumerator.Current => this.Current;

        public void Dispose()
        {

        }

        public bool MoveNext()
        {
            Current = Current.next;
            return Current != list.tail;
        }

        public void Reset()
        {
            Current = list.head;
        }
    }
    public class MyLinkedList<T> : IEnumerable<MyLinkedListNode<T>>
    {
        public MyLinkedListNode<T> head;
        public MyLinkedListNode<T> tail;
        public MyLinkedList()
        {
            this.head = new MyLinkedListNode<T>(default(T), null, null);
            this.tail = new MyLinkedListNode<T>(default(T), head, null);
            this.head.next = tail;
        }
        public MyLinkedList(IEnumerable<T> items) : this()
        {
            AddRange(items);
        }
        public override string ToString()
        {
            var sb = new StringBuilder();
            var node = head.next;
            while (node != tail)
            {
                sb.Append(node.data);
                sb.Append(" ");
                node = node.next;
            }
            return sb.ToString();
        }
        public void AddRange(IEnumerable<T> items)
        {
            var node = head;
            foreach (T item in items)
            {
                node = node.InsertAfter(item);
            }
        }

        public IEnumerator<MyLinkedListNode<T>> GetEnumerator()
        {
            return new MyLinkedListEnumerator<T>(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public bool IsEmpty() => head.next == tail;
    }


}

