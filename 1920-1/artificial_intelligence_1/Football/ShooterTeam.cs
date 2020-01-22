using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class AIShooterTeam : TeamAI
    {
        public override void setCommands()
        {
            if (!isInitialized)
                initialize();

            foreach (var item in myPlayers)
            {
                PointF playersLocation = s.getLocation(item),
                    playersVelocity = s.getVelocity(item);
                if (s.hasBall(item))
                {
                    if (r.Next(7) == 0)
                        s.moveBall(this, item, new PointF(r.Next(40) - 20, r.Next(40) - 20));
                    else
                        s.moveBall(this, item, computeVelocity(playersLocation, enemyGoalCentralPoint));
                }
                else
                {
                    if (r.Next(20) == 0)
                        s.changeVelocity(this, item, computeVelocity(playersLocation, s.getBallLocation()));
                    else
                    {
                        if (r.Next(10) == 0)
                            s.changeVelocity(this, item, new PointF(playersVelocity.X + r.Next(10) - 5, 
                                playersVelocity.Y + r.Next(10) - 5));
                    }
                }
            }
        }

        public AIShooterTeam(string name)
        {
            this.name = name;
            this.c = Color.Black;
        }
    }
}
