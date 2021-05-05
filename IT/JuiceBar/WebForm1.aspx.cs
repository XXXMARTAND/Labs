using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace JuiceBar
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                List<string> Fruit = new List<string>();
                Fruit.Add("Apple");
                Fruit.Add("Mango");
                Fruit.Add("Orange");
                Fruit.Add("Watermelon");
                CheckBoxList1.DataSource = Fruit;
                List<string> IceCream = new List<string>();
                IceCream.Add("Chocolate");
                IceCream.Add("Vanilla");
                IceCream.Add("Strawberry");
                IceCream.Add("Butterscotch");
                RadioButtonList1.DataSource = IceCream;
                this.DataBind();
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int[] arr = { 50, 70, 60 };
            Random r = new Random();
            int num = r.Next(0, 3);
            Label1.Text = "The Milkshake you picked has <br/> " + CheckBoxList1.SelectedItem.Text + "<br/>&<br/> " + RadioButtonList1.SelectedItem.Text + "<br/><br/>Total Price : Rs." + arr[num].ToString();
        }
    }
}