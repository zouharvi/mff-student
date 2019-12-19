using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FourInARow
{
    public abstract class Player
    {
		/// <summary>
		/// This method should return an index of column in which the player want to place its piece in current position. Calling this method doesn't change the current position.
		/// </summary>
		/// <returns></returns>
        public abstract int selectMove();

		/// <summary>
		/// This tells the player that somebody (this player, the oposite player, or someone else) changed the current game possition by playing a move. The next calling of selectMove will assume that the move corresponds to the UPDATED position.
		/// This is typically called after some player made a move (either to inform the player that the oponent made move, or to confirm that player's move was accepted and played on the board.
		/// </summary>
		/// <param name="isThisPlayer"></param>
		/// <param name="column"></param>
		public abstract void playMove(bool isThisPlayer, int column);

        public abstract string getName();

		/// <summary>
		/// In computer engines, this should be implemented with an empty body.
		/// Should only be implemented for human players that use mouse to input moves.
		/// </summary>
		/// <param name="column"></param>
        public abstract void handleClick(int column);

        public virtual void Reset()
        {
            //nothing here by default
        }
    }

    class HumanPlayer : Player
    {
        private int move = -1;
        public override void handleClick(int column)
        {
            move = column;
        }

        public override int selectMove()
        {
            while (move < 0)
            {

            }
            int copy = move;
            move = -1;
            return copy;
        }

        public override void playMove(bool isThisPlayer, int column)
        {
            //nothing here
        }

        public override string getName()
        {
            return "human";
        }
    }

    class RandomPlayer : Player
    {
        int sizeX, sizeY;
        int[] freeTiles;
        List<int> possibleMoves;
        static Random r = new Random();

        public override int selectMove()
        {
            //System.Threading.Thread.Sleep(100);
            return possibleMoves[r.Next(possibleMoves.Count)];
        }

        public override void Reset()
        {
            this.freeTiles = new int[sizeX];
            this.possibleMoves = new List<int>();
            for (int i = 0; i < sizeX; i++)
            {
                freeTiles[i] = sizeY;
                possibleMoves.Add(i);
            }
            base.Reset();
        }

        public override void playMove(bool isThisPlayer, int column)
        {
            freeTiles[column]--;
            if (freeTiles[column] == 0)
                possibleMoves.Remove(column);
        }

        public override string getName()
        {
            return "Random Engine";
        }

        public RandomPlayer(int sizeX, int sizeY)
        {
            this.sizeX = sizeX;
            this.sizeY = sizeY;
            Reset();
        }

        public override void handleClick(int column)
        {
            //nothing here
        }
    }

}
