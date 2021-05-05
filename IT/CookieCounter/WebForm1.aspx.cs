using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CookieCounter
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                sub_ddl.Items.Add("Maths");
                sub_ddl.Items.Add("Physics");
                sub_ddl.Items.Add("Biology");
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string name = name_tb.Text;
            string regNo = regno_tb.Text;
            string selectedSubject = sub_ddl.SelectedItem.Text;
            Session["name"] = name;
            Session["regNo"] = regNo;
            Session["subject"] = selectedSubject;
            Response.Redirect("WebForm2.aspx");
        }
    }
}
