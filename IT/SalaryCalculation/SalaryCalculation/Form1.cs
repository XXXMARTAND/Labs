using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SalaryCalculation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double n2;

            double.TryParse(textBox1.Text, out n2);

            if (comboBox1.SelectedItem.ToString() == "Level 1")

            {
                MessageBox.Show("The bonus to be paid is " + (n2 * 0.1).ToString());
            }

            else if (comboBox1.SelectedItem.ToString() == "Level 2" || comboBox1.SelectedItem.ToString() == "Level 3" || comboBox1.SelectedItem.ToString() == "Level 4")

            {
                MessageBox.Show("The bonus to be paid is " + (n2 * 0.09).ToString());
            }

            else if (comboBox1.SelectedItem.ToString() == "Level 5" || comboBox1.SelectedItem.ToString() == "Level 6" || comboBox1.SelectedItem.ToString() == "Level 7")

            {
                MessageBox.Show("The bonus to be paid is " + (n2 * 0.07).ToString());
            }

            else if (comboBox1.SelectedItem.ToString() == "Level 8" || comboBox1.SelectedItem.ToString() == "Level 9" || comboBox1.SelectedItem.ToString() == "Level 10")

            {
                MessageBox.Show("The bonus to be paid is " + (n2 * 0.05).ToString());
            }
        }
    }
}
