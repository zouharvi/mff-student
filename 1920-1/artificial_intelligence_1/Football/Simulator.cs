using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace Football
{
    class Simulator
    {
        private static Random r = new Random();

        public Point score;
        private DrawingUnit drawer;
        private Dictionary<int, Player> players;
        private Playground pg;
        private TeamAI firstTeam, secondTeam;
        private MovingObject ball;
        private List<MovingObject> objects;
        private List<Player> activePlayers;
        private long stepsWithoutGoal = 0;

        #region Team's actions interface

        public void setPlayersData(int playersID, int data)
        {
            players[playersID].data = data;
        }

        public PointF getBallVelocity()
        {
            return ball.velocity;
        }

        public void changeVelocity(TeamAI team, int playersID, PointF newVelocity)
        {
            if (players.ContainsKey(playersID))
            {
                if (isOwnPlayer(team, playersID))
                {
                    players[playersID].setVelocity(scale(sum(scale(newVelocity, pg.maxPlayerSpeedChange),
                        players[playersID].velocity), pg.maxPlayerSpeed));
                }
            }
        }

        public List<int> getPlayersIDs(TeamAI team)
        {
            List<int> result = new List<int>();
            foreach (var item in players.Keys)
            {
                if (players[item].team.getName() == team.getName())
                    result.Add(item);
            }
            return result;
        }

        public List<int> getOpositePlayersIDs(TeamAI team)
        {
            List<int> result = new List<int>();
            foreach (var item in players.Keys)
            {
                if (players[item].team.getName() != team.getName())
                    result.Add(item);
            }
            return result;
        }

        public PointF getVelocity(int playersID)
        {
            if (players.ContainsKey(playersID))
                return players[playersID].getVelocity();
            else return new PointF();
        }

        public PointF getLocation(int playersID)
        {
            if (players.ContainsKey(playersID))
                return players[playersID].getLocation();
            else return new PointF();
        }

        public PointF getBallLocation()
        {
            return ball.getLocation();
        }

        public void moveBall(TeamAI team, int playersID, PointF newVelocity)
        {
            if (players.ContainsKey(playersID))
            {
                if (isOwnPlayer(team, playersID))
                {
                    if (players[playersID].hasBall)
                        ball.velocity = scale(newVelocity, pg.maxBallSpeed);
                }
            }
        }

        #endregion Team's actions interface

        public Simulator(PictureBox p, Playground pg, Label f, Label s, Label sc)
        {
            this.drawer = new DrawingUnit(p, pg, f, s, sc);
            this.objects = new List<MovingObject>();
            this.pg = pg;
            this.players = new Dictionary<int, Player>();
            this.score = new Point(0, 0);
            this.activePlayers = new List<Player>();
        }

        public void setTeams(TeamAI first, TeamAI second)
        {
            this.firstTeam = first;
            this.secondTeam = second;
            //((AIChampionTeam)secondTeam).addDrawer(drawer);
        }

        private float lenghtSquared(PointF vect)
        {
            return Math.Abs(vect.X * vect.X) + Math.Abs(vect.Y * vect.Y);
        }

        private PointF sum(PointF first, PointF second)
        {
            return new PointF(first.X + second.X, first.Y + second.Y);
        }

        private PointF scale(PointF velocity, float velocityLimit)
        {
            float length = lenghtSquared(velocity);
            if (length <= velocityLimit * velocityLimit)
                return velocity;
            else
            {
                float scaleMultiplicator = (float)(velocityLimit / Math.Sqrt(length));
                PointF result = new PointF(velocity.X * scaleMultiplicator, velocity.Y * scaleMultiplicator);
                return result;
            }
        }

        private bool isOwnPlayer(TeamAI team, int playersID)
        {
            return (team == firstTeam && players[playersID].isFirstTeam) ||
                (team == secondTeam && !players[playersID].isFirstTeam);
        }

        public void test()
        {
            PointF first = new PointF(200, 200),
                second = new PointF(100,100),
                test = new PointF(150,150);
            float width = 50;
            int i = 0;
            if (TeamAI.isInTest(first, second, width, test))
            {
                i++;
            }
        }

        public void start()
        {
            for (int i = 0; i < pg.playersCount; i++)
            {
                Player pl = new Player(firstTeam, pg.playerSize, true);
                players.Add(pl.ID, pl);
                objects.Add(pl);
            }
            for (int i = 0; i < pg.playersCount; i++)
            {
                Player pl = new Player(secondTeam, pg.playerSize, false);
                players.Add(pl.ID, pl);
                objects.Add(pl);
            }
            ball = new MovingObject(pg.ballColor, pg.ballSize, new PointF(pg.sizeX / 2, pg.sizeY / 2));
            objects.Add(ball);
            resetPosition();
            firstTeam.setSimulator(this);
            secondTeam.setSimulator(this);
            drawer.showScore(firstTeam, secondTeam, score);
        }

        private float distanceSquared(MovingObject p1, MovingObject p2)
        {
            return Math.Abs(p1.location.X - p2.location.X) + Math.Abs(p1.location.Y - p2.location.Y);
        }

        public Playground getPlayground()
        {
            return new Playground();
        }

        public bool hasBall(int playersID)
        {
            if (players.ContainsKey(playersID))
            {
                return players[playersID].hasBall;
            }
            return false;
        }

        public Rectangle getGoal(TeamAI team)
        {
            if (team == firstTeam)
                return pg.firstGoal;
            if (team == secondTeam)
                return pg.secondGoal;
            return new Rectangle();
        }

        public Rectangle getOppositeGoal(TeamAI team)
        {
            if (team == firstTeam)
                return pg.secondGoal;
            if (team == secondTeam)
                return pg.firstGoal;
            return new Rectangle();
        }

        public void goOneStep()
        {
            stepsWithoutGoal++;
            if (stepsWithoutGoal >= 500)
            {
                resetPosition();
                stepsWithoutGoal = 0;
            }
            activePlayers.Clear();
            foreach (Player item in players.Values)
            {
                item.hasBall = false;
                if (distanceSquared(item, ball) <= pg.ballSize * pg.ballSize)
                    activePlayers.Add(item);
            }
            if (activePlayers.Count > 0)
            {
                activePlayers[r.Next(activePlayers.Count)].hasBall = true;
            }

            firstTeam.setCommands();
            secondTeam.setCommands();

            foreach (MovingObject particle in objects)
            {
                particle.changeLoc();
                if (isGoal())
                {
                    System.Threading.Thread.Sleep(1000);
                    stepsWithoutGoal = 0;
					resetPosition(isInFirstGoal() ? 1 : 2);
                    drawer.showScore(firstTeam, secondTeam, score);
                }
                if (!pg.innerPlace.Contains(new Point((int)particle.location.X, (int)particle.location.Y)) ||
                    (isInPenalty(particle)))
                    
                {
                    particle.location.X -= 1.5f * particle.velocity.X;
                    particle.location.Y -= 1.5f * particle.velocity.Y;
                    particle.velocity.X = 0;
                    particle.velocity.Y = 0;
                }
            }
 
        }

        private bool isInPenalty(MovingObject particle)
        {
            if (particle != ball)
            {
                return pg.firstPenalty.Contains(new Point((int)particle.location.X, (int)particle.location.Y)) ||
                    pg.secondPenalty.Contains(new Point((int)particle.location.X, (int)particle.location.Y));
            }
            return false;
        }

        private void resetPosition(int team = 0)
        {
            float margins = 0.15f;
            Random r = new Random();
            foreach (var item in players.Keys)
            {
                Player p = players[item];
                do
                {
					if (p.isFirstTeam)
					{
						p.location.X = pg.sizeX / 4 + r.Next((int)(pg.sizeX / 4)) - (pg.sizeX / 8);
						p.location.Y = pg.sizeY / 2 + r.Next((int)(pg.sizeY / 2)) - (pg.sizeY / 4);
					}
					else
					{
						p.location.X = 3 * pg.sizeX / 4 + r.Next((int)(pg.sizeX / 4)) - (pg.sizeX / 8);
						p.location.Y = pg.sizeY / 2 + r.Next((int)(pg.sizeY / 2)) - (pg.sizeY / 4);
					}
                } while (isInPenalty(p));
                p.velocity.X = 0;
                p.velocity.Y = 0;
            }
			if (team == 1)
			{
				Player p = players.Where(rrr => rrr.Value.isFirstTeam).First().Value;
				p.location.X = pg.sizeX / 2;
				p.location.Y = pg.sizeY / 2;
			}
			if (team == 2)
			{
				Player p = players.Where(rrr => !rrr.Value.isFirstTeam).First().Value;
				p.location.X = pg.sizeX / 2;
				p.location.Y = pg.sizeY / 2;
			}

			ball.location.X = pg.sizeX / 2;
            ball.location.Y = pg.sizeY / 2;
            ball.velocity.X = 0;
            ball.velocity.Y = 0;
        }

        private bool isGoal()
        {
            if (pg.firstGoal.Contains(new Point((int)ball.location.X, (int)ball.location.Y)))
            {
                score.Y++;
                return true;
            }
            if (pg.secondGoal.Contains(new Point((int)ball.location.X, (int)ball.location.Y)))
            {
                score.X++;
                return true;
            }
            return false;
        }

		private bool isInFirstGoal()
		{
			return pg.firstGoal.Contains(new Point((int)ball.location.X, (int)ball.location.Y));
		}

		public void draw()
        {
            drawer.draw(objects);
        }
    }
}
