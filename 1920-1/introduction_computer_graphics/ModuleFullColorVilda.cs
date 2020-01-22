using MathSupport;
using Raster;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using Utilities;

namespace Modules
{
  public class ModuleFullColorVilda : DefaultRasterModule
  {
    /// <summary>
    /// Mandatory plain constructor.
    /// </summary>
    public ModuleFullColorVilda ()
    {
      // Default cell size (wid x hei).
      param = "prec=100";
    }

    /// <summary>
    /// Author's full name.
    /// </summary>
    public override string Author => "Vilém Zouhar";

    /// <summary>
    /// Name of the module (short enough to fit inside a list-boxes, etc.).
    /// </summary>
    public override string Name => "FullColorVilda";

    /// <summary>
    /// Tooltip for Param (text parameters).
    /// </summary>
    public override string Tooltip => "[prec=<precision>][,slow][,ignore-input][,no-check]";

    /// <summary>
    /// Usually read-only, optionally writable (client is defining number of inputs).
    /// </summary>
    public override int InputSlots => 1;

    /// <summary>
    /// Usually read-only, optionally writable (client is defining number of outputs).
    /// </summary>
    public override int OutputSlots => 1;

    /// <summary>
    /// Input raster image.
    /// </summary>
    protected Bitmap inImage = null;

    /// <summary>
    /// Output raster image.
    /// </summary>
    protected Bitmap outImage = null;

    /// <summary>
    /// Output message (color check).
    /// </summary>
    protected string message;

    /// <summary>
    /// Assigns an input raster image to the given slot.
    /// Doesn't start computation (see #Update for this).
    /// </summary>
    /// <param name="inputImage">Input raster image (can be null).</param>
    /// <param name="slot">Slot number from 0 to InputSlots-1.</param>
    public override void SetInput (
      Bitmap inputImage,
      int slot = 0)
    {
      inImage = inputImage;
    }

    public static void Randomize<T>(ref T[] items) {
        Random rand = new Random();
        for (int i = 0; i < items.Length - 1; i++)
        {
            int j = rand.Next(i, items.Length);
            T temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }

    private bool checkClosestOk(int v1, int v2, int v3, bool[] mask) {
        int value = v1 + 256*v2 + 256*256*v3;
        if(v1 >= 0 && v2 >= 0 && v3 >= 0 && v1 < 256 && v2 < 256 && v3 < 256 && !mask[value]) {
          mask[value] = true;
          return true;
        }
        return false;
    }
    private int lastTaken = -1;
    private Color getClosestFree(int v1, int v2, int v3, bool[] mask) {
      int window = 0;

      if(checkClosestOk(v1, v2, v3, mask))
        return Color.FromArgb(v1, v2, v3);

      while(true) {
        if(checkClosestOk(v1+window, v2, v3, mask)) return Color.FromArgb(v1+window, v2, v3);
        if(checkClosestOk(v1-window, v2, v3, mask)) return Color.FromArgb(v1-window, v2, v3);
        if(checkClosestOk(v1, v2+window, v3, mask)) return Color.FromArgb(v1, v2+window, v3);
        if(checkClosestOk(v1, v2-window, v3, mask)) return Color.FromArgb(v1, v2-window, v3);
        if(checkClosestOk(v1, v2, v3+window, mask)) return Color.FromArgb(v1, v2, v3+window);
        if(checkClosestOk(v1, v2, v3-window, mask)) return Color.FromArgb(v1, v2, v3-window);
        
        window += 1;
        if(window >= precision) {
          while(true) {
            lastTaken += 1;
            if(!mask[lastTaken]) {
              mask[lastTaken] = true;
              return Color.FromArgb(lastTaken % 256, (lastTaken/256 ) % 256, lastTaken/(256*256));
            }
          }
        }
      }
    }
    int precision = 100;

    /// <summary>
    /// Recompute the output image[s] according to input image[s].
    /// Blocking (synchronous) function.
    /// #GetOutput() functions can be called after that.
    /// </summary>
    public override void Update ()
    {
      // Input image is optional.
      // Starts a new computation.
      UserBreak = false;

      // Default values.
      int wid = 4096;
      int hei = 4096;
      bool fast = true;
      bool ignoreInput = false;
      bool check = true;

      // We are not using 'paramDirty', so the 'Param' string has to be parsed every time.
      Dictionary<string, string> p = Util.ParseKeyValueList(param);
      if (p.Count > 0)
      {
        // prec=<int> [imitation precision from 0 to 256]
        if (Util.TryParse(p, "prec", ref precision))
          precision = Math.Min(Math.Max(0, precision), 256);

        // slow ... use Bitmap.SetPixel()
        fast = !p.ContainsKey("slow");

        // ignore-input ... ignore input image even if it is present
        ignoreInput = p.ContainsKey("ignore-input");

        // no-check ... disable color check at the end
        check = !p.ContainsKey("no-check");
      }

      outImage = new Bitmap(wid, hei, PixelFormat.Format24bppRgb);

      if (!ignoreInput && inImage != null) {
        // double minH=1, maxH=0, minS=1, maxS=0, minV=1, maxV=0;
        double minR=256, maxR=0, minG=256, maxG=0, minB=256, maxB=0;
        for(int x = 0; x < inImage.Width; x++) {
          for(int y = 0; y < inImage.Height; y++) {
            Color color = inImage.GetPixel(x, y);
            if(color.G > maxG) maxG = color.G;
            if(color.G < minG) minG = color.G;
            if(color.R > maxR) maxR = color.R;
            if(color.R < minR) minR = color.R;
            if(color.B > maxB) maxB = color.B;
            if(color.B < minB) minB = color.B;
          }
        }

        inImage = new Bitmap(inImage, new Size(wid, hei));
        bool[] maskAll = new bool[256*256*256];
        
        int[] accessQueue = new int[wid*hei];
        for(int i = 0; i < wid; i++) {
          for(int j = 0; j < hei; j++)
            accessQueue[i + wid*j] = i + wid*j;
        }
        Randomize(ref accessQueue);
        
        for(int a = 0; a < accessQueue.Length; a++) {
          Color color = inImage.GetPixel(accessQueue[a] % wid, accessQueue[a]/wid);
          Color newCol = getClosestFree(
            color.R, color.G, color.B,
            maskAll);
          outImage.SetPixel(accessQueue[a] % wid, accessQueue[a]/wid, newCol);
        }
      }
      else
      {
        // No input => generate constant full-color image.
        Color[] allColors = new Color[256*256*256];
        Console.WriteLine("length {0}", allColors.Length);
        for (int i = 0; i < allColors.Length; i++) {
          allColors[i] = Color.FromArgb(i % 256, (i/256) % (256), (i/(256*256)) % (256));
        }
        Randomize(ref allColors);

        for (int yo = 0; yo < hei; yo++)
        {
          for (int xo = 0; xo < wid; xo++)
          {
            outImage.SetPixel(xo, yo, allColors[yo+xo*hei]);
          }
        }
      }

      // Output message.
      if (check &&
          !UserBreak)
      {
        long colors = Draw.ColorNumber(outImage);
        message = colors == (1 << 24) ? "Colors: 16M, Ok" : $"Colors: {colors}, Fail";
      }
      else
        message = null;
    }

    /// <summary>
    /// Returns an output raster image.
    /// Can return null.
    /// </summary>
    /// <param name="slot">Slot number from 0 to OutputSlots-1.</param>
    public override Bitmap GetOutput (
      int slot = 0) => outImage;

    /// <summary>
    /// Returns an optional output message.
    /// Can return null.
    /// </summary>
    /// <param name="slot">Slot number from 0 to OutputSlots-1.</param>
    public override string GetOutputMessage (
      int slot = 0) => message;
  }
}
