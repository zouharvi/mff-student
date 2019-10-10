using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class AIRandomTeam : TeamAI
    {
        private bool IDsSet = false;
        private List<int> myplayerIDs;

        public override void setCommands()
        {
            if (!IDsSet)
                setIDs();
            foreach (var item in myplayerIDs)
            {
                if (Math.Abs(s.getVelocity(item).X) <= 0.01 || Math.Abs(s.getVelocity(item).Y) <= 0.01 || r.Next(30) == 0)
                    s.changeVelocity(this, item, new PointF(r.Next(20) - 10, r.Next(20) - 10));
                if (s.hasBall(item))
                {
                    s.moveBall(this, item, new PointF(r.Next(40) - 20, r.Next(40) - 20));
                }
            }
        }

        private void setIDs()
        {
            myplayerIDs = s.getPlayersIDs(this);
        }

        public AIRandomTeam(string name)
        {
            this.name = name;
            this.c = Color.FromArgb(r.Next(100) + 100, r.Next(255), r.Next(255));
        }

    }
}

 