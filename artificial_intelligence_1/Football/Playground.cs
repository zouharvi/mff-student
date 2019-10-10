using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Football
{
    class Playground
    {
        public int sizeX, sizeY, playersCount, goalSize, timelimit;
        public Color backColor = Color.Green, ballColor = Color.Red;
        public int playerSize, ballSize;
        public float maxPlayerSpeed, maxPlayerSpeedChange, maxBallSpeed, maxPlayerSpeedSquared, maxBallSpeedSquared;
        public Rectangle firstGoal, secondGoal, innerPlace, firstPenalty, secondPenalty;
        public PointF firstPenaltyPoint, secondPenaltyPoint;

        public Playground()
        {
            this.sizeY = 540;
            this.sizeX = 900;
            this.playersCount = 5;
            this.goalSize = 66;
            this.timelimit = 5;
            this.playerSize = 10;
            this.ballSize = 5;
            this.maxPlayerSpeed = 5;
            this.maxPlayerSpeedChange = 1;
            this.maxBallSpeed = 15;
            this.maxPlayerSpeedSquared = maxPlayerSpeed * maxPlayerSpeed;
            this.maxBallSpeedSquared = maxBallSpeed * maxBallSpeed;
            this.firstGoal = new Rectangle(-15, sizeY / 2 - goalSize / 2, 16, goalSize);
            this.secondGoal = new Rectangle(sizeX - 1, sizeY / 2 - goalSize / 2, 16, goalSize);
            this.innerPlace = new Rectangle(-2, -2, sizeX + 2, sizeY + 2);
            this.firstPenalty = new Rectangle(0, sizeY / 2 - goalSize / 2 - 50, 50, goalSize + 100);
            this.secondPenalty = new Rectangle(sizeX - 50, sizeY / 2 - goalSize / 2 - 50, 50, goalSize + 100);
            this.firstPenaltyPoint = new PointF(firstPenalty.X + firstPenalty.Width + 50, firstPenalty.Y + firstPenalty.Height / 2);
            this.secondPenaltyPoint = new PointF(secondPenalty.X - 50, secondPenalty.Y + secondPenalty.Height / 2);
        }

    }
}
