using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CookieCounter
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        int _Counter = 0;
        HttpCookie curr;
        protected void Page_Load(object sender, EventArgs e)
        {

            curr = Request.Cookies.Get("counter_cookie");
            if (curr != null)
            {
                int temp;
                int.TryParse(curr["counter"], out temp);
                _Counter = temp;
            }
            else
            {
                _Counter = 0;
            }
            _counter_holder.Text = _Counter.ToString();
            if (IsPostBack) return;


            name_holder.InnerText = string.Format("Name: {0}", (string)Session["name"]);
            regno_holder.InnerText = string.Format("RegNo: {0}", (string)Session["regNo"]);
            subject_holder.InnerText = string.Format("Subject: {0}", (string)Session["subject"]);

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            _Counter += 1;
            if (curr == null)
            {
                curr = new HttpCookie("counter_cookie");
            }
            curr["counter"] = _Counter.ToString();
            Response.Cookies.Add(curr);
            _counter_holder.Text = _Counter.ToString();
        }
    }
}
