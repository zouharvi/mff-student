using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading.Tasks;

namespace FourInARow
{
    public partial class Form1 : Form
    {
        private GameHandler handler;
        private StartGame startForm;

        public Form1()
        {
            InitializeComponent();
            startForm = new StartGame();
            startForm.mainForm = this;
            startForm.ShowDialog();
        }

        private void Restart()
        {
            handler.Restart();
            Task t = new Task(() => handler.start(Restart));
            t.Start();
        }

        public void start(int sizeX, int sizeY, Player first, Player second)
        {
            handler = new GameHandler(first, second, sizeX, sizeY, pictureBox1);
            Restart();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            int x = ((MouseEventArgs)e).X;
            int y = ((MouseEventArgs)e).Y;
            handler.handleClick(x, y);
        }

        private void pictureBox1_SizeChanged(object sender, EventArgs e)
        {
            handler.HandleResize();
        }
    }
}
