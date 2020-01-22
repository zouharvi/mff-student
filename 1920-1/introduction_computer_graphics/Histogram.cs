using System.Drawing;
using MathSupport;
using Raster;
using System;
using System.Text.RegularExpressions;

namespace Utilities
{
    public class ImageHistogramVilda
    {
        /// <summary>
        /// Cached histogram data.
        /// </summary>
        protected static int[,] histArray = null;
        protected static int[,] histArrayCur = null;

        // Histogram sample window diameter
        protected static int rangeDiam = 0;
        // Histogram color mode (0 .. RGB, 1 .. HSV)
        protected static int colorMode = 0;

        /// <summary>
        /// Draws the current histogram to the given raster image.
        /// </summary>
        /// <param name="graph">Result image (already scaled to the desired size).</param>
        public static void DrawHistogram(Bitmap graph)
        {
            if (histArray == null)
                return;

            float maxDark = 0.0f;
            foreach (int f in histArray)
                if (f > maxDark)
                    maxDark = f;
            float max = 0.0f;
            foreach (int f in histArrayCur)
                if (f > max)
                    max = f;
            if(max == 0.0f)
                max = maxDark;

            using (Graphics gfx = Graphics.FromImage(graph))
            {
                gfx.Clear(Color.White);
                int length = histArray.GetLength(0);

                // Graph scaling:
                float x0 = graph.Width * 0.05f;
                float y0 = graph.Height * 0.95f;
                float kx = graph.Width * 0.9f / length;
                float kyDark = -graph.Height * 0.9f / maxDark;
                float ky = -graph.Height * 0.9f / max;

                Point[] prev = new Point[3];
                Point[] prevDark = new Point[3];
                Pen[] pens = new Pen[3] { new Pen(Color.Red, 2), new Pen(Color.Green, 2), new Pen(Color.Blue, 2) };
                Pen[] pensDark = new Pen[3] { new Pen(Color.DarkRed, 2), new Pen(Color.DarkGreen, 2), new Pen(Color.DarkBlue, 2) };
                for (int x = 0; x < length; x++)
                {
                    for(int col = 0; col < 3; col++) {
                        Point curDark = new Point(Convert.ToInt32(x0 + x * kx), Convert.ToInt32(y0 + histArray[x,col] * kyDark));
                        if(x != 0) {
                            gfx.DrawLine(pensDark[col], prevDark[col], curDark);
                        }
                        prevDark[col] = curDark;

                        if(rangeDiam != 0) {
                            Point cur = new Point(Convert.ToInt32(x0 + x * kx), Convert.ToInt32(y0 + histArrayCur[x,col] * ky));
                            if(x != 0) {
                                gfx.DrawLine(pens[col], prev[col], cur);
                            }
                            prev[col] = cur;
                        }
                    }
                }

                // Axes:
                Pen axisPen = new Pen(Color.Black);
                gfx.DrawLine(axisPen, x0, y0, x0 + length * kx, y0);
                gfx.DrawLine(axisPen, x0, y0, x0, y0 + maxDark * kyDark);
            }
        }

        /// <summary>
        /// Recomputes image histogram and draws the result in the given raster image.
        /// </summary>
        /// <param name="input">Input image.</param>
        /// <param name="param">Textual parameter.</param>
        public static void ComputeHistogram(Bitmap input, string param, int mouseX, int mouseY)
        {
            // Text parameters:
            param = param.ToLower().Trim();

            Match match = (new Regex(@"diam=([0-9]+)")).Match(param);
            if (match.Success)
            {
                rangeDiam = Int32.Parse(match.Groups[1].Value);
                if(mouseX < 0 || mouseY < 0) {
                    rangeDiam = 0;
                }
            } else {
                rangeDiam = 0;
            }

            if (param.Contains("hsv"))
            {
                colorMode = 0;
            }
            else if (param.Contains("rgb"))
            {
                colorMode = 1;
            }

            // Histogram recomputation.
            histArray = new int[256, 3];
            histArrayCur = new int[256, 3];

            int width = input.Width;
            int height = input.Height;
            for (int y = 0; y < height; y++)
                for (int x = 0; x < width; x++)
                {
                    Color col = input.GetPixel(x, y);

                    // HSV
                    if(colorMode == 0) {
                        double H, S, V;
                        Arith.ColorToHSV( col, out H, out S, out V );
                        
                        // naive discretization
                        H = H / 360.0 * 255;
                        S = S * 255;
                        V = V * 255;
                        histArray[Convert.ToInt32(H),0]++;
                        histArray[Convert.ToInt32(S),1]++;
                        histArray[Convert.ToInt32(V),2]++;

                        if(rangeDiam > 0 && x >= mouseX - rangeDiam && x <= mouseX + rangeDiam && y >= mouseY - rangeDiam && y <= mouseY + rangeDiam) {
                            histArrayCur[Convert.ToInt32(H),0]++;
                            histArrayCur[Convert.ToInt32(S),1]++;
                            histArrayCur[Convert.ToInt32(V),2]++;
                        }
                    } else {
                        histArray[col.R,0]++;
                        histArray[col.G,1]++;
                        histArray[col.B,2]++;

                        if(rangeDiam > 0 && x >= mouseX - rangeDiam && x <= mouseX + rangeDiam && y >= mouseY - rangeDiam && y <= mouseY + rangeDiam) {
                            histArrayCur[col.R,0]++;
                            histArrayCur[col.G,1]++;
                            histArrayCur[col.B,2]++;
                        }
                    }
                }
        }
    }
}
