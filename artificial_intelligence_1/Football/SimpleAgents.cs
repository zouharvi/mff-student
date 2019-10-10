using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class AgentSimpleDefender : AgentPlayer
    {
        public override void selectAction()
        {
            if (utils.getNearestPlayer(utils.ballLocation, Utils.TargetGroup.myPlayers) == myID)
                goToLocation(getPointBetween(utils.ballLocation, utils.ourGoalCentralPoint));
            else
                goToLocation(utils.myPenaltyPoint);
            passBallToPlayer(getNearestTeammate());
        }
    }
    class AgentSimpleOffender2 : AgentPlayer
    {
        public override void selectAction()
        {
            goToLocation(getPointBetween(utils.enemyGoalCentralPoint, getPointBetween(utils.ballLocation, utils.enemyGoalCentralPoint)));
            shootToGoal();
        }
    }

    class AgentSimpleBallSeeker : AgentPlayer
    {
        public override void selectAction()
        {
            goToLocation(utils.ballLocation);
            passBallToPlayer(getNearestTeammate());

        }
    }

    class AgentSimpleBallSeeker2 : AgentPlayer
    {
        public override void selectAction()
        {
            goToLocation(utils.ballLocation);
            shootToGoal();
        }
    }

    class AgentSimplePlayerSeeker : AgentPlayer
    {
        private int assignedEnemy = -1;
        public override void selectAction()
        {
            if(this.assignedEnemy == -1)
            {
                this.assignedEnemy = utils.opositePlayersIDs[(new Random()).Next(utils.opositePlayersIDs.Count)];
            }
            goToLocation(utils.locations[this.assignedEnemy]);
            passBallToPlayer(getNearestTeammate());
        }
    }

    class AgentSimpleOffender : AgentPlayer
    {
        public override void selectAction()
        {
            goToLocation(utils.enemyPenaltyPoint);
            shootToGoal();
        }
    } 
}
