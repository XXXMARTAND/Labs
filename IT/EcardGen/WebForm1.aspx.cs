using System;
using System.Collections.Generic;
using System.Linq;
using System.Drawing;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace EcardGen
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            Panel1.BackColor = Color.FromName(DropDownList1.SelectedItem.Text);

            if (Int32.Parse(DropDownList3.SelectedItem.Text) > 0)
            {
                Label1.Font.Size =
                FontUnit.Point(Int32.Parse(DropDownList3.SelectedItem.Text));
            }

            //Label1.ForeColor = Color.FromName(DropDownList4.SelectedItem.Text);
            Image1.ImageUrl = "1.png";

            Label1.Font.Name = DropDownList2.SelectedItem.Text;

            if (CheckBox1.Checked)
            {
                Image1.Visible = true;
            }
            else
            {
                Image1.Visible = false;
            }

            Label1.Text = TextBox1.Text;
        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
           // TextBox1.Visible = true;
        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
