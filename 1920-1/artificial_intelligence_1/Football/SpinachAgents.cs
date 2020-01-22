using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
	// @deprecated
	//class AgentSpinach : AgentPlayer
	//{
	//	private bool? isDefend = null;
	//	private int seed, assignedEnemy = -1;
	//	public AgentSpinach(int seed)
	//	{
	//		this.seed = seed;
	//	}

	//	public override void selectAction()
	//	{
	//		if (this.isDefend == null)
	//		{
	//			// check if is rightmost
	//			float rightD = 0;
	//			int rightI = -1;
	//			foreach (var id in utils.myPlayersIDs)
	//			{
	//				if (utils.locations[id].X > rightD)
	//				{
	//					rightD = utils.locations[id].X;
	//					rightI = id;
	//				}
	//			}

	//			if(rightI == this.myID)
	//				this.isDefend = true;
	//			else
	//				this.isDefend = false;
	//		}

	//		if ((bool)this.isDefend)
	//			this.defendRole();
	//		else
	//			this.blockRole();
	//	}

	//	private void defendRole()
	//	{
	//		const int diff = 120;
	//		if (utils.ballLocation.X > 750 && (utils.ballLocation.Y > 270 + diff || utils.ballLocation.Y < 270 - diff))
	//		{
	//			goToLocation(getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint));
	//		}
	//		else {
	//			var target = getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint);
	//			target.X = 800;
	//			goToLocation(target);

	//			// shoot left rightmost
	//			int leftmost = this.closestLeftMate();
	//			if (leftmost == this.myID)
	//			{
	//				passBallToPlayer(getNearestTeammate());
	//			}
	//			else
	//			{
	//				passBallToPlayer(leftmost);
	//			}
	//		}
	//	}

	//	private void blockRole()
	//	{
	//		if (this.assignedEnemy == -1)
	//		{
	//			//this.assignedEnemy = (new Random(this.seed)).Next(utils.opositePlayersIDs.Count);
	//			this.assignedEnemy = utils.opositePlayersIDs[seed];
	//		}

	//		var enemy = utils.locations[this.assignedEnemy];
	//		goToLocation(getPointBetweenWeighted(enemy, 6, utils.ballLocation, 1));

	//		shootClosestLeftMate();
	//	}
	//}

	class AgentSpinachDefendPass : AgentPlayer
	{
		public override void selectAction()
		{
			const int diff = 120;
			if (utils.ballLocation.X > 750 && (utils.ballLocation.Y > 270 + diff || utils.ballLocation.Y < 270 - diff))
			{
				goToLocation(getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint));
			}
			else {
				var target = getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint);
				target.X = 820;
				goToLocation(target);

				// shoot left rightmost
				int leftmost = this.closestLeftMate();
				if (leftmost == this.myID)
				{
					passBallToPlayer(getNearestTeammate());
				}
				else
				{
					passBallToPlayer(leftmost);
				}
			}
		}
	}

	// @deprecated
	//class AgentSpinachSeekPassLeftmost : AgentPlayer
	//{
	//	public override void selectAction()
	//	{
	//		var ball = utils.ballLocation;
	//		goToLocation(ball);
	//		if (ball.X < 60)
	//		{
	//			// pass right leftmost
	//			int rightmost = this.closestRightMate();
	//			passBallToPlayer(rightmost);
	//		}
	//		else
	//		{
	//			shootClosestLeftMate();
	//		}
	//	}
	//}

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
			goToLocation(getPointBetweenWeighted(enemy, 6, utils.ballLocation, 1));

			shootClosestLeftMate();
		}
	}

}
