using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class Edge : IComparable<Edge>
    {
        public int from, to;
        public double weight;
        public double a, b;
        public TSPInput inp;

        public override bool Equals(object obj)
        {
            if (!(obj is Edge))
                return false;
            Edge e = (Edge)obj;
            return e.from == this.from && e.to == this.to;
        }

        public override int GetHashCode()
        {
            return from * 50000 + to;
        }

        public static bool isCrossing(TSPPoint A, TSPPoint B, TSPPoint C, TSPPoint D)
        {
            double p = (B.y - A.y) / (B.x - A.x),
                q = A.y - p * A.x;
            return isCrossing(A, B, C, D, p, q);
        }

        public static bool isCrossing(TSPPoint A, TSPPoint B, TSPPoint C, TSPPoint D, double p, double q)
        {
            if (B.ID == C.ID || A.ID == C.ID || A.ID == D.ID || B.ID == D.ID)
                return false;
            double res1 = p * C.x + q - C.y,
                res2 = p * D.x + q - D.y;
            if ((res1 < 0 && res2 > 0) || (res1 > 0 && res2 < 0))
                return true;
            return false;
            //return (res1 < 0 && res2 > 0) || (res1 > 0 && res2 < 0);
        }

        public bool intersectsWith(Edge other)
        {
            //return isCrossing(inp.getPoint(from), inp.getPoint(to), other.inp.getPoint(other.from), other.inp.getPoint(other.to));

            return (a * inp.getPoint(other.from).x + b < inp.getPoint(other.from).y ^
                a * inp.getPoint(other.to).x + b < inp.getPoint(other.to).y) &&
            (other.a * inp.getPoint(this.from).x + other.b < inp.getPoint(this.from).y ^
                other.a * inp.getPoint(this.to).x + other.b < inp.getPoint(this.to).y);
        }

        public Edge(int from, int to, TSPInput inp)
        {
            this.from = from;
            this.to = to;
            this.weight = inp.getDistance(from, to);
            this.inp = inp;
            this.a = (inp.getPoint(to).y - inp.getPoint(from).y) / (inp.getPoint(to).x - inp.getPoint(from).x);
            this.b = inp.getPoint(to).y - inp.getPoint(to).x * a;
        }

        public Edge(int from, int to, TSPInput inp, double weight)
        {
            this.from = from;
            this.to = to;
            this.weight = weight;
            this.inp = inp;
            this.a = (inp.getPoint(to).y - inp.getPoint(from).y) / (inp.getPoint(to).x - inp.getPoint(from).x);
            this.b = inp.getPoint(to).y - inp.getPoint(to).x * a;
        }


        #region IComparable<Edge> Members

        public int CompareTo(Edge other)
        {
            if (other.weight > this.weight)
                return 1;
            if (other.weight < this.weight)
                return -1;
            return 0;
        }

        #endregion
    }
}
