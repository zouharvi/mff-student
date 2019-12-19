using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FourInARow
{
    public partial class StartGame : Form
    {
        public int sizeX, sizeY;
        public Player first, second;
        public Form1 mainForm;

        public StartGame()
        {
            InitializeComponent();
        }

        private void RedMainComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (RedMainComboBox.Text)
            {
                case "Monte Carlo engine":
                    RedAddLabel.Text = "Simulations:";
                    RedAddComboBox.Items.Clear();
                    RedAddComboBox.Items.Add("500");
                    RedAddComboBox.Items.Add("1000");
                    RedAddComboBox.Items.Add("2000");
                    RedAddComboBox.Items.Add("3000");
                    RedAddComboBox.Items.Add("4000");
                    RedAddComboBox.Items.Add("5000");
                    RedAddComboBox.Items.Add("7000");
                    RedAddComboBox.Items.Add("9000");
                    RedAddComboBox.Items.Add("11000");
                    RedAddComboBox.Items.Add("15000");
                    RedAddComboBox.Items.Add("25000");
                    RedAddComboBox.Enabled = true;
                    RedAddComboBox.Text = "5000";
                    break;

                case "Random engine":
                case "Human":
                    RedAddLabel.Text = "";
                    RedAddComboBox.Text = "";
                    RedAddComboBox.Enabled = false;
                    break;

                case "Alpha-Beta engine":
				case "Alpha-Beta engine EXPERIMENTAL":
					RedAddLabel.Text = "Depth:";
                    RedAddComboBox.Items.Clear();
                    RedAddComboBox.Items.Add("1");
                    RedAddComboBox.Items.Add("2");
                    RedAddComboBox.Items.Add("3");
                    RedAddComboBox.Items.Add("4");
                    RedAddComboBox.Items.Add("5");
                    RedAddComboBox.Items.Add("6");
                    RedAddComboBox.Items.Add("7");
                    RedAddComboBox.Items.Add("8");
                    RedAddComboBox.Items.Add("9");
                    RedAddComboBox.Enabled = true;
                    RedAddComboBox.Text = "3";
                    break;
            }
        }

        private void BlueMainComboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (BlueMainComboBox2.Text)
            {
                case "Monte Carlo engine":
                    BlueAddLabel.Text = "Simulations:";
                    BlueAddComboBox.Items.Clear();
                    BlueAddComboBox.Items.Add("500");
                    BlueAddComboBox.Items.Add("1000");
                    BlueAddComboBox.Items.Add("2000");
                    BlueAddComboBox.Items.Add("3000");
                    BlueAddComboBox.Items.Add("4000");
                    BlueAddComboBox.Items.Add("5000");
                    BlueAddComboBox.Items.Add("7000");
                    BlueAddComboBox.Items.Add("9000");
                    BlueAddComboBox.Items.Add("11000");
                    BlueAddComboBox.Items.Add("15000");
                    BlueAddComboBox.Items.Add("25000");
                    BlueAddComboBox.Enabled = true;
                    BlueAddComboBox.Text = "5000";
                    break;

                case "Random engine":
                case "Human":
                    BlueAddLabel.Text = "";
                    BlueAddComboBox.Text = "";
                    BlueAddComboBox.Enabled = false;
                    break;

                case "Alpha-Beta engine":
				case "Alpha-Beta engine EXPERIMENTAL":
					BlueAddLabel.Text = "Depth:";
                    BlueAddComboBox.Items.Clear();
                    BlueAddComboBox.Items.Add("1");
                    BlueAddComboBox.Items.Add("2");
                    BlueAddComboBox.Items.Add("3");
                    BlueAddComboBox.Items.Add("4");
                    BlueAddComboBox.Items.Add("5");
                    BlueAddComboBox.Items.Add("6");
                    BlueAddComboBox.Items.Add("7");
                    BlueAddComboBox.Items.Add("8");
                    BlueAddComboBox.Items.Add("9");
                    BlueAddComboBox.Enabled = true;
                    BlueAddComboBox.Text = "3";
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            sizeX = int.Parse(SizeXcomboBox.Text);
            sizeY = int.Parse(SizeYcomboBox.Text);

            switch (RedMainComboBox.Text)
            {
                case "Monte Carlo engine":
                    first = new MCEngine(int.Parse(RedAddComboBox.Text), sizeX, sizeY);
                    break;
                case "Random engine":
                    first = new RandomPlayer(sizeX, sizeY);
                    break;
                case "Human":
                    first = new HumanPlayer();
                    break;
                case "Alpha-Beta engine":
                    first = new AlphaBetaEngine(sizeX, sizeY, int.Parse(RedAddComboBox.Text), false);
                    break;
				case "Alpha-Beta engine EXPERIMENTAL":
					first = new AlphaBetaExperimentalEngine(sizeX, sizeY, int.Parse(RedAddComboBox.Text), false);
					break;
			}

            switch (BlueMainComboBox2.Text)
            {
                case "Monte Carlo engine":
                    second = new MCEngine(int.Parse(BlueAddComboBox.Text), sizeX, sizeY);
                    break;
                case "Random engine":
                    second = new RandomPlayer(sizeX, sizeY);
                    break;
                case "Human":
                    second = new HumanPlayer();
                    break;
                case "Alpha-Beta engine":
                    second = new AlphaBetaEngine(sizeX, sizeY, int.Parse(BlueAddComboBox.Text), false);
                    break;
				case "Alpha-Beta engine EXPERIMENTAL":
					second = new AlphaBetaExperimentalEngine(sizeX, sizeY, int.Parse(BlueAddComboBox.Text), false);
					break;
			}
            this.Close();
            mainForm.start(sizeX, sizeY, first, second);
        }


    }
}
