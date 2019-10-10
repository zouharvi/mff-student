using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class AIZoneBasedTeam : TeamAI
    {
        private List<Point> defencePositions, ofencePositions;

        #region Interface methods

        public override void setCommands()
        {
            if (!isInitialized)
            {
                initialize();
                computeNavPointsLocations();
            }

            alreadySet.Clear();
            updatePosition();
            findFreePlayer();

            determineBallState();
            switch (ballState)
            {
                case BallState.enemyHasBall:
                case BallState.noOneHasBall:
                    int theNearestPlayer = nearestPlayer(s.getBallLocation(), target.myPlayers);
                    s.changeVelocity(this, theNearestPlayer, computeVelocity(locations[theNearestPlayer], s.getBallLocation()));
                    goToDefence(theNearestPlayer);
                    break;
                case BallState.weHaveBall:
                    if (getDistanceSquared(locations[ballHolder], enemyGoalCentralPoint) >
                        playground.sizeX / 3 * playground.sizeX / 3 ||
                        Math.Abs(locations[ballHolder].X - enemyGoalCentralPoint.X) < 200)
                    {
                        if (nearestEnemyDistance(locations[ballHolder]) < 5500 
                            && locations[nearestPlayer(locations[ballHolder], target.opositePlayers)].X <
                            locations[ballHolder].X)
                        {
                            int targetPlayer// = nearestPlayer(locations[ballHolder], ballHolder);
                                             = freePlayer;

                            PointF passPoint = new PointF(locations[targetPlayer].X,
                                   locations[targetPlayer].Y);

                            playersTargets[targetPlayer] = new Point((int)passPoint.X, (int)passPoint.Y);
                            alreadySet.Add(targetPlayer);
                            s.moveBall(this, ballHolder, computeVelocity(locations[ballHolder], passPoint));
                        }
                        else
                        {
                            s.changeVelocity(this, ballHolder, computeVelocity(locations[ballHolder],
                                enemyGoalCentralPoint));
                            s.moveBall(this, ballHolder, computeVelocity(locations[ballHolder],
                                enemyGoalCentralPoint, playground.maxPlayerSpeed * 0.95f));
                            alreadySet.Add(ballHolder);
                        }
                    }
                    else s.moveBall(this, ballHolder, computeVelocity(locations[ballHolder],
                                enemyGoalCentralPoint));
                    goToOfence(ballHolder);
                    break;
                    /*
                case BallState.noOneHasBall:
                    int playerToGetBall = -1;
                    PointF ballTrajectory = s.getBallLocation(),
                        ballVelocity = s.getBallVelocity(),
                        originalPosition = s.getBallLocation();
                    if (ballVelocity.X != 0 || ballVelocity.Y != 0)
                        for (int i = 0; i < 150000; i++)
                        {
                            ballTrajectory.X += ballVelocity.X;
                            ballTrajectory.Y += ballVelocity.Y;
                            theNearestPlayer = nearestPlayer(ballTrajectory, target.allPlayers);
                            if (getDistanceSquared(locations[theNearestPlayer], ballTrajectory) <
                                Math.Pow(ballVelocity.X * ballVelocity.X + ballVelocity.Y * ballVelocity.Y / playground.maxPlayerSpeed, 6) *
                                getDistanceSquared(originalPosition, ballTrajectory) * 4.5)
                            {
                                playerToGetBall = theNearestPlayer;
                                ballTrajectory.X += 4 * ballVelocity.X;
                                ballTrajectory.Y += 4 * ballVelocity.Y;
                                break;
                            }
                        }
                    else
                    {
                        playerToGetBall = nearestPlayer(originalPosition, target.allPlayers);
                    }
                    if (playerToGetBall != -1 && myPlayers.Contains(playerToGetBall))
                    {
                        playersTargets[playerToGetBall] = new Point((int)ballTrajectory.X, (int)ballTrajectory.Y);
                        alreadySet.Add(playerToGetBall);
                        goToTargets();
                    }
                    else
                    {
                        goToTargets();
                    }
                    
                    break;*/
            }
        }

        #endregion Interface methods

        private void computeNavPointsLocations()
        {
            defencePositions = new List<Point>();
            ofencePositions = new List<Point>();

            List<Point> tepm1 = new List<Point>(),
                tepm2 = new List<Point>();

            int widthDivision = 5,
                heightDiviion = 6,
                widthPiece = playground.sizeX / (widthDivision * 2),
                heightPiece = playground.sizeY / heightDiviion,
                halfWidth = playground.sizeX / 2;

            for (int i = 0; i <= widthDivision; i += 2)
            {
                for (int j = 0; j <= heightDiviion; j += 3)
                {
                    tepm1.Add(new Point(i * widthPiece, j * heightPiece));
                    tepm2.Add(new Point(i * widthPiece + halfWidth, j * heightPiece));
                }
            }
            if (enemyGoal.X > 100)
            {
                defencePositions = tepm1;
                ofencePositions = tepm2;
            }
            else
            {
                defencePositions = tepm2;
                ofencePositions = tepm1;
            }
        }

        private bool isClearToPass(PointF from, PointF to)
        {
            return false;
        }

        private void goToTargets()
        {
            foreach (var item in playersTargets.Keys)
            {
                s.changeVelocity(this, item, computeVelocity(locations[item],
                    new PointF(playersTargets[item].X, playersTargets[item].Y)));
            }
        }

        private void goToOfence(int exceptThisPlayer)
        {
            if (!hasBallStateChanged())
            {
                goToTargets();
                return;
            }
            List<Point> positions = new List<Point>(ofencePositions);
            playersTargets.Clear();
            for (int i = 0; i < myPlayers.Count; i++)
            {
                if (myPlayers[i] == exceptThisPlayer || alreadySet.Contains(myPlayers[i]))
                    continue;
                int randomIndex = r.Next(positions.Count);
                s.changeVelocity(this, myPlayers[i],
                    computeVelocity(locations[myPlayers[i]], positions[randomIndex]));
                playersTargets.Add(myPlayers[i], positions[randomIndex]);
                positions.RemoveAt(randomIndex);
            }
        }

        private void goToDefence(int exceptThisPlayer)
        {
            if (!hasBallStateChanged())
            {
                goToTargets();
                return;
            }
            List<Point> positions = new List<Point>(defencePositions);
            playersTargets.Clear();
            //int defender = nearestPlayer(friendlyGoalCentralPoint, target.myPlayers);
            //s.changeVelocity(this, defender, computeVelocity(locations[defender], friendlyGoalCentralPoint));
            for (int i = 0; i < myPlayers.Count; i++)
            {
                if (myPlayers[i] == exceptThisPlayer || alreadySet.Contains(myPlayers[i]))// || myPlayers[i] == defender)
                    continue;
                //s.changeVelocity(this, myPlayers[i], computeVelocity(locations[myPlayers[i]],
                //    new PointF((int)(s.getBallLocation().X + locations[myPlayers[i]].X + 5 * r.NextDouble()) / 2, (int)(s.getBallLocation().Y + locations[myPlayers[i]].Y + 5 * r.NextDouble()) / 2)));
                //continue;

                int randomIndex = r.Next(positions.Count);
                s.changeVelocity(this, myPlayers[i],
                    computeVelocity(locations[myPlayers[i]], positions[randomIndex]));
                playersTargets.Add(myPlayers[i], positions[randomIndex]);
                positions.RemoveAt(randomIndex);
            }

        }

        private void findFreePlayer()
        {
            double best = double.MinValue;
            foreach (var item in myPlayers)
            {
                if (item == ballHolder && ballState == BallState.weHaveBall)
                    continue;
                double goodToPass = 2 * nearestEnemyDistance(locations[item]) -
                    getDistanceSquared(locations[item], enemyGoalCentralPoint);
                if (goodToPass > best)
                {
                    freePlayer = item;
                    best = goodToPass;
                }
            }
        }

        public AIZoneBasedTeam(string name)
        {
            this.name = name;
            this.c = Color.Gold;
            this.c = Color.FromArgb(r.Next(100), r.Next(200), r.Next(255));
        }
    }
}
