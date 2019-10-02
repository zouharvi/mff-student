using Snake.Input;
using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.Entity
{
    class Worm
    {
        private Location location;
        private Direction heading;
        private IPlayerController controller;
        // TODO: missing constructor

        public void Move()
        {
            throw new NotImplementedException();
        }

        public void Grow(int i)
        {
            throw new NotImplementedException();
        }

        public void Die()
        {
            throw new NotImplementedException();
        }

        public bool isAlive()
        {
            throw new NotImplementedException();
        }

        public int GetGrowCount()
        {
            throw new NotImplementedException();
        }

        public Location GetHeadLocation()
        {
            return location;
        }

        public Direction GetHeading()
        {
            return heading;
        }

        public void SetHeading(Direction heading)
        {
            this.heading = heading;
        }

        public IPlayerController GetController()
        {
            return controller;
        }

        public void SetController(IPlayerController controller)
        {
            this.controller = controller;
        }
    }
}
