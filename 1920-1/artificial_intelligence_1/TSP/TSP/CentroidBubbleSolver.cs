using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class CentroidBubbleSolver : TSPSolver
    {
        private double centroidX, centroidY;
        private double[] angles;
        Comparer<int> comparer;

        private void computeCentroid(TSPInput input)
        {
            angles = new double[input.nodesCount];
            double sumX = 0, sumY = 0;
            for (int i = 0; i < input.nodesCount; i++)
            {
                sumX += input.getPoint(i).x;
                sumY += input.getPoint(i).y;
            }
            centroidX = sumX / input.nodesCount;
            centroidY = sumY / input.nodesCount;
            for (int i = 0; i < input.nodesCount; i++)
            {
                angles[i] = Math.Atan2(input.getPoint(i).x - centroidX, input.getPoint(i).y - centroidY);
            }
            this.comparer = new referenceComparer(angles);
        }

        #region TSPSolver Members

        public TSPSolution solve(TSPInput input)
        {
            computeCentroid(input);
            int[] points = new int[input.nodesCount];
            for (int i = 0; i < input.nodesCount; i++)
                points[i] = i;
            Array.Sort(points, comparer);
            TSPSolution sol = new TSPSolution(input);
            for (int i = 0; i < input.nodesCount - 1; i++)
            {
                sol.setSuccessor(points[i], points[i + 1]);
            }
            sol.setSuccessor(points[input.nodesCount - 1], points[0]);
            return sol;
        }

        #endregion

        private class centroidAngleComparer : Comparer<int>
        {
            private double centroidX, centroidY;
            private TSPInput inp;

            private double getDistanceSquared(int pointIndex)
            {
                return (inp.getPoint(pointIndex).x - centroidX) * (inp.getPoint(pointIndex).x - centroidX) +
                    (inp.getPoint(pointIndex).y - centroidY) * (inp.getPoint(pointIndex).y - centroidY);
            }

            private double getAngle(int pointIndex)
            {
                return Math.Atan2(inp.getPoint(pointIndex).x - centroidX, inp.getPoint(pointIndex).y - centroidY);
            }

            public centroidAngleComparer(double centroidX, double centroidY, TSPInput inp)
            {
                this.inp = inp;
                this.centroidX = centroidX;
                this.centroidY = centroidY;
            }

            public override int Compare(int x, int y)
            {
                return getAngle(x) > getAngle(y) ? 1 : -1;
            }
        }

        private class referenceComparer : Comparer<int>
        {
            private double[] refArray;

            public referenceComparer(double[] refArray)
            {
                this.refArray = refArray;
            }

            public override int Compare(int x, int y)
            {
                if (refArray[x] > refArray[y])
                    return 1;
                if (refArray[x] < refArray[y])
                    return -1;
                return 0;
            }
        }
    }


}
