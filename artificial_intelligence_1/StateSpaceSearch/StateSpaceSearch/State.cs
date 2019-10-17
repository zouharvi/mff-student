using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace StateSpaceSearch
{
    class StateCostPair
    {
        public State state;
        public int cost;

        public override int GetHashCode()
        {
            return state.GetHashCode() + cost;
        }

        public StateCostPair(State s, int cost)
        {
            this.state = s;
            this.cost = cost;
        }
    }

    abstract class State
    {
        public Problem p;
        public virtual bool isFinal()
        {
            return p.isFinal(this);
        }

        public abstract void getSuccessors(List<StateCostPair> result);

        public abstract State clone();
    }

    abstract class Problem
    {
        public abstract bool isFinal(State s);

        public abstract void readFromFile(string filePath);

        public State initialState;    
    }

    abstract class Visualizer
    {
        protected PictureBox screen;
        protected Graphics g;

        public virtual void init(PictureBox p)
        {
            this.screen = p;
            screen.Image = new Bitmap(p.Width, p.Height);
            g = Graphics.FromImage(screen.Image);
        }

        protected void refresh()
        {
            screen.Refresh();
        }

        public abstract void visualize(State s);
    }

}
