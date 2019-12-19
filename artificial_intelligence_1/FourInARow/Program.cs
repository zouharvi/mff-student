using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace FourInARow
{
    static class Program
    {
        public static Random r = new Random(); //set random seed here if needed

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
