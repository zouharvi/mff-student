using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    abstract class AgentPlayer
    {
        protected PointF intendedVelocity, intendedBallVelocity;
        protected Utils utils;
        protected int myID;

        public PointF getIntendedVelocity()
        {
            return intendedVelocity;
        }

        public PointF getIntendedBallVelocity()
        {
            return intendedBallVelocity;
        }

        public void updateInformation()
        {
            utils.update();
        }

        public void setUtils(Utils u)
        {
            this.utils = u;
        }

        public void setID(int ID)
        {
            this.myID = ID;
        }

        public abstract void selectAction();

        public AgentPlayer()
        {
            this.intendedBallVelocity = new PointF(0, 0);
            this.intendedVelocity = new PointF(0, 0);
        }

        protected void goToLocation(PointF location)
        {
            this.intendedVelocity = utils.computeVelocity(utils.locations[myID], location);
        }

        protected void shootToGoal()
        {
            this.intendedBallVelocity = utils.computeVelocity(utils.locations[myID], utils.enemyGoalCentralPoint);
        }

        protected void passBallToPlayer(int playerID)
        {
            this.intendedBallVelocity = utils.computeVelocity(utils.locations[myID], utils.locations[playerID]);
        }

        protected int getNearestTeammate()
        {
            return utils.getNearestPlayer(utils.locations[myID], Utils.TargetGroup.myPlayers, myID);
        }

		protected PointF getPointBetween(PointF first, PointF second)
		{
			return new PointF((first.X + second.X) / 2, (first.Y + second.Y) / 2);
		}

		protected PointF getPointBetweenWeighted(PointF first, float w1, PointF second, float w2)
		{
			return new PointF((first.X*w1 + second.X*w2) / (w1+w2), (first.Y*w1 + second.Y*w2) / (w1+w2));
		}

		protected int closestLeftMate()
		{
			int leftmost = this.myID;
			var myPos = utils.locations[this.myID];
			double minDiff = 9999;
			foreach (var id in utils.myPlayersIDs)
			{
				if (id == this.myID)
					continue;
				var location = utils.locations[id];
				if (location.X < myPos.X && utils.getDistance(myPos, location) < minDiff)
				{
					minDiff = utils.getDistance(myPos, location);
					leftmost = id;
				}
			}
			return leftmost;
		}

		protected void shootClosestLeftMate()
		{
			// shoot left rightmost
			int leftmost = this.closestLeftMate();
			if (leftmost == this.myID)
			{
				shootToGoal();
			}
			else
			{
				passBallToPlayer(leftmost);
			}
		}

		protected int closestRightMate()
		{
			int rightmost = this.myID;
			var myPos = utils.locations[this.myID];
			double minDiff = 9999;
			foreach (var id in utils.myPlayersIDs)
			{
				if (id == this.myID)
					continue;
				var location = utils.locations[id];
				if (location.X > myPos.X && utils.getDistance(myPos, location) < minDiff)
				{
					minDiff = utils.getDistance(myPos, location);
					rightmost = id;
				}
			}
			return rightmost;
		}

		protected void shootClosestRightMate()
		{
			// shoot left rightmost
			int rightmost = this.closestLeftMate();
			if (rightmost == this.myID)
			{
				shootToGoal();
			}
			else
			{
				passBallToPlayer(rightmost);
			}
		}

		protected int rightMostEnemy()
		{
			int rightmost = -1;
			double pos = 0;
			foreach (var id in utils.opositePlayersIDs)
			{
				var location = utils.locations[id];
				if (location.X > pos)
				{
					pos = location.X;
					rightmost = id;
				}
			}
			return rightmost;
		}
    }
}
