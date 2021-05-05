using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ShoppingCart
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        private HttpCookie coki;

        protected void Page_Load(object sender, EventArgs e)
        {
            status.Visible = false;
            items_list.Visible = true;
            coki = Request.Cookies.Get("cookie_cart");
            if (coki != null)
            {
                items_list.Visible = true;
                welcome_msg.InnerText = "Welcome, " + coki["_cust_name"].ToString()+" Here's Your Cart";
                item1.InnerText = "Item1: " + coki["_item_1"];
                item2.InnerText = "Item2: " + coki["_item_2"];
                item3.InnerText = "Item3: " + coki["_item_3"];
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            coki = new HttpCookie("cookie_cart");
            coki["_cust_name"] = name_tb.Text;
            coki["_item_1"] = i1.Text;
            coki["_item_2"] = i2.Text;
            coki["_item_3"] = i3.Text;
            Response.Cookies.Add(coki);
            status.Visible = true;
        }
    }
}

