using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace EmpEligibility
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void ImageMap1_Click(object sender, ImageMapEventArgs e)
        {

        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Image1.ImageUrl = int.Parse(DropDownList1.Text) % 100 + ".png";
            Image1.Visible = true;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;
            DateTime joined = Convert.ToDateTime(TextBox2.Text);
            if (now.Subtract(joined).TotalDays >= 5 * 365)
            {
                Label1.Text = "Eligible";
            }
            else
                Label1.Text = "Not Eligible";
        }
        
        protected void FetchImage(object sender, EventArgs e)
        {
            Image1.ImageUrl = int.Parse(DropDownList1.Text) % 100 + ".png";
            Image1.Visible = true;
        }
    }
}