using System;
using System.Collections.Generic;
using System.Drawing;
using LineCanvas;
using MathSupport;
using System.Windows.Forms;
using Utilities;

namespace _093animation
{
    public class Animation
    {
        public static void InitParams(out string name, out int wid, out int hei, out double from, out double to, out double fps, out string param, out string tooltip)
        {
            // Put your name here.
            name = "Vilém Zouhar";

            // Credits:
            // Frida Kahlo – Self-Portrait with Thorn Necklace and Hummingbird, 1940
            // https://www.widewalls.ch/famous-painters-20th-century/frida-kahlo/
            
            // Image size in pixels.
            wid = 1920;
            hei = 1080;

            // Animation.
            from = 0.0;
            to = 30.0;
            fps = 25.0;

            // Specific animation params.
            param = "";

            // Tooltip = help.
            tooltip = "";
        }

        private static Bitmap inp = null;
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

        public static void InitAnimation(int width, int height, double start, double end, double fps, string param)
        {
            if (!loadImage())
                inp = null;
            inp = new Bitmap(inp, new Size(width, height));
        }

        public static void DrawFrame(Canvas c, double time, double start, double end, string param)
        {
            if (inp == null)
                return;
            float OI = 1.5f;
            // Input params.
            float penWidth = 1.0f;
            int skipX = (int) (10 * OI);
            int skipY = (int) (10 * OI);
            float scaleX = 10*OI;
            float scaleY = 10*OI;
            float randY = 4f*OI;
            bool waves = false;
            Random random = new Random();

            double timeNorm = Arith.Clamp((time - start) / (end - start), 0.0, 1.0);
            double timeBase = time-start;
            
            // flipX
            int stage = 1;
            double stageTime = timeBase;
            while(stageTime > 3) {
              stageTime -= 3;
              stage += 2;
            }
            if(stageTime < 0.5) stage -= 1;
            byte flipX = (byte) (stage % 2);

            // override first two flips
            if(stage == 1) flipX = 0;
            // if(stage == 2) flipX = 1;
            
            if(stage == 1) {

            } else if(stage > 1) {
              skipX = (int) (15*OI);
              skipY = (int) (15*OI);
              scaleX = 15*OI;
              scaleY = 15*OI;
              randY = 8f*OI;
            }

            double randYstatic = 0; 
            if (stage == 3) {
              randYstatic = Math.Max(10, 13*stageTime*OI);
              penWidth = 3;
            } else if (stage == 4) {
              penWidth = 3;
              random = new Random(100);
              randYstatic = 13*3*OI;
            } else {
              randYstatic = 0;
            }

            if (stage == 5 || stage == 6) {
              skipY = (int) (8*OI);
              scaleX = 5*OI;
              scaleY = 5*OI;
            }
            if (stage == 6) {
              random = new Random(100);
            }

            if (stage == 7 || stage == 8) {
              skipY = (int) (12*OI);
              skipX = (int) (12*OI);
              scaleX = 13*OI;
              scaleY = 13*OI;
            }
            if (stage == 8) {
              random = new Random(100);
            }
            
            if (stage == 9 || stage == 10) {
              skipX = (int) (12*OI);
              skipY = (int) (3*OI);
              waves = true;
              penWidth = 2;
              randYstatic = Math.Max(5, 10*stageTime*OI);
            }
            if (stage == 10) {
              random = new Random(100);
            }

            if (stage == 11 || stage == 12) {
              skipY = (int) (10*OI);
              skipX = (int) (10*OI);
              scaleX = 13*OI;
              scaleY = 13*OI;
            }
            if (stage == 12) {
              random = new Random(100);
            }

            if (stage == 13 || stage == 14) {
              skipX = (int) (13*OI);
              skipY = (int) (12*OI);
              waves = true;
              penWidth = 2.4f;
              randYstatic = Math.Max(20, 50*stageTime);
            }
            if (stage == 14) {
              random = new Random(100);
            }

            if (stage >= 15) {
              skipY = (int) (8*OI);
              skipX = (int) (8*OI);
              scaleX = 8*OI;
              scaleY = 8*OI;
            }
            if (stage == 16) {
              random = new Random(100);
            }

            if (stage >= 17) {
              skipY = (int) (5*OI);
              skipX = (int) (5*OI);
              scaleX = 5*OI;
              scaleY = 5*OI;
            }
            
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
                    Color col = inp.GetPixel(j*(1-flipX) + flipX*(inp.Width-1-j), i);
                    c.SetColor(col);

                    int length = (int)(scaleX * col.GetBrightness());
                    double angle = col.GetHue() / 360;
                    double difY = Math.Cos(angle * Math.PI);
                    double difYRandY = (random.NextDouble() - 0.5) * (randY+randYstatic);
                    if(waves) {
                      c.Line(prevX, prevY, j + length, i + difY * scaleY + difYRandY);
                      prevX = j + length;
                      prevY = i + difY * scaleY + difYRandY;
                    } else {
                      c.Line(j, i, j + length, i + difY * scaleY + difYRandY);
                    }
                }
            }

            // debug print states
            // Console.WriteLine(stage);
            // c.SetPenWidth(2);
            // c.SetColor(Color.Red);
            // for(int i = 0; i < stage; i++)
            //   c.Line(10, 5*i, 100, 5*i);
        }
    }
}
