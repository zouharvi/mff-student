using System;
using System.Collections.Generic;
using System.Drawing;
using LineCanvas;
using Utilities;
using System.Windows.Forms;

namespace _092lines
{
    public class Lines
    {

        public static void InitParams(out string name, out int wid, out int hei, out string param, out string tooltip)
        {
            // Put your name here.
            name = "Vilém Zouhar";

            // Image size in pixels.
            wid = 800;
            hei = 520;

            // Specific animation params.
            param = "width=3.0,scaleX=10,scaleY=10,skipX=10,skipY=10,randY=5";

            // Tooltip = help.
            tooltip = "width=<int>, scaleX=<float>, scaleY=<float>, skipX=<int>, skipY=<int>, randY=<float>";
        }

        private static Bitmap inp;
        private static Random random = new Random();
        private static bool loadImage()
        {
            using (OpenFileDialog ofd = new OpenFileDialog()
            {
                Title = "Open Image File",
                Filter = "Bitmap Files|*.bmp" +
                "|Gif Files|*.gif" +
                "|JPEG Files|*.jpg" +
                "|PNG Files|*.png" +
                "|TIFF Files|*.tif" +
                "|All image types|*.bmp;*.gif;*.jpg;*.png;*.tif",
                FilterIndex = 6,
                FileName = ""
            })
            {
                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    inp = (Bitmap)Image.FromFile(ofd.FileName);
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

        public static void Draw(Canvas c, string param)
        {
            // Input params.
            float penWidth = 1.0f;
            int skipX = 10;
            int skipY = 10;
            float scaleX = 10.0f;
            float scaleY = 10.0f;
            float randY = 5f;

            Dictionary<string, string> p = Util.ParseKeyValueList(param);
            if (p.Count > 0)
            {
                Util.TryParse(p, "width", ref penWidth);
                Util.TryParse(p, "skipX", ref skipX);
                Util.TryParse(p, "skipY", ref skipY);
                Util.TryParse(p, "scaleX", ref scaleX);
                Util.TryParse(p, "scaleY", ref scaleY);
                Util.TryParse(p, "randY", ref randY);
            }

            if (!loadImage())
                return;

            inp = new Bitmap(inp, new Size(c.Width, c.Height));
            c.Clear(Color.Black);

            c.SetPenWidth(penWidth);
            c.SetAntiAlias(true);
            c.SetColor(Color.FromArgb(255, 0, 0));

            for (int i = 0; i < inp.Height; i += skipY)
            {
                double prevX = 0;
                double prevY = i;
                for (int j = 0; j < inp.Width; j += skipX)
                {
                    Color col = inp.GetPixel(j, i);
                    c.SetColor(col);

                    int length = (int)(scaleX * col.GetBrightness());
                    double angle = col.GetHue() / 360;
                    double difY = Math.Cos(angle * Math.PI);
                    double difYRandY = (random.NextDouble() - 0.5) * randY;
                    c.Line(prevX, prevY, j + length, i + difY * scaleY + difYRandY);
                    prevX = j + length;
                    prevY = i + difY * scaleY + difYRandY;
                }
            }
        }
    }
}
