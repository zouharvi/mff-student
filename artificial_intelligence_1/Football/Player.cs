using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class Player : MovingObject
    {
        private static int IDCounter = 0;

        public int ID;
        public bool hasBall = false, isFirstTeam;
        public TeamAI team;

        public void setVelocity(PointF newVelocity)
        {
            this.velocity = newVelocity;
        }

        public Player(TeamAI team, double radius, bool isFirstTeam)
            : base(team.getColor(), radius)
        {
            this.ID = IDCounter++;
            this.team = team;
            this.isFirstTeam = isFirstTeam;
        }

        public Player(TeamAI team, double radius, PointF loc, bool isFirstTeam)
            : base(team.getColor(), radius, loc)
        {
            this.ID = IDCounter++;
            this.team = team;
            this.isFirstTeam = isFirstTeam;
        }
    }
}
