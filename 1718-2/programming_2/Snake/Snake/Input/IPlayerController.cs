using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.Input
{
    interface IPlayerController
    {
        void Update();
        Direction GetInput();
        bool IsEndGame();
        void Reverse(long milis);
    }
}
