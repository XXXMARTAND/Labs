using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace StateCity
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            if (!IsPostBack)
            {
                Dictionary<int, string> State = new Dictionary<int, string>();
                State.Add(0, "Maharashtra");
                State.Add(1, "Karnataka");
                State.Add(2, "Rajasthan");
                State.Add(3, "Tamil Nadu");
                State.Add(4, "Sikkim");
                DropDownList1.DataSource = State;
                DropDownList1.DataTextField = "Value";
                DropDownList1.DataValueField = "Key";
                this.DataBind();
            }
        }
    }
}