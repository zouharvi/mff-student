using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    abstract class TeamAI
    {
        #region Interface methods
        public virtual Color getColor()
        {
            return c;
        }
        public virtual String getName()
        {
            return name;
        }
        public Simulator s;

        public virtual void setSimulator(Simulator sim)
        {
            this.s = sim;
        }

        public abstract void setCommands();
        #endregion Interface methods

        public enum BallState
        {
            weHaveBall,
            enemyHasBall,
            noOneHasBall
        }

        public enum target
        {
            allPlayers,
            myPlayers,
            opositePlayers
        }

        /*
        protected PointF? collisionCourse(PointF myLoc, PointF targetLoc, PointF targetVelocity, double velocityLimit)
        {
            return null;
        }
        */

        #region Properties
        protected static Random r = new Random();
        protected Playground playground;
        protected Color c;
        protected string name;
        protected bool isInitialized = false;
        protected int ballHolder = 0, freePlayer;
        protected BallState ballState = BallState.noOneHasBall, previousBallState;
        protected PointF enemyGoalCentralPoint, friendlyGoalCentralPoint;
        protected Rectangle enemyGoal;
        protected List<int> myPlayers, opositePlayers, allPlayers, alreadySet;
        protected Dictionary<int, PointF> locations, velocities, playersTargets;
        #endregion Properties

        #region AI low level

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


        #endregion AI low level

        #region Test Methods

        public static bool isInTest(PointF from, PointF to, float width, PointF test)
        {
            PointF directionVector = new PointF(to.X - from.X, to.Y - from.Y),
                normalVector = new PointF(directionVector.Y, -directionVector.X);
            normalVector = scale(normalVector, width);
            PointF A = new PointF(from.X + normalVector.X, from.Y + normalVector.Y),
                B = new PointF(from.X - normalVector.X, from.Y - normalVector.Y),
                C = new PointF(to.X + normalVector.X, to.Y + normalVector.Y),
                D = new PointF(to.X - normalVector.X, to.Y - normalVector.Y);

            return isIn(A, B, C, D, test, directionVector, normalVector);
        }

        #endregion Test Methods

        #region AI Support

        protected PointF sum(PointF first, PointF second)
        {
            return new PointF(first.X + second.X, first.Y + second.Y);
        }

        protected bool isPathFree(PointF from, PointF to, float width)
        {
            PointF directionVector = new PointF(to.X - from.X, to.Y - from.Y),
                normalVector = new PointF(directionVector.Y, -directionVector.X);
            normalVector = scale(normalVector, width);
            PointF A = new PointF(from.X + normalVector.X, from.Y + normalVector.Y),
                B = new PointF(from.X - normalVector.X, from.Y - normalVector.Y),
                C = new PointF(to.X + normalVector.X, to.Y + normalVector.Y),
                D = new PointF(to.X - normalVector.X, to.Y - normalVector.Y);

            foreach (var item in opositePlayers)
            {
                PointF testPoint = locations[item];
                if (isIn(A, B, C, D, testPoint, directionVector, normalVector))
                    return false;
            }
            return true;
        }

        protected PointF computeVelocity(PointF from, PointF to)
        {
            return new PointF(10 * (to.X - from.X), 10 * (to.Y - from.Y)); ;
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

        protected PointF computeVelocity(PointF from, PointF to, float velocityLimit)
        {
            return scale(new PointF(10 * (to.X - from.X), 10 * (to.Y - from.Y)), velocityLimit);
        }

        protected double getDistanceSquared(PointF from, PointF to)
        {
            return (to.X - from.X) * (to.X - from.X) + (to.Y - from.Y) * (to.Y - from.Y);
        }

        protected double nearestEnemyDistance(PointF spot)
        {
            int nearestPlayersID = -1;
            double nearestDistance = double.MaxValue;
            for (int i = 0; i < opositePlayers.Count; i++)
            {
                double playersDistance = getDistanceSquared(locations[opositePlayers[i]], spot);
                if (playersDistance < nearestDistance)
                {
                    nearestDistance = playersDistance;
                    nearestPlayersID = myPlayers[i];
                }
            }
            return nearestDistance;
        }

        protected int nearestPlayer(PointF spot, target target)
        {
            return nearestPlayer(spot, target, -1);
        }

        protected int nearestPlayer(PointF spot, target target, int exceptThisPlayer)
        {
            int nearestPlayersID = -1;
            double nearestDistance = double.MaxValue;
            List<int> players = null;
            switch (target)
            {
                case target.allPlayers:
                    players = allPlayers;
                    break;
                case target.myPlayers:
                    players = myPlayers;
                    break;
                case target.opositePlayers:
                    players = opositePlayers;
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

        protected bool hasBallStateChanged()
        {
            return previousBallState != ballState;
        }

        protected void determineBallState()
        {
            if (ballState == BallState.enemyHasBall || ballState == BallState.weHaveBall)
            {
                previousBallState = ballState;
            }
            ballState = BallState.noOneHasBall;
            foreach (var item in myPlayers)
            {
                if (s.hasBall(item))
                {
                    ballState = BallState.weHaveBall;
                    ballHolder = item;
                }
            }
            if (ballState != BallState.weHaveBall)
            {
                foreach (var item in opositePlayers)
                {
                    if (s.hasBall(item))
                    {
                        ballState = BallState.enemyHasBall;
                        ballHolder = item;
                    }
                }
            }
        }

        protected void updatePosition()
        {
            foreach (var item in allPlayers)
            {
                locations[item] = s.getLocation(item);
                velocities[item] = s.getVelocity(item);
            }
        }

        protected void shoot(int playersID)
        {
            s.moveBall(this, playersID, computeVelocity(s.getBallLocation(), enemyGoalCentralPoint));
        }

        #endregion AI Support

        protected void initialize()
        {
            playground = s.getPlayground();
            enemyGoal = s.getOppositeGoal(this);
            myPlayers = s.getPlayersIDs(this);
            opositePlayers = s.getOpositePlayersIDs(this);
            allPlayers = new List<int>(myPlayers.Count + opositePlayers.Count);
            allPlayers.AddRange(myPlayers);
            allPlayers.AddRange(opositePlayers);

            enemyGoalCentralPoint = new PointF(enemyGoal.X + enemyGoal.Width / 2, enemyGoal.Y + enemyGoal.Height / 2);
            Rectangle friendlyGoal = s.getGoal(this);
            friendlyGoalCentralPoint = new PointF(friendlyGoal.X + friendlyGoal.Width / 2, friendlyGoal.Y + friendlyGoal.Height / 2);
            locations = new Dictionary<int, PointF>(allPlayers.Count);
            velocities = new Dictionary<int, PointF>(allPlayers.Count);

            alreadySet = new List<int>();
            playersTargets = new Dictionary<int, PointF>();
            this.isInitialized = true;
        }

        public void setColor(Color c)
        {
            this.c = c;
        }

        public void addDrawer(DrawingUnit d)
        {
            initialize();
            //d.drawPoints(defencePositions);
        }
    }
}
