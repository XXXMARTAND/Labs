using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            Panel1.BackColor = Color.FromName(DropDownList2.SelectedItem.Text);

            if (Int32.Parse(DropDownList3.SelectedItem.Text) > 0)
            {
                Label1.Font.Size =
                FontUnit.Point(Int32.Parse(DropDownList3.SelectedItem.Text));
            }

            Label1.ForeColor = Color.FromName(DropDownList4.SelectedItem.Text);

            Label1.Text = TextBox1.Text;

            Image1.ImageUrl = DropDownList1.SelectedItem.Text;
            Image1.Visible = true;

        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}