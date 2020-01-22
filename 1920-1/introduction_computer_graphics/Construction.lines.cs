using System;
using System.Collections.Generic;
using MathSupport;
using OpenTK;
using Utilities;

namespace Scene3D
{
  public class Construction
  {
    #region Form initialization

    public static void InitParams (out string name, out string param, out string tooltip)
    {
      name    = "Vilém Zouhar";
      param   = "seg=1000,sX=4,sY=4,sZ=1,density=0.1";
      tooltip = "density=<density>, seg=<segments>, sX, sY, sZ .. axis scales";
    }

    #endregion

    #region Instance data

    private double density = 0.1;
    private double sX = 4;
    private double sY = 4;
    private double sZ = 1;
    private int segments = 1000;
    private double maxT = 2.0 * Math.PI;

    private void parseParams (string param)
    {
      // Defaults.
      density = 0.1;
      sX      = 4;
      sY      = 4;
      sZ      = 1;
      segments = 1000;

      Dictionary<string, string> p = Util.ParseKeyValueList(param);
      if (p.Count > 0)
      {
        if (Util.TryParse(p, "seg", ref segments) && segments < 10)
          segments = 10;

        Util.TryParseRational(p, "density", ref density);
        Util.TryParseRational(p, "sX", ref sX);
        Util.TryParseRational(p, "sY", ref sY);
        Util.TryParseRational(p, "sZ", ref sZ);
      }

      // Estimate of upper bound for 't'.
      maxT = 4 * 2.0 * Math.PI;
    }

    #endregion

    public Construction ()
    {    }

    private const int ACCURACY = 5;

    private int fact(int n) {
      if(n <= 1) 
        return 1;
      else
        return n * fact(n-1);
    }

    private float fresnelS(double x) {
      double sum = 0;
      double last = 0;
      for(int i = 1; i < ACCURACY; i++) {
        last = sum;
        sum += Math.Pow(-1, i) * Math.Pow(x, 4*i+3)/((4*i+3)*fact(2*i+1));
      }  
      return (float)(sum+last)/2;
    }

    private float fresnelC(double x) {
      double sum = 0;
      double last = 0;
      for(int i = 1; i < ACCURACY; i++) {
        last = sum;
        sum += Math.Pow(-1, i) * Math.Pow(x, 4*i+1)/((4*i+1)*fact(2*i));
      }  
      return (float)(sum+last)/2;
    }

    #region Mesh construction

    public int AddMesh (SceneBrep scene, Matrix4 m, string param)
    {
      parseParams(param);

      // If there will be large number of new vertices, reserve space for them to save time.
      scene.Reserve(3*segments);

      // further edit axis scales

      // fresnel
      // A.X = fresnelC(t);
      // A.Y = fresnelS(t);

      // Cardioid
      // A.X = (float)(Math.Pow(Math.Sin(t), 3) + 25);
      // A.Y = (float)(Math.Cos(t) - 5*Math.Cos(2*t) - 2*Math.Cos(3*t) - Math.Cos(4*t)+ 2);
      // A.Z = (float)(Math.Pow(Math.Sin(t), 3) + 25);

      // Torus
      // A.X = (float)(Math.Cos(t)*(2 * 1/2 * Math.Cos(s)));
      // A.Y = (float)(Math.Sin(t)*(2 * 1/2 * Math.Cos(s)));
      // A.Z = (float)(5 * Math.Sin(t)));

      // first helix
      double t = 0.0;
      double dt = maxT / segments;
      double s = 0.0;
      double ds = 1.0 / segments;
      int vPrev = 0;
      Vector3 A;
      for (int i = 0; i <= segments; i++)
      {
        // Helix
        A.X = (float)(Math.Cos(t)*sX);
        A.Y = (float)(Math.Sin(t)*sY);
        A.Z = (float)(t*sZ);

        // New vertex.
        int v = scene.AddVertex(Vector3.TransformPosition(A, m));

        // Vertex attributes.
        scene.SetTxtCoord(v, new Vector2((float)s, (float)s));
        System.Drawing.Color c = Raster.Draw.ColorRamp(0.5 *(s + 1.0));
        scene.SetColor(v, new Vector3(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f));

        // New line?
        if (i > 0)
          scene.AddLine(vPrev, v);

        // Next vertex.
        t += dt;
        s += ds;
        vPrev = v;
      }

      // second helix
      t = 0.0;
      s = 0.0;
      vPrev = 0;
      for (int i = 0; i <= segments; i++)
      {
        // Helix
        A.X = (float)(Math.Cos(t+Math.PI/2)*sX);
        A.Y = (float)(Math.Sin(t+Math.PI/2)*sY);
        A.Z = (float)(t*sZ);

        // New vertex.
        int v = scene.AddVertex(Vector3.TransformPosition(A, m));

        // Vertex attributes.
        scene.SetTxtCoord(v, new Vector2((float)s, (float)s));
        System.Drawing.Color c = Raster.Draw.ColorRamp(0.5 *(s + 1.0));
        scene.SetColor(v, new Vector3(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f));

        // New line?
        if (i > 0)
          scene.AddLine(vPrev, v);

        // Next vertex.
        t += dt;
        s += ds;
        vPrev = v;
      }

      // ladder
      segments = (int) (segments*density);
      dt = maxT / segments;
      ds = 1.0 / segments;
      t = 0.0;
      s = 0.0;
      Vector3 B;
      for (int i = 0; i <= segments; i++)
      {
        B.X = (float)(Math.Cos(t+Math.PI/2)*sX);
        B.Y = (float)(Math.Sin(t+Math.PI/2)*sY);
        B.Z = (float)(t*sZ);
        
        A.X = (float)(Math.Cos(t)*sX);
        A.Y = (float)(Math.Sin(t)*sY);
        A.Z = (float)(t*sZ);
        
        // New vertex.
        int v1 = scene.AddVertex(Vector3.TransformPosition(A, m));
        int v2 = scene.AddVertex(Vector3.TransformPosition(B, m));

        // Vertex attributes.
        scene.SetTxtCoord(v1, new Vector2((float)s, (float)s));
        scene.SetTxtCoord(v2, new Vector2((float)s, (float)s));
        System.Drawing.Color c = Raster.Draw.ColorRamp(0.5 *(s + 1.0));
        scene.SetColor(v1, new Vector3(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f));
        scene.SetColor(v2, new Vector3(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f));

        // New line?
        if (i > 0)
          scene.AddLine(v1, v2);

        // Next vertex.
        t += dt;
        s += ds;
      }

      // Thick line (for rendering).
      scene.LineWidth = 0.2f;

      return segments;
    }

    #endregion
  }
}
