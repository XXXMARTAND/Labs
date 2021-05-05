using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MidTerm
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string str = "Name: " + Request.QueryString["Name"] + "(" + Request.QueryString["RegNo"] + ")";
            Label1.Text = str;



        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string val = Request.QueryString["Option"];
            if (val == "Odd")
            {
                if(Int32.Parse(TextBox1.Text) % 2 == 1)
                {
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Success"));
                }
                else
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Failure"));
            }
            if (val == "Even")
            {
                if (Int32.Parse(TextBox1.Text) % 2 == 0)
                {
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Success"));
                }
                else
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Failure"));
            }
            else
            {
                if (Int32.Parse(TextBox1.Text) % 3 == 0)
                {
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Success"));
                }
                else
                    ListBox1.Items.Add(new ListItem(TextBox1.Text + " Failure"));
            }

        }
    }
}