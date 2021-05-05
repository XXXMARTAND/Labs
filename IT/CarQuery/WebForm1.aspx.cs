using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CarQuery
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            DropDownList1.Items.Add(new ListItem("--Select--"));
            DropDownList1.Items.Add(new ListItem("BMW"));
            DropDownList1.Items.Add(new ListItem("AUDI"));
            DropDownList1.Items.Add(new ListItem("MARUTI"));
            DropDownList1.Items.Add(new ListItem("HYUNDAI"));
            DropDownList1.Items.Add(new ListItem("HONDA"));

        }
        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)

        {

            string url = "WebForm2.aspx?";

            url += "Model=" + HttpUtility.UrlEncode(TextBox1.Text.ToString()) + "&";

            url += "Make=" + HttpUtility.UrlEncode(DropDownList1.SelectedItem.ToString());

            Response.Redirect(url);

        }
    }
}
