using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Validator1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args)
        {
            int val = Int32.Parse(args.Value.Substring(0, 2));
            if (val > 50)
            {
                args.IsValid = true;
            }
            else
                args.IsValid = false;
        }

        protected void Button1_Click(object sender, EventArgs e)
        {

        }

        protected void CustomValidator1_ServerValidate1(object source, ServerValidateEventArgs args)
        {
            try
            {
                int val = Int32.Parse(args.Value.Substring(0, 1));
                if (val > 50 && args.Value.Length == 10)
                {
                    args.IsValid = true;

                }
                else
                    args.IsValid = false;
            }
            catch
            {
                args.IsValid = false;
            }
            
        }
    }
}