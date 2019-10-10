using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Football
{
    public partial class Form1 : Form
    {
        Simulator s;
        public Form1()
        {
            InitializeComponent();

            //---- TADY JSOU CLENOVE TYMU ----
            List<AgentPlayer> agentsInTeam2 = new List<AgentPlayer>()
            {
				new AgentSpinachDefendPass(),
				//new AgentSpinachSeekPassLeftmost(),
				new AgentSpinachBlock(1),
				new AgentSpinachBlock(2),
				new AgentSpinachBlock(0),
				new AgentSpinachBlock(4),
            };

            // ---- TADY NASTAVTE JMENO VASEHO TYMU ----
            TeamAI team2 = new AgentTeamAI("Brambory se špenátem", agentsInTeam2);

			// ---- ZADNE DALSI VECI NENI POTREBA TADY MENIT ----

			s = new Simulator(pictureBox1, new Playground(), FirstTeamName_label, SecondTeamName_label, score_label);
			//TeamAI team1 = new AIZoneBasedTeam("AIZoneBasedTeam");
			//TeamAI team1 = new DistributedAI("DistributedAI");
			//TeamAI team1 = new AIShooterTeam("AIShooterTeam");

			TeamAI team1 = new DistributedAI("Barcelona FC");
            //Team team1 = new DistributedAI("Arsenal London");

            team1.setColor(Color.DarkRed);
            team2.setColor(Color.Cyan);

            s.setTeams(team1, team2);
            s.start();
            //s.test();
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            s.goOneStep();
            s.draw();
            if (s.score.X >= 50 || s.score.Y >= 50)
                timer1.Enabled = false;
        }
    }
}
