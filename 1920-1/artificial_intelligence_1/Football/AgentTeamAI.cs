using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class AgentTeamAI : TeamAI
    {
        protected List<AgentPlayer> players;
        protected List<int> playersIDs;
        protected Utils u;

        public override void setCommands()
        {
            foreach (var item in players)
            {
                item.updateInformation();
            }

            foreach (var item in players)
            {
                item.selectAction();
            }

            for (int i = 0; i < playersIDs.Count; i++)
            {
                if (s.hasBall(playersIDs[i]))
                {
                    s.moveBall(this, playersIDs[i], players[i].getIntendedBallVelocity());
                }
                s.changeVelocity(this, playersIDs[i], players[i].getIntendedVelocity());
            }
        }

        public AgentTeamAI(string name, List<AgentPlayer> players)
        {
            this.name = name;
            this.players = players;
            this.playersIDs = new List<int>();
        }

        public override void setSimulator(Simulator sim)
        {
            base.setSimulator(sim);
            u = new Utils(sim, this);
            foreach (var item in this.players)
            {
                item.setUtils(u);
            }
            playersIDs = sim.getPlayersIDs(this);
            for (int i = 0; i < u.myPlayersIDs.Count; i++)
            {
                players[i].setID(u.myPlayersIDs[i]);
            }
        }

    }
}
