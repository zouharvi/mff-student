using MathSupport;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Globalization;
using System.Text;
using System.Threading.Tasks;
using Utilities;

namespace Modules
{
  public class ModuleHSVP : DefaultRasterModule
  {
    /// <summary>
    /// Mandatory plain constructor.
    /// </summary>
    public ModuleHSVP ()
    {}

    /// <summary>
    /// Author's full name.
    /// </summary>
    public override string Author => "Vilém Zouhar";

    /// <summary>
    /// Name of the module (short enough to fit inside a list-boxes, etc.).
    /// </summary>
    public override string Name => "HSVP";

    /// <summary>
    /// Tooltip for Param (text parameters).
    /// </summary>
    public override string Tooltip => "[dH=<double>][,mulS=<double>][,mulV=<double>][,gamma=<double>]\n... dH is absolute, mS, mV, dGamma relative\n[[hsv][ULP]=<double>] for upper and lower bounds and penalization for HSV";

    /// <summary>
    /// Default HSV transform parameters (have to by in sync with the default module state).
    /// </summary>
    protected string param = "dH=40";

    /// <summary>
    /// True if 'param' has to be parsed in the next recompute() call.
    /// </summary>
    protected bool paramDirty = true;

    /// <summary>
    /// Current 'Param' string is stored in the module.
    /// Set reasonable initial value.
    /// </summary>
    public override string Param
    {
      get => param;
      set
      {
        if (value != param)
        {
          param = value;
          paramDirty = true;
          recompute();
        }
      }
    }

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
    /// Absolute Hue delta in degrees.
    /// </summary>
    protected double dH = 0.0;

    /// <summary>
    /// Saturation multiplier.
    /// </summary>
    protected double mS = 1.0;

    /// <summary>
    /// Value multiplier.
    /// </summary>
    protected double mV = 1.0;

    /// <summary>
    /// Gamma-correction coefficient (visible value = inverse value).
    /// </summary>
    protected double gamma = 1.0;

    protected double hU = 100;
    protected double hL = 0;
    protected double sU = 0.88;
    protected double sL = 0.25;
    protected double vU = 0.8;
    protected double vL = 0.1;

    protected double hP = 0.1;
    protected double sP = 2.0;
    protected double vP = 1.0;

    protected void updateParam ()
    {
      if (paramDirty)
      {
        paramDirty = false;

        // 'param' parsing.
        Dictionary<string, string> p = Util.ParseKeyValueList(param);
        if (p.Count > 0)
        {
          Util.TryParse(p, "hU", ref hU);
          Util.TryParse(p, "hL", ref hL);
          Util.TryParse(p, "sU", ref sU);
          Util.TryParse(p, "sL", ref sL);
          Util.TryParse(p, "vU", ref vU);
          Util.TryParse(p, "vL", ref vL);
          Util.TryParse(p, "hP", ref hP);
          Util.TryParse(p, "sP", ref sP);
          Util.TryParse(p, "vP", ref vP);

          // dH=<double> [+- number in degrees]
          Util.TryParse(p, "dH", ref dH);

          // mulS=<double> [relative number .. multiplicator]
          Util.TryParse(p, "mulS", ref mS);

          // mulV=<double> [relative number .. multiplicator]
          Util.TryParse(p, "mulV", ref mV);

          // gamma=<double> [gamma correction .. exponent]
          if (Util.TryParse(p, "gamma", ref gamma))
          {
            // <= 0.0 || 1.0.. nothing
            if (gamma < 0.001)
              gamma = 1.0;
          }
        }
      }
    }

    /// <summary>
    /// Recompute the image.
    /// </summary>
    protected void recompute ()
    {
      if (inImage == null)
        return;

      // Update module values from 'param' string.
      updateParam();

      int wid = inImage.Width;
      int hei = inImage.Height;

      // Output image must be true-color.
      outImage = new Bitmap(wid, hei, PixelFormat.Format24bppRgb);

      // Convert pixel data.
      double gam = (gamma < 0.001) ? 1.0 : 1.0 / gamma;

      // Slow GetPixel/SetPixel code.
      for (int y = 0; y < hei; y++)
      {
        double R, G, B;
        double H, S, V;

        for (int x = 0; x < wid; x++)
        {
          Color ic = inImage.GetPixel(x, y);

          // Conversion to HSV.
          Arith.ColorToHSV(ic, out H, out S, out V);
          Arith.HSVToRGB(H, S, V, out R, out G, out B);
          // 0 <= H <= 360, 0 <= S <= 1, 0 <= V <= 1

          double error = 0;
          if(H > hU) error += hP*(H-hU)/360.0;
          if(H < hL) error += hP*(hL-H)/360.0;
          if(S < sL) error += sP*(sL-S);
          if(S > sU) error += sP*(S-sU);
          if(V < vL) error += vP*(vL-V);
          if(V > vU) error += vP*(V-vU);
          error = Util.Clamp(error, 0.0, 1.0);

          // HSV transform.
          H = H*(1-error) + (error)*(H + dH);
          S = S*(1-error) + (error)*Util.Clamp(S * mS, 0.0, 1.0);
          V = V*(1-error) + (error)*Util.Clamp(V * mV, 0.0, 1.0);

          // Conversion back to RGB.
          Arith.HSVToRGB(H, S, V, out R, out G, out B);
          // [R,G,B] is from [0.0, 1.0]^3

          // Optional gamma correction.
          if (gam != 1.0)
          {
            // Gamma-correction.
            R = Math.Pow(R, gam);
            G = Math.Pow(G, gam);
            B = Math.Pow(B, gam);
          }

          Color oc = Color.FromArgb(
          Convert.ToInt32(Util.Clamp(R * 255.0, 0.0, 255.0)),
          Convert.ToInt32(Util.Clamp(G * 255.0, 0.0, 255.0)),
          Convert.ToInt32(Util.Clamp(B * 255.0, 0.0, 255.0)));

          outImage.SetPixel(x, y, oc);
        }
      }
    }
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

    /// <summary>
    /// Recompute the output image[s] according to input image[s].
    /// Blocking (synchronous) function.
    /// #GetOutput() functions can be called after that.
    /// </summary>
    public override void Update () => recompute();

    /// <summary>
    /// Returns an output raster image.
    /// Can return null.
    /// </summary>
    /// <param name="slot">Slot number from 0 to OutputSlots-1.</param>
    public override Bitmap GetOutput (
      int slot = 0) => outImage;
  }
}
