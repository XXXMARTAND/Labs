using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Legend
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Dictionary<int, string> dict = new Dictionary<int, string>();
                dict.Add(0, null);
                dict.Add(1, "comedy");
                dict.Add(2, "romance");
                dict.Add(3, "animated");
                DropDownList1.DataTextField = "Value";
                DropDownList1.DataValueField = "Key";
                DropDownList1.DataSource = dict;
                DropDownList1.DataBind();
            }
        }
        protected void Change(object sender, EventArgs e)
        {
            ListBox1.Items.Clear();
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=houseKeeping1;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("Select name from Table2 where category=@param1", con);
                com.Parameters.AddWithValue("@param1",DropDownList1.SelectedItem.Text);
                SqlDataReader reader = com.ExecuteReader();
                while (reader.Read())
                {
                    ListBox1.Items.Add(reader["name"].ToString());
                }
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }
            finally
            {
                con.Close();
            }
        }
        protected void Change2(object sender, EventArgs e)
        {
            Label1.Text = "";
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=houseKeeping1;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
            try
            {
                con.Open();
                SqlCommand com = new SqlCommand("Select name, age from Table2 where category=@cat and name=@n", con);
                com.Parameters.AddWithValue("@n", ListBox1.SelectedValue);
                com.Parameters.AddWithValue("@cat", DropDownList1.SelectedItem.Text);
                SqlDataReader reader = com.ExecuteReader();
                while (reader.Read())
                {
                    Label1.Text += "Name: " + reader["name"].ToString() + "<br>Age: " + reader["age"];
                }
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }
            finally
            {
                con.Close();
            }
        }
    }
}