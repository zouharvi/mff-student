using System;
using System.Collections.Generic;

namespace strongly_connected_components
{
    class Program
    {
        class Node
        {
            public static List<Node> all = new List<Node>();
            public static void SetAllFlags(int flag)
            {
                foreach (Node n in all)
                    n.flag = flag;
            }
            public static void AddEdge(int i, int j)
            {
                all[i - 1].neighbours.Add(j - 1);
            }

            public List<int> neighbours = new List<int>();
            public int index;
            public int flag;
            public Node(int index)
            {
                all.Add(this);
                this.index = index;
            }
        }

        static void VisitNode(Node curr, ref Stack<int> afterVisit)
        {
            curr.flag = 1;
            foreach (int i in curr.neighbours)
                if (Node.all[i].flag == 0) VisitNode(Node.all[i], ref afterVisit);
            afterVisit.Push(curr.index);
        }

        static void Main(string[] args)
        {
            for(int i = 1; i <= 10; i++)
                new Node(i);
            Node.SetAllFlags(0);

            Node.AddEdge(1, 10);
            Node.AddEdge(1, 6);
            Node.AddEdge(2, 1);
            Node.AddEdge(2, 3);
            Node.AddEdge(3, 10);
            Node.AddEdge(3, 5);
            Node.AddEdge(3, 4);
            Node.AddEdge(4, 5);
            Node.AddEdge(5, 3);
            Node.AddEdge(5, 3);
            Node.AddEdge(6, 5);
            Node.AddEdge(6, 7);
            Node.AddEdge(7, 1);
            Node.AddEdge(8, 7);
            Node.AddEdge(8, 9);
            Node.AddEdge(9, 8);
            Node.AddEdge(10, 5);


            // PART 1: make a stack of last elements
            Stack<int> afterVisit  = new Stack<int>();
            for(int j = 0; j < 10; j++)
            {
                if(Node.all[j].flag == 0)
                {
                    VisitNode(Node.all[j], ref afterVisit);
                }
            }

            Console.WriteLine("DFS order: ");
            foreach(int i in afterVisit)
                Console.Write("{0} ", i);
            Console.WriteLine();

            // PART 2: 
            // flip orientation
            List<Node> nodes = new List<Node>();
            for (int i = 1; i <= 10; i++)
                nodes.Add(new Node(i));

            for (int j = 0; j < 10; j++)
            {
                foreach (int i in Node.all[j].neighbours)
                    nodes[i].neighbours.Add(j);
            }
            Node.all = nodes;
            Node.SetAllFlags(0);

            // PART 3&4: last DFS
            Console.WriteLine("\nComponents: ");
            while (afterVisit.Count != 0)
            {
                Node curr = Node.all[afterVisit.Pop()-1];

                if (curr.flag == 0)
                {
                    Console.Write("(");
                    Stack<int> component = new Stack<int>();
                    VisitNode(curr, ref component);
                    while (component.Count != 0)
                        Console.Write("{0}"+(component.Count==1?"":", "), component.Pop());
                    Console.Write(")");
                }
            }
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}
