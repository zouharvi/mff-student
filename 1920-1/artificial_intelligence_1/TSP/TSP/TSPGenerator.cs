using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSP
{
    class TSPGenerator
    {
        public static TSPInput generateUniform(int nodesCount, Random r, int maxWidth = 1000, int maxHeight = 1000)
        {
            //r = new Random();
            TSPInput result = TSPInput.create();
            for (int i = 0; i < nodesCount; i++)
            {
                TSPPoint p = TSPPoint.create(r.NextDouble() * maxWidth, r.NextDouble() * maxHeight);
                result.addPoint(p);
            }
            return result;
        }

        public static TSPInput generateClusters(int nodesCount, int clusters, Random r, int maxWidth = 1000, int maxHeight = 1000)
        {
            r = new Random();
            TSPInput result = TSPInput.create();
            List<double> clustersX = new List<double>(), clustersY = new List<double>();
            double x, y;
            for (int i = 0; i < clusters; i++)
            {
                do
                {
                    x = r.NextDouble() * maxWidth - maxWidth / (2 * clusters);
                    y = r.NextDouble() * maxHeight - maxHeight / (2 * clusters);

                } while (x < 0 || y < 0);
                clustersX.Add(x);
                clustersY.Add(y);
            }
            for (int j = 0; j < clusters; j++)
            {
                for (int i = 0; i < nodesCount / clusters; i++)
                {
                    TSPPoint p = TSPPoint.create(clustersX[j] + r.NextDouble() * maxWidth / clusters,
                        clustersY[j] + r.NextDouble() * maxHeight / clusters);
                    result.addPoint(p);
                }
            }
            return result;
        }

        public static TSPInput generateClustersAntiGreedy(int nodesCount, int clusters, Random r, int maxWidth = 1000, int maxHeight = 1000)
        {
            r = new Random();
            TSPInput result = TSPInput.create();
            List<double> clustersX = new List<double>(), clustersY = new List<double>();
            double x, y;
            for (int i = 0; i < clusters; i++)
            {
                do
                {
                    x = r.NextDouble() * maxWidth - maxWidth / (2 * clusters);
                    y = r.NextDouble() * maxHeight - maxHeight / (2 * clusters);

                } while (x < 0 || y < 0);
                clustersX.Add(x);
                clustersY.Add(y);
            }
            for (int j = 0; j < clusters; j++)
            {
                for (int i = 0; i < (nodesCount - 4) / clusters; i++)
                {
                    TSPPoint p = TSPPoint.create(clustersX[j] + r.NextDouble() * maxWidth / clusters,
                        clustersY[j] + r.NextDouble() * maxHeight / clusters);
                    result.addPoint(p);
                }
            }
            result.addPoint(TSPPoint.create(0, 0));
            result.addPoint(TSPPoint.create(1000, 0));
            result.addPoint(TSPPoint.create(0, 1000));
            result.addPoint(TSPPoint.create(1000, 1000));
            return result;
        }

        public static TSPInput generateHybrid(int nodesCount, int clusters, Random r, int maxWidth = 1000, int maxHeight = 1000)
        {
            r = new Random();
            TSPInput result = TSPInput.create();
            List<double> clustersX = new List<double>(), clustersY = new List<double>();
            double x, y;
            for (int i = 0; i < clusters; i++)
            {
                do
                {
                    x = r.NextDouble() * maxWidth - maxWidth / (2 * clusters-1);
                    y = r.NextDouble() * maxHeight - maxHeight / (2 * clusters-1);

                } while (x < 0 || y < 0);
                clustersX.Add(x);
                clustersY.Add(y);
            }
            for (int j = 0; j < clusters; j++)
            {
                int clusterSize = r.Next(nodesCount / (clusters-1));
                for (int i = 0; i < clusterSize; i++)
                {
                    TSPPoint p = TSPPoint.create(clustersX[j] + r.NextDouble() * maxWidth / clusters,
                        clustersY[j] + r.NextDouble() * maxHeight / clusters);
                    result.addPoint(p);
                }
            }
            while (result.nodesCount < nodesCount)
            {
                TSPPoint p = TSPPoint.create(r.NextDouble() * maxWidth, r.NextDouble() * maxHeight);
                result.addPoint(p);
            }
            return result;
        }
    }
}
