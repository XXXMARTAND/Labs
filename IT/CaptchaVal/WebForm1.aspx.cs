using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CaptchaVal
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        static int retry;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                retry = 0;
                //Session["RetryCount"] = 0;
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            //int rt = (int)Session["RetryCount"];
            // rt++;
            retry++;
            if (retry > 3)
            {
                TextBox1.Enabled = false;
                TextBox1.Visible = false;
                
                Label1.Text = "Validation Failed";
                Label1.Visible = true;
            }
            else
            {
                if (TextBox1.Text == "ReCAPtCHA")
                {
                    Label1.Text = "Successful!";
                    Label1.Visible = true;
                }
                else
                {
                    Label1.Text = "Unsuccessful! Try Again!";
                    Label1.Visible = true;
                }
            }

        }
    }
}
