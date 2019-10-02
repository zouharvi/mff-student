using System;
using System.Collections.Generic;
using System.Text;

namespace Snake.Input
{
    sealed class Keyboard : KeyboardController
    {
        // TODO: Missing constructor
        public bool HasKey()
        {
            throw new NotImplementedException();
        }

        public ConsoleKeyInfo GetKey()
        {
            throw new NotImplementedException();
        }

        private Keyboard()
        {
            throw new NotImplementedException();
        }

        private static Keyboard instance;

        public static Keyboard Instance
        {
            get
            {
                if (instance == null)
                    instance = new Keyboard();
                return instance;
            }
        }
    }
}
