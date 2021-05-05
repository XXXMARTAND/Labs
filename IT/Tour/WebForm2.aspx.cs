using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tour
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Label1.Text = ListBox1.SelectedItem.Text;
            Console.WriteLine(ListBox1.SelectedItem.Text);
            Response.Redirect("~/WebForm1.aspx?place=" + ListBox1.SelectedItem.Text);
        }

        protected void ListBox1_SelectedIndexChanged1(object sender, EventArgs e)
        {
            Label1.Text = ListBox1.SelectedItem.Text;
            Console.WriteLine(ListBox1.SelectedItem.Text);
            Response.Redirect("~/WebForm1.aspx?place=" + ListBox1.SelectedItem.Text);
        }
    }
}