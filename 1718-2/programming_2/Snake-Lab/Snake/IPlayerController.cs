using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    interface IPlayerController
    {
        void Update();
        Direction GetInput();
        void ReverseInput();
        bool IsEndGame();
    }
}
