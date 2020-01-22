using MathSupport;
using Raster;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using Utilities;
using System.Linq;
using Vilda;

namespace Vilda
{
    class Utils
    {
        public static int Clamp(int value, int min, int max)
        {
            return (value < min) ? min : (value > max) ? max : value;
        }

        public static double Median(List<double> arr)
        {
            arr.Sort();
            return arr[(int)arr.Count / 2];
        }
    }
}

namespace Modules
{
    public class ModuleImpressionismVilda : DefaultRasterModule
    {
        // Sources, mostly [1] and [2]
        // [1] https://www.codeproject.com/Articles/471994/OilPaintEffect
        // [2] http://supercomputingblog.com/graphics/oil-painting-algorithm/
        // [3] https://www.mrl.nyu.edu/publications/painterly98/
        // [4] http://www.cgl.uwaterloo.ca/lanortha/CourseProjects/Painterly/painterly.html
        public ModuleImpressionismVilda()
        {
            param = "radius=5, detail=50";
        }
        public override string Author => "Vilém Zouhar";
        public override string Name => "Impressionism";
        public override string Tooltip => "[radius=<int>][detail=<double>]";
        public override int InputSlots => 1;
        public override int OutputSlots => 1;
        protected Bitmap inImage = null;
        protected Bitmap outImage = null;

        protected string message;
        public override void SetInput(Bitmap inputImage, int slot = 0)
        {
            inImage = inputImage;
        }
        int radius = 5;
        double intensityLevels = 50;
        public override void Update()
        {
            // Starts a new computation.
            UserBreak = false;


            Dictionary<string, string> p = Util.ParseKeyValueList(param);
            if (p.Count > 0)
            {
                // detail=<double>
                if (Util.TryParse(p, "detail", ref intensityLevels))
                    intensityLevels = Math.Min(Math.Max(0, intensityLevels), 256);
                // radius=<int>
                if (Util.TryParse(p, "radius", ref radius))
                    radius = Math.Min(Math.Max(0, radius), 256);
            }

            outImage = new Bitmap(inImage);

            if (inImage == null)
                return;

            // No input => generate constant full-color image.
            for (int y = 0; y < outImage.Height; y++)
            {
                if (UserBreak) return;
                for (int x = 0; x < outImage.Width; x++)
                {
                    // var newCol = filterR1.apply(inImage, xo, yo);
                    // outImage.SetPixel(xo, yo, newCol);
                    // iterate window around a specific pixel
                    int[] intensities = new int[256];
                    int[] intensitiesR = new int[256];
                    int[] intensitiesG = new int[256];
                    int[] intensitiesB = new int[256];
                    for (int rY = Math.Max(0, y - radius); rY < Math.Min(outImage.Height, y + radius); rY++)
                    {
                        for (int rX = Math.Max(0, x - radius); rX < Math.Min(outImage.Width, x + radius); rX++)
                        {
                            Color col = inImage.GetPixel(rX, rY);
                            int curIntensity = (int)((((col.R + col.G + col.B) / 3.0) * intensityLevels) / 255.0);
                            curIntensity = Utils.Clamp(curIntensity, 0, 255);
                            intensities[curIntensity] += 1;
                            intensitiesR[curIntensity] += col.R;
                            intensitiesG[curIntensity] += col.G;
                            intensitiesB[curIntensity] += col.B;
                        }
                    }

                    // find max intensity index
                    int maxCount = -1;
                    int maxI = -1;
                    for (int i = 0; i <= 255; i++)
                    {
                        if (intensities[i] > maxCount)
                        {
                            maxCount = intensities[i];
                            maxI = i;
                        }
                    }
                    outImage.SetPixel(x, y, Color.FromArgb(
                      intensitiesR[maxI] / maxCount,
                      intensitiesG[maxI] / maxCount,
                      intensitiesB[maxI] / maxCount
                      ));
                }
            }

        }
        public override Bitmap GetOutput(int slot = 0) => outImage;
        public override string GetOutputMessage(int slot = 0) => message;
    }
}
