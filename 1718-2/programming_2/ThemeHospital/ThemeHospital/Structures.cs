using System;
using System.Collections.Generic;
using System.Text;

namespace ThemeHospital
{
    public struct Node
    {
        public Node(int id, NodeType type)
        {
            this.id = id;
            this.type = type;
            links = new List<Link>();
        }
        public enum NodeType
        {
            ENTRANCE, INFODESK, GP, EEG, SONO, XRAY, PSYCHO, TREATMENT, NODE
        }
        public void SetType(NodeType type) { this.type = type; }
        private int id;
        private NodeType type;
        private List<Link> links;
        public Link AddLink(Node to, int cost)
        {
            Link l = new Link(cost, this, to);
            links.Add(l);
            return l;
        }
        public List<Link> GetLinks()
        {
            return links;
        }
        public int GetId()
        {
            return id;
        }
    }

    public struct Link
    {
        public Link(int cost, Node from, Node to)
        {
            this.cost = cost;
            this.from = from;
            this.to = to;
        }
        private int cost;
        private Node from, to;
        public Node GetTo()   { return to; }
        public Node GetFrom() { return from; }
        public int GetCost()  { return cost; }
    }

    public class Path
    {

    }

    public class NavRequest
    {
        private int id;
        private Node node;
        private string name;
        public NavRequest(int id, string name, Node node)
        {
            this.id = id;
            this.node = node;
            this.name = name;
        }
    }

    public class Patient
    {
        public enum HealthProblem
        {
            CARDIAC,PNEUMONIA,HIP_PAIN,NEUROTIC
        }

        public Patient(int id, string name, int multip, HealthProblem problem) {
            this.id = id;
            this.name = name;
            this.multip = multip;
            this.problem = problem;
        }
        
        private int id;
        private string name;
        private int multip;
        public HealthProblem problem;
        public Node entrance;
        public int GetId() { return id; }
        public string GetName() { return name; }
        public int GetSpeedMultiplier() { return multip; }
    }


    public class HospitalGraph
    {
        public List<Node> nodes = new List<Node>();
        public List<Patient> patients = new List<Patient>();
        public List<NavRequest> navRequests = new List<NavRequest>();
        public Path GetPath(Node from, Node to, Patient patient)
        {
            return null;
        }

        public List<Node> GetNodesOfType()
        {
            return null;
        }
    }
}
