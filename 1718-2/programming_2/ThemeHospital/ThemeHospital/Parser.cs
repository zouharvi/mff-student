using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace ThemeHospital
{
    class Parser
    {
        static string intR = "[1-9][0-9]?";
        static string cost = intR;
        static string oriented = "\\-\\-\\((" + intR + ")\\)\\-\\->";
        static string nonOriented = "\\<\\-\\-\\((" + intR + ")\\)\\-\\->";
        static string link = "(" + nonOriented + "|" + oriented + ")";
        static string nodeType = "(ENTRANCE|INFODESK|GP|EEG|SONO|XRAY|PSYCHO|TREATMENT|NODE)";
        static string id = intR;
        static string node = nodeType + "\\-" + id;
        static string topLevelLink =  "(" + node + ") " + link + " (" + node + ")\n";

        static string name = "[A-Z][a-zA-Z ]+";
        static string speedMultiplier = intR;
        static string healthProblem = "CARDIAC|PNEUMONIA|HIP\\-PAIN|NEUROTIC";
        static string topLevelPatient = "(" + name + "):(" + speedMultiplier + "):(" + healthProblem+ ")\n";
        static string topLevelNavRequest = "(" + name + "):(" + node + ")\n";

        static Node ProcessNode(string nodeIn)
        {
            int idIn = int.Parse((new Regex(nodeType + "\\-(" + id + ")")).Match(nodeIn).Groups[2].Value);
            Node.NodeType type = Enum.Parse<Node.NodeType>((new Regex(nodeType + "\\-(" + id + ")")).Match(nodeIn).Groups[1].Value);
            nodes[idIn].SetType(type);
            return nodes[idIn];
        }

        static void ProcessLink(string linkIn)
        {
            int id = int.Parse((new Regex(intR)).Match(linkIn).Value);
            Node from = ProcessNode((new Regex(topLevelLink)).Match(linkIn).Groups[1].Value);
            bool oriented = !(new Regex(nonOriented)).Match(linkIn).Success;
            int cost;
            if (!oriented)
                cost = int.Parse((new Regex(topLevelLink)).Match(linkIn).Groups[4].Value);
            else
                cost = int.Parse((new Regex(topLevelLink)).Match(linkIn).Groups[5].Value);
            Node to = ProcessNode((new Regex(topLevelLink)).Match(linkIn).Groups[6].Value);

            from.AddLink(to, cost);
            if (!oriented)
            {
                to.AddLink(from, cost);
            }
        }

        static Patient ProcessPatient(string patientIn)
        {
            int id = int.Parse((new Regex(intR)).Match(patientIn).Value);
            string name = ((new Regex(topLevelPatient)).Match(patientIn).Groups[1].Value);
            int speed = int.Parse((new Regex(topLevelPatient)).Match(patientIn).Groups[2].Value);
            Patient.HealthProblem problem;
            if (!Enum.TryParse<Patient.HealthProblem>((new Regex(topLevelPatient)).Match(patientIn).Groups[3].Value, out problem)) {
                problem = Patient.HealthProblem.HIP_PAIN;
            }
            return new Patient(id, name, speed, problem);
        }

        static NavRequest ProcessNavRequest(string requestIn)
        {
            int id = int.Parse((new Regex(intR)).Match(requestIn).Value);
            string name = ((new Regex(topLevelNavRequest)).Match(requestIn).Groups[1].Value);
            Node node = ProcessNode((new Regex(topLevelNavRequest)).Match(requestIn).Groups[2].Value);
            return new NavRequest(id, name, node);
        }

        private static Node[] nodes;

        public static HospitalGraph Parse(string input)
        {
            nodes = new Node[100];
            for (int i = 0; i < 100; i++)
                nodes[i] = new Node(i, Node.NodeType.NODE);

            Regex topLevelNodes = new Regex(topLevelLink);
            Match m = topLevelNodes.Match(input);
            while (m.Success)
            {
                ProcessLink(m.Value);
                m = m.NextMatch();
            }

            HospitalGraph graph = new HospitalGraph();
            bool[] present = new bool[100];
            for (int i = 0; i < 100; i++)
            {
                if (!present[i] && nodes[i].GetLinks().Count != 0)
                {
                    graph.nodes.Add(nodes[i]);
                    present[i] = true;
                }
                foreach(Link l in nodes[i].GetLinks())
                {
                    if(!present[l.GetTo().GetId()])
                    {
                        present[l.GetTo().GetId()] = true;
                        graph.nodes.Add(l.GetTo());
                    }
                }
            }

            Regex topLevelPatiensR = new Regex(topLevelPatient);
            var ms = topLevelPatiensR.Matches(input);
            foreach (Match match in ms)
            {
                graph.patients.Add(ProcessPatient(match.Value));
            }

            Regex topLevelNavRequestsR = new Regex(topLevelNavRequest);
            ms = topLevelNavRequestsR.Matches(input);
            foreach (Match match in ms)
            {
                graph.navRequests.Add(ProcessNavRequest(match.Value));
            }


            return graph;
        }
    }
}
