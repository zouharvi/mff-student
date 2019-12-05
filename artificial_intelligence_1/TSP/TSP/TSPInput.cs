using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using LocalSearch;

namespace TSP
{
    [Serializable]
    class TSPPoint
    {
        #region staticMembers
        
        private static int IDCounter = 0;
        public static void resetCounter()
        {
            TSPPoint.IDCounter = 0;
        }
        public static int getID()
        {
            return IDCounter++;
        }
        
        #endregion staticMembers

        #region read-onlyData
        public double x
        {
            get;
            private set;
        }
        public double y
        {
            get;
            private set;
        }
        public int ID
        {
            get;
            private set;
        }
        #endregion privateData

        #region constructors
        
        public TSPPoint()
        {
        }
        private TSPPoint(double x, double y)
        {
            this.x = x;
            this.y = y;
            this.ID = getID();
        }
        public static TSPPoint create(double x, double y)
        {
            if (x < 0 || y < 0) throw new ArgumentOutOfRangeException();
            return new TSPPoint(x, y);
        }

        #endregion constructors

        public void renewID()
        {
            this.ID = TSPPoint.getID();
        }

        public int userData1;
        public string userData2;
    }

    [Serializable]
    class TSPInput : LocalSearchProblem
    {
        #region PrivateData
        
        private List<TSPPoint> points;
        private List<List<double>> distances;    //distances of points indexed by their positions in "points"
        private Dictionary<int, int> position; // positions of the points in "points" indexed by their IDs

        #endregion

        #region constructorsAndFactories

        private TSPInput()
        {
            TSPPoint.resetCounter();
            this.distances = new List<List<double>>();
            this.points = new List<TSPPoint>();
            this.position = new Dictionary<int, int>();
        }

        public static TSPInput create()
        {
            return new TSPInput();
        }

        public static TSPInput create(string file)
        {
            return TSPInput.load(file);
        }

        #endregion constructorsAndFactories

        #region serializationMethods

        public void save(string file)
        {
            IFormatter formatter = new BinaryFormatter();
            Stream stream = new FileStream(file, FileMode.Create);
            formatter.Serialize(stream, this);
            stream.Close();
        }
        private static TSPInput load(string file)
        {
            IFormatter formatter = new BinaryFormatter();
            Stream stream = new FileStream(file, FileMode.Open);
            TSPInput t = (TSPInput)formatter.Deserialize(stream);
            stream.Close();
            return t;
        }
        private void recalculateID()
        {
            this.position.Clear();
            for (int i = 0; i < points.Count; i++)
            {
                points[i].renewID();
                position.Add(points[i].ID, i);
            }
        }

        #endregion serializationMethods

        #region ExportToPlanningSAS
        
        private void saveSASFile(string file)
        {
            using (var writer = new System.IO.StreamWriter(file))
            {
                writer.WriteLine("begin_version");
                writer.WriteLine("3");
                writer.WriteLine("end_version");

                writer.WriteLine("begin_metric");
                writer.WriteLine("1");
                writer.WriteLine("end_metric");

                //number of variables = number of sites + 1
                writer.WriteLine(this.points.Count + 1);

                //first variable = position of the salesman. domain size = number of sites
                writer.WriteLine("begin_variable");
                writer.WriteLine("positionOfSalesman");
                writer.WriteLine("-1"); //axiom layer is not used
                writer.WriteLine(this.points.Count); //domain size
                for (int i = 0; i < this.points.Count; i++)
                     writer.WriteLine("salesman at site" + i); //menaings of values              
                writer.WriteLine("end_variable");
            
                //next variables = which sites were visited

                for (int i = 0; i < this.points.Count; i++)
                {
                    writer.WriteLine("begin_variable");
                    writer.WriteLine("visitedSite" + i);
                    writer.WriteLine("-1"); //axiom layer is not used
                    writer.WriteLine("2"); //domain size is 2 - true or false
                    writer.WriteLine("site" + i + " was not visited"); //menaings of values
                    writer.WriteLine("site" + i + " was visited"); //menaings of values 
                    writer.WriteLine("end_variable");
                }

                writer.WriteLine("0"); //no mutex groups

                //initial state
                writer.WriteLine("begin_state");
                for (int i = 0; i < this.points.Count + 1; i++)
                    writer.WriteLine("0"); // all variables are initialy 0 - salesman is in location 0 and no location has been visited
                writer.WriteLine("end_state");

                //goal state
                writer.WriteLine("begin_goal");
                writer.WriteLine(this.points.Count + 1); //number of goals
                writer.WriteLine("0 0"); // salesman has to be in site0
                for (int i = 1; i < this.points.Count + 1; i++)
                    writer.WriteLine(i + " 1"); // all sites has to be visited
                writer.WriteLine("end_goal");

                //operators count
                writer.WriteLine(this.points.Count * this.points.Count - this.points.Count);
                for (int i = 0; i < this.points.Count; i++)
                    for (int j = 0; j < this.points.Count; j++)
                    {
                        //operator go from i to j
                        if (i == j) continue;
                        writer.WriteLine("begin_operator");
                        writer.WriteLine("travel from site" + i + " to site" + j);
                        if (j != 0) writer.WriteLine("0"); //no prevail conditions
                        else
                        {
                            writer.WriteLine(this.points.Count - 1);    //returning is only allowed if all sites have been visited
                            for (int k = 1; k < this.points.Count; k++)
                            {
                                writer.WriteLine((k + 1) + " 1");
                            }
                        }
                        writer.WriteLine("2"); //2 effects
                        writer.WriteLine("0 0 " + i + " " + j); //move salesman from i to j, no effect conditions
                        writer.WriteLine("0 " + (j + 1) + " 0 1"); //set the site j which was previously "not visited" to state "visited", no effect conditions
                        writer.WriteLine((int)(Math.Truncate(getDistance(i, j)))); //cost of the operator
                        writer.WriteLine("end_operator");
                    }
                writer.WriteLine("0"); //no axioms
            }
        }
        
        #endregion ExportToPlanningSAS

        private double computeDistance(int pos1, int pos2)
        {
            return Math.Sqrt((points[pos1].x - points[pos2].x) * (points[pos1].x - points[pos2].x) +
            (points[pos1].y - points[pos2].y) * (points[pos1].y - points[pos2].y));
        }

        #region publicInterface

        public void addPoint(TSPPoint p)
        {
            points.Add(p);
            position.Add(p.ID, points.Count - 1);
            distances.Add(new List<double>(distances.Count + 1));
            for (int i = 0; i < points.Count-1; i++)
            {
                double distance_i_new = computeDistance(i, points.Count-1);
                distances[i].Add(distance_i_new);
                distances[distances.Count - 1].Add(distance_i_new);
            }
            distances[distances.Count - 1].Add(0d);
            if (p.x > maxValueX)
                maxValueX = p.x;
            if (p.y > maxValueY)
                maxValueY = p.y;
        }
        public TSPPoint getPoint(int position)
        {
            return points[position];
        }
        public double getDistance(int first, int second)
        {
            return distances[first][second];
        }

        #endregion publicInterface

        #region PublicAccessData

        public double maxValueX
        {
            get;
            private set;
        }
        public double maxValueY
        {
            get;
            private set;
        }
        public int nodesCount
        {
            get
            {
                return points.Count;
            }
            private set
            {
                
            }
        }

        #endregion PublicAccessData

    }
}
