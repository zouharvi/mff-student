using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class DistributedAI : TeamAI
    {
        #region Interface Methods
        public override void setCommands()
        {
            if (!isInitialized)
            {
                initialize();
                ofensiveTarget = new PointF((enemyGoalCentralPoint.X < friendlyGoalCentralPoint.X ?
                    enemyGoalCentralPoint.X + 200 : enemyGoalCentralPoint.X - 200), enemyGoalCentralPoint.Y);
                defensiveTarget = new PointF((enemyGoalCentralPoint.X < friendlyGoalCentralPoint.X ?
                    friendlyGoalCentralPoint.X - 200 : friendlyGoalCentralPoint.X + 200), friendlyGoalCentralPoint.Y);

            }
            updatePosition();
            determineBallState();
            bestRating = double.MinValue;

            switch (ballState)
            {
                case BallState.weHaveBall:
                    waitCounter = 0;
                    passRecipient = -1;
                    foreach (var item in myPlayers)
                    {
                        selectPlayersAction(item);
                    }
                    selectBallHoldersAction(ballHolder);
                    break;
                case BallState.noOneHasBall:
                    if (previousBallState == BallState.weHaveBall && passRecipient != -1)
                    {
                        waitCounter++;
                        if (waitCounter > 300)
                        {
                            int theNearestPlayer = nearestPlayer(s.getBallLocation(), target.myPlayers);
                            s.changeVelocity(this, theNearestPlayer,
                                computeVelocity(locations[theNearestPlayer], s.getBallLocation()));
                            return;
                        }
                        s.changeVelocity(this, passRecipient, computeVelocity(locations[passRecipient], passTarget));
                        foreach (var item in myPlayers)
                        {
                            if (item == passRecipient)
                                continue;
                            selectPlayersAction(item);
                        }
                    }
                    else
                    {
                        goToDefence();
                    }
                    break;
                case BallState.enemyHasBall:
                    goToDefence();
                    break;
            }
                    
        }

        #endregion

        #region Properties

        private Dictionary<int, double> playersRatings;
        private double bestRating;
        private int bestRated;
        private PointF passTarget;
        private int passRecipient,
            waitCounter = 0;
        private PointF ofensiveTarget, defensiveTarget;
        private PointF[] directions = new PointF[]
            {
                new PointF(0, 10),
                new PointF(10, 10),
                new PointF(10, 0),
                new PointF(10, -10),
                new PointF(-10, 0),
                new PointF(-10, 10),
                new PointF(0, -10),
                new PointF(-10, -10),
                new PointF(10, 5),
                new PointF(10, -5),
                new PointF(5, 10),
                new PointF(5, -10),
                new PointF(-5, 10),
                new PointF(-5, -10),
                new PointF(-10, 5),
                new PointF(-10, -5)
            };

        #endregion Properties

        private bool isInside(PointF pointF)
        {
            return pointF.X > 0 && pointF.Y > 0 && pointF.X < s.getPlayground().sizeX && pointF.Y < s.getPlayground().sizeY;
        }

        private void goToDefence()
        {
            waitCounter = 0;
            passRecipient = -1;
            int theNearestPlayer = nearestPlayer(s.getBallLocation(), target.myPlayers);
            if (Math.Abs(friendlyGoalCentralPoint.X - locations[theNearestPlayer].X) >
                Math.Abs(s.getBallLocation().X - friendlyGoalCentralPoint.X))
            {
                PointF directionToBall = computeVelocity(locations[theNearestPlayer], s.getBallLocation());
                directionToBall.X = -directionToBall.X;
                directionToBall.Y = -directionToBall.Y;
                s.changeVelocity(this, theNearestPlayer, directionToBall);
            }
            else
            {
                s.changeVelocity(this, theNearestPlayer,
                    computeVelocity(locations[theNearestPlayer], s.getBallLocation()));
            }
            int defender = nearestPlayer(friendlyGoalCentralPoint, target.myPlayers);
            s.changeVelocity(this, defender, computeVelocity(locations[defender],
                new PointF((defensiveTarget.X + friendlyGoalCentralPoint.X) / 2, defensiveTarget.Y )));

            foreach (var item in myPlayers)
            {
                if (item == theNearestPlayer || item == defender)
                    continue;
                selectPlayersAction(item);
            }
        }

        private void selectPlayersAction(int playersID)
        {
            PointF currentLoc = new PointF(locations[playersID].X, locations[playersID].Y);
            double currentBestRating = double.MinValue;
            PointF bestDirection = new PointF();
            foreach (var item in directions)
            {
                locations[playersID] = new PointF(currentLoc.X + item.X, currentLoc.Y + item.Y);
                if (!isInside(locations[playersID]))
                    continue;
                double rating = getPlayersRating(playersID);
                if (rating > currentBestRating)
                {
                    currentBestRating = rating;
                    bestDirection = item;
                }
            }
            locations[playersID] = currentLoc;
            if (bestRating < currentBestRating)
            {
                bestRating = currentBestRating;
                bestRated = playersID;
            }
            playersRatings[playersID] = getPlayersRating(playersID); ;
            s.setPlayersData(playersID, (int)playersRatings[playersID]);
            playersTargets[playersID] = new PointF(currentLoc.X + bestDirection.X, currentLoc.Y + bestDirection.Y);
            if (playersID != ballHolder)
                s.changeVelocity(this, playersID, computeVelocity(currentLoc, playersTargets[playersID]));
        }

        private void selectBallHoldersAction(int playersID)
        {
            if (shouldShoot(playersID))
            {
                shoot(playersID);
                return;
            }
            
            if (bestRated != playersID)
            {
                s.moveBall(this, playersID, computeVelocity(s.getBallLocation(), playersTargets[bestRated]));
                passRecipient = bestRated;
                passTarget = playersTargets[passRecipient];
                return;
            }
            PointF desiredVelocity = computeVelocity(locations[playersID], playersTargets[playersID]);
            s.changeVelocity(this, playersID, desiredVelocity);
            PointF realVelocity = scale(sum(scale(desiredVelocity, s.getPlayground().maxPlayerSpeedChange),
                        velocities[playersID]), s.getPlayground().maxPlayerSpeed); 
            s.moveBall(this, playersID, realVelocity);
        }

        private bool shouldShoot(int playersID)
        {
            return isPathFree(locations[playersID], enemyGoalCentralPoint, 50);
        }

        private double getPlayersRating(int playersID)
        {
            if (ballState == BallState.weHaveBall || 
                (ballState == BallState.noOneHasBall && previousBallState == BallState.weHaveBall))
                return computePlayersOffensiveRating(playersID);
            return computePlayersDefensiveRating(playersID);
        }

        private double computePlayersOffensiveRating(int playersID)
        {
            double result = 0,
                distanceToGoal = 2 * Math.Sqrt(getDistanceSquared(ofensiveTarget, locations[playersID])) +
                0.5 * Math.Abs(ofensiveTarget.Y - locations[playersID].Y);
            result -= distanceToGoal;

            int nearestEnemyPlayer = nearestPlayer(locations[playersID], target.opositePlayers);
            double nearestEnemyDistance = getDistanceSquared(locations[playersID], locations[nearestEnemyPlayer]);
            result -= 2000000 / nearestEnemyDistance;

            int theNearestAlly = nearestPlayer(locations[playersID], target.myPlayers, playersID);
            double nearestAllyDistance =getDistanceSquared(locations[playersID], locations[theNearestAlly]);
            result -= 2000000 / nearestAllyDistance;
            
            result += 1000;
            if (!isPathFree(s.getBallLocation(), locations[playersID], 50))
                result -= 2000;
            return result;
        }

        private double computePlayersDefensiveRating(int playersID)
        {
            double result = 0,
                distanceXtointercept = Math.Abs((defensiveTarget.X + s.getBallLocation().X) / 2
                - locations[playersID].X);
                //ballsDistanceXToGoal = Math.Abs(friendlyGoalCentralPoint.X - s.getBallLocation().X);
            result += 2 * (500 - distanceXtointercept);
            int theNearestAlly = nearestPlayer(locations[playersID], target.myPlayers, playersID);
            result -= 2000000 / getDistanceSquared(locations[playersID], locations[theNearestAlly]);
            int theNearestEnemy = nearestPlayer(locations[playersID], target.opositePlayers);
            result += 2000000 / getDistanceSquared(locations[playersID], locations[theNearestEnemy]);

            return result;
        }

        public DistributedAI(string name)
        {
            playersRatings = new Dictionary<int, double>();
            previousBallState = BallState.enemyHasBall;
            this.name = name;
            this.bestRated = -1;
            this.bestRating = double.MinValue;
            c = Color.FromArgb(r.Next(100), r.Next(200), r.Next(255));
        }

    }
}
