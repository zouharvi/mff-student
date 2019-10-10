using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
	class AgentSpinachDefendPass : AgentPlayer
	{
		private int offsetY;
		public AgentSpinachDefendPass(int offsetY)
		{
			this.offsetY = offsetY;
		}
		public override void selectAction()
		{
			const int diff = 100;
			if (utils.ballLocation.X > 750 && (utils.ballLocation.Y > 270 + diff || utils.ballLocation.Y < 270 - diff))
			{
				goToLocation(getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint));
			}
			else {
				var target = getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint);
				target.X = 820;
				target.Y += this.offsetY;
				goToLocation(target);

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
		}
	}

	class AgentSpinachDefendPass2 : AgentPlayer
	{
		private int offsetY;
		public AgentSpinachDefendPass2(int offsetY)
		{
			this.offsetY = offsetY;
		}
		public override void selectAction()
		{
			var target = getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint);
			target.X = 820;
			target.Y += this.offsetY;
			goToLocation(target);

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
	}

	class AgentSpinachOffendShoot : AgentPlayer
	{
		private int offsetY;
		public AgentSpinachOffendShoot(int offsetY)
		{
			this.offsetY = offsetY;
		}

		public override void selectAction()
		{
			goToLocation(getPointBetween(utils.ballLocation, utils.enemyGoalCentralPoint));
			shootToGoal();
		}
	}

	class AgentSpinachSeekPassLeftmost : AgentPlayer
	{
		public override void selectAction()
		{
			var ball = utils.ballLocation;
			goToLocation(ball);
			if (ball.X < 60)
			{
				// pass right leftmost
				int rightmost = this.closestRightMate();
				passBallToPlayer(rightmost);
			}
			else
			{
				shootClosestLeftMate();
			}
		}
	}

	class AgentSpinachBlock : AgentPlayer
	{
		private int seed, assignedEnemy = -1;
		public AgentSpinachBlock(int seed)
		{
			this.seed = seed;
		}

		public override void selectAction()
		{
			if (this.assignedEnemy == -1)
			{
				//this.assignedEnemy = (new Random(this.seed)).Next(utils.opositePlayersIDs.Count);
				this.assignedEnemy = utils.opositePlayersIDs[seed];
			}

			var enemy = utils.locations[this.assignedEnemy];
			goToLocation(getPointBetweenWeighted(enemy, 3, utils.ballLocation, 1));

			shootClosestLeftMate();
		}
	}

}
