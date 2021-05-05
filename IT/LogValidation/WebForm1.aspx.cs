using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LogValidation
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        int _s = 0;
        int _f = 0;
        private readonly string userName = "User";
        private readonly string pwd = "Password";
        protected void Page_Load(object sender, EventArgs e)
        {
            //initialize props
            if (Application["_s"] != null && Session["_f"] != null)
            {
                _s = (int)Application["_s"];
                _f = (int)Session["_f"];
                updateCounters();
            }
            else
            {
                _s = _f = 0;
                Application["_s"] = _s;
                Session["_f"] = _f;
            }
        }

        protected void btn_login_Click(object sender, EventArgs e)
        {
            if (pwd == pw_tb.Text && userName == name_tb.Text)
            {
                _s += 1;
            }
            else
            {
                _f += 1;
            }
            Application["_s"] = _s;
            Session["_f"] = _f;
            updateCounters();
        }

        private void updateCounters()
        {
            _success_count_holder.InnerText = _s.ToString();
            _failure_count_holder.InnerText = _f.ToString();
            if (_f > 3)
            {
                pw_tb.Enabled = false;
                _failure_count_holder.Style["color"] = "red";
                status.InnerText = "Login Attempts Failed! Contact Admin";
                status.Style["color"] = "red";
            }
        }
    }
}
