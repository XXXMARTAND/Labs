using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MidTerm
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string url = "WebForm2.aspx?";

            url += "Name=" + HttpUtility.UrlEncode(TextBox1.Text.ToString()) + "&";
            url += "RegNo=" + HttpUtility.UrlEncode(TextBox2.Text.ToString()) + "&";
            url += "Option=" + HttpUtility.UrlEncode(DropDownList1.SelectedItem.ToString());

            Response.Redirect(url);

        }
    }
}