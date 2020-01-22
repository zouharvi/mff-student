using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class MovingObject
    {
        private static Random r = new Random();

        public int data = 0;

        private Color c;
        public Color getColor()
        {
            return c;
        }
        public PointF velocity, location;
        public PointF getVelocity()
        {
            return velocity;
        }

        public PointF getLocation()
        {
            return location;
        }
        private double radius;

        public double getRadius()
        {
            return radius;
        }

        public MovingObject()
        {
        }

        public void changeLoc()
        {
            location.X += velocity.X;
            location.Y += velocity.Y;
        }

        public MovingObject(Color c, double radius)
        {
            this.c = c;
            velocity = new PointF(0f, 0f);
            this.location = new PointF();
            this.radius = radius;
        } 

        public MovingObject(Color c, double radius, PointF loc)
        {
            this.c = c;
            velocity = new PointF(0f, 0f);
            this.location = loc;
            this.radius = radius;
        }

        public MovingObject(Color c, double radius, PointF loc, PointF vel)
        {
            this.c = c;
            velocity = new PointF(vel.X, vel.Y);
            this.location = loc;
            this.radius = radius;
        }

    }
}
