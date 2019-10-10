using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class Utils
    {
        public enum BallState
        {
            weHaveBall,
            enemyHasBall,
            noOneHasBall
        }

        public enum TargetGroup
        {
            allPlayers,
            myPlayers,
            opositePlayers
        }

		protected Simulator s;
        protected TeamAI t;

        public Utils(Simulator sim, TeamAI team)
        {
            this.s = sim;
            this.t = team;
            initialize();
        }

        protected void initialize()
        {
            playground = s.getPlayground();
            enemyGoal = s.getOppositeGoal(t);
            myPlayersIDs = s.getPlayersIDs(t);
            opositePlayersIDs = s.getOpositePlayersIDs(t);
            allPlayersIDs = new List<int>(myPlayersIDs.Count + opositePlayersIDs.Count);
            allPlayersIDs.AddRange(myPlayersIDs);
            allPlayersIDs.AddRange(opositePlayersIDs);

            enemyGoalCentralPoint = new PointF(enemyGoal.X + enemyGoal.Width / 2, enemyGoal.Y + enemyGoal.Height / 2);
            Rectangle friendlyGoal = s.getGoal(t);
            ourGoalCentralPoint = new PointF(friendlyGoal.X + friendlyGoal.Width / 2, friendlyGoal.Y + friendlyGoal.Height / 2);
            locations = new Dictionary<int, PointF>(allPlayersIDs.Count);
            velocities = new Dictionary<int, PointF>(allPlayersIDs.Count);
            myPenaltyPoint = (s.getOppositeGoal(this.t).X > 150) ? s.getPlayground().firstPenaltyPoint : s.getPlayground().secondPenaltyPoint;
            enemyPenaltyPoint = (s.getOppositeGoal(this.t).X > 150) ? s.getPlayground().secondPenaltyPoint : s.getPlayground().firstPenaltyPoint;
        }

        public void update()
        {
            ballLocation.X = s.getBallLocation().X;
            ballLocation.Y = s.getBallLocation().Y;
            ballVelocity.X = s.getBallVelocity().X;
            ballVelocity.Y = s.getBallVelocity().Y;
            foreach (var item in allPlayersIDs)
            {
                locations[item] = s.getLocation(item);
                velocities[item] = s.getVelocity(item);
            }
            determineBallState();
        }

        protected Playground playground;
        protected BallState ballState = BallState.noOneHasBall, previousBallState;
        public PointF enemyGoalCentralPoint, ourGoalCentralPoint;
        protected Rectangle enemyGoal;
        
        public List<int> myPlayersIDs, opositePlayersIDs, allPlayersIDs;
        /// <summary>
        /// Contains current locations of all players indexed by their ID
        /// </summary>
        public Dictionary<int, PointF> locations;
        /// <summary>
        /// Contains current locations of all players indexed by their ID
        /// </summary>
        public Dictionary<int, PointF> velocities;
        protected int ballHolder;
        public PointF ballLocation, ballVelocity;
        public PointF myPenaltyPoint;
        public PointF enemyPenaltyPoint;

		public double getDistanceSquared(PointF from, PointF to)
        {
            return (to.X - from.X) * (to.X - from.X) + (to.Y - from.Y) * (to.Y - from.Y);
        }

		public double getDistance(PointF from, PointF to)
		{
			return Math.Sqrt(getDistanceSquared(from, to));
		}

		protected void determineBallState()
        {
            if (ballState == BallState.enemyHasBall || ballState == BallState.weHaveBall)
            {
                previousBallState = ballState;
            }
            ballState = BallState.noOneHasBall;
            foreach (var item in myPlayersIDs)
            {
                if (s.hasBall(item))
                {
                    ballState = BallState.weHaveBall;
                    ballHolder = item;
                }
            }
            if (ballState != BallState.weHaveBall)
            {
                foreach (var item in opositePlayersIDs)
                {
                    if (s.hasBall(item))
                    {
                        ballState = BallState.enemyHasBall;
                        ballHolder = item;
                    }
                }
            }
        }

        protected static PointF scale(PointF velocity, float velocityLimit)
        {
            float length = Math.Abs(velocity.X * velocity.X) + Math.Abs(velocity.Y * velocity.Y);
            if (length <= velocityLimit * velocityLimit)
                return velocity;
            else
            {
                float scaleMultiplicator = (float)(velocityLimit / Math.Sqrt(length));
                PointF result = new PointF(velocity.X * scaleMultiplicator, velocity.Y * scaleMultiplicator);
                return result;
            }
        }

        private static float evalNormalForm(float lineA, float lineB, float lineC, PointF point)
        {
            return lineA * point.X + lineB * point.Y + lineC;
        }

        private static float evalFromPoints(PointF lineStart, PointF normalVector, PointF testPoint)
        {
            float LineC = -normalVector.X * lineStart.X - normalVector.Y * lineStart.Y;
            return evalNormalForm(normalVector.X, normalVector.Y, LineC, testPoint);
        }

        private static bool isSameHalfplane(PointF lineStart, PointF normalVector, PointF testPoint1, PointF testPoint2)
        {
            float result1 = evalFromPoints(lineStart, normalVector, testPoint1),
                result2 = evalFromPoints(lineStart, normalVector, testPoint2);
            return (result1 <= 0 && result2 <= 0) || (result1 >= 0 && result2 >= 0);
        }

        private static bool isIn(PointF A, PointF B, PointF C, PointF D, PointF testPoint, PointF direction, PointF normal)
        {
            return isSameHalfplane(A, normal, testPoint, B) &&
                isSameHalfplane(B, normal, testPoint, A) &&
                isSameHalfplane(A, direction, testPoint, C) &&
                isSameHalfplane(C, direction, testPoint, A);
        }

        /// <summary>
        /// Tells you which side is in control of the ball
        /// </summary>
        /// <returns></returns>
        public BallState getBallState()
        {
            determineBallState();
            return ballState;
        }

        /// <summary>
        /// Returns ID of the player currently controling the ball.
        /// </summary>
        /// <returns></returns>
        public int getBallHoldersID()
        {
            determineBallState();
            return ballHolder;
        }

        /// <summary>
        /// Computes a velocity required to move from the point "from" to the point "to"
        /// </summary>
        /// <param name="from"></param>
        /// <param name="to"></param>
        /// <returns></returns>
        public PointF computeVelocity(PointF from, PointF to)
        {
            return new PointF(10 * (to.X - from.X), 10 * (to.Y - from.Y)); ;
        }

        /// <summary>
        /// Returns ID of a player that is closest to the given location. Only some groups of players are consideres based on the parameter "target".
        /// </summary>
        /// <param name="spot"></param>
        /// <param name="target"></param>
        /// <returns></returns>
        public int getNearestPlayer(PointF spot, TargetGroup target)
        {
            return getNearestPlayer(spot, target, -1);
        }

        /// <summary>
        /// Returns ID of a player that is closest to the given location. Only some groups of players are consideres based on the parameter "target". The player whos ID equals to "exceptThisPlayer" is not considered.
        /// </summary>
        /// <param name="spot"></param>
        /// <param name="target"></param>
        /// <param name="exceptThisPlayer"></param>
        /// <returns></returns>
        public int getNearestPlayer(PointF spot, TargetGroup target, int exceptThisPlayer)
        {
            int nearestPlayersID = -1;
            double nearestDistance = double.MaxValue;
            List<int> players = null;
            switch (target)
            {
                case TargetGroup.allPlayers:
                    players = allPlayersIDs;
                    break;
                case TargetGroup.myPlayers:
                    players = myPlayersIDs;
                    break;
                case TargetGroup.opositePlayers:
                    players = opositePlayersIDs;
                    break;
            }
            for (int i = 0; i < players.Count; i++)
            {
                if (players[i] == exceptThisPlayer)
                    continue;
                double playersDistance = getDistanceSquared(locations[players[i]], spot);
                if (playersDistance < nearestDistance)
                {
                    nearestDistance = playersDistance;
                    nearestPlayersID = players[i];
                }
            }
            return nearestPlayersID;
        }

        /// <summary>
        /// Returns true if and only if there is a path from a place "from" to a place "to" of a width of "width" that doesn't contain any enemy players.
        /// </summary>
        /// <param name="from"></param>
        /// <param name="to"></param>
        /// <param name="width"></param>
        /// <returns></returns>
        protected bool isPathFree(PointF from, PointF to, float width)
        {
            PointF directionVector = new PointF(to.X - from.X, to.Y - from.Y),
                normalVector = new PointF(directionVector.Y, -directionVector.X);
            normalVector = scale(normalVector, width);
            PointF A = new PointF(from.X + normalVector.X, from.Y + normalVector.Y),
                B = new PointF(from.X - normalVector.X, from.Y - normalVector.Y),
                C = new PointF(to.X + normalVector.X, to.Y + normalVector.Y),
                D = new PointF(to.X - normalVector.X, to.Y - normalVector.Y);

            foreach (var item in opositePlayersIDs)
            {
                PointF testPoint = locations[item];
                if (isIn(A, B, C, D, testPoint, directionVector, normalVector))
                    return false;
            }
            return true;
        }


    }
}
