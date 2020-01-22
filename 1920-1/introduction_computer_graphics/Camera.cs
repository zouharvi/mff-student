using System;
using System.Collections.Generic;
using MathSupport;
using OpenTK;
using OpenTK.Graphics.OpenGL;
using Utilities;
using System.Globalization;

namespace _086shader
{
  public class AnimatedCamera : DefaultDynamicCamera
  {
    public static void InitParams (out string name, out string param, out string tooltip)
    {
      name  = "Vilém Zouhar";
      param = "period=10.0, rad=2.0";
      tooltip = "period=<cam period in seconds>, rad=<cam radius in scene diameters>";
    }

    public override void Update (string param, string cameraFile)
    {
      Dictionary<string, string> p = Util.ParseKeyValueList(param);
      if (p.Count > 0)
      {
        // period=<double>
        double v = 1.0;
        if (Util.TryParse(p, "period", ref v))
          MaxTime = Math.Max(v, 0.1);

        // rad=<double>
        if (Util.TryParse(p, "rad", ref v))
          radius = (float) Math.Max(v, 0.01);
      }
      Time = Util.Clamp(Time, MinTime, MaxTime);

      float rx = (float) (radius * 0.5 * Diameter);

      // file seclection in Linux Wine is terrible
      // remove this once debug is complete
      // cameraFile = @"Z:\home\vilda\grcis\086shader\two_circles_mid_up.txt";

      travelPoints = new List<Vector3>();
      if(cameraFile != "") {
        Console.WriteLine(cameraFile);
        string[] lines = System.IO.File.ReadAllLines(cameraFile);
        foreach (string line in lines)
        {
            if(line[0] == '#') {
              // comment
              Console.WriteLine(line);
              continue;
            } 
            string[] coords = line.Split(' ');
            if(coords.Length != 3) {
              Console.WriteLine("Incorrect number of coords: `" + line + "`");
              continue;
            }
            float x0 = float.Parse(coords[0], CultureInfo.InvariantCulture);
            float x1 = float.Parse(coords[1], CultureInfo.InvariantCulture);
            float x2 = float.Parse(coords[2], CultureInfo.InvariantCulture);

            travelPoints.Add(
              Center + new Vector3( rx*x0, rx*x1, rx*x2)
            );
        }
      } else {
        Console.WriteLine("Missing script file");
      }
    }

    float radius = 1.0f;

    public AnimatedCamera (string param, string cameraFile = "")
    {
      Update(param, cameraFile);
    }

    Matrix4 perspectiveProjection;
    public override Matrix4 Projection => perspectiveProjection;
    public override void GLsetupViewport (int width, int height, float near = 0.01f, float far = 1000.0f)
    {
      GL.Viewport(0, 0, width, height);
      perspectiveProjection = Matrix4.CreatePerspectiveFieldOfView(Fov, width / (float)height, near, far);
      GLsetProjection();
    }

    List<Vector3> travelPoints = new List<Vector3>();

    Matrix4 computeModelView() {
      // entire animation time tracker
      double t = (Time - MinTime) / (MaxTime - MinTime);
      int subcurves = travelPoints.Count - 3;
      // select subcurve
      int i = (int) Math.Floor(t * subcurves);
      // curve segment time tracker
      double subcurveTime = (t * subcurves - i); 
      // compute target
      var target = CatmulSplineVec(travelPoints[i], travelPoints[i + 1], travelPoints[i + 2], travelPoints[i + 3], subcurveTime);
      // perform looking
      return Matrix4.LookAt(target, Center, Vector3.UnitY);
    }

    public Vector3 CatmulSplineVec(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4, double t)
      => new Vector3(
        CatmulSplinePiece(v1.X, v2.X, v3.X, v4.X, t),
        CatmulSplinePiece(v1.Y, v2.Y, v3.Y, v4.Y, t),
        CatmulSplinePiece(v1.Z, v2.Z, v3.Z, v4.Z, t)
      );

    public float CatmulSplinePiece(double p0, double p1, double p2, double p3, double t)
      => (float) (0.5d * (
        ( 0 * p0 + 2 * p1 + 0 * p2 + 0 * p3) +
        (-1 * p0 + 0 * p1 + 1 * p2 + 0 * p3) * t +
        ( 2 * p0 - 5 * p1 + 4 * p2 - 1 * p3) * t * t +
        (-1 * p0 + 3 * p1 - 3 * p2 + 1 * p3) * t * t * t
      ));

    public override Matrix4 ModelView => computeModelView();

    public override Matrix4 ModelViewInv => computeModelView().Inverted();
  }
}