using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Jobs
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Panel1.Enabled = Panel2.Enabled = false;
            }
        }

        protected void Submit(object sender, EventArgs e)
        {
            if (RadioButtonList1.SelectedValue == "1")
            {
                SqlConnection con = new SqlConnection();
                con.ConnectionString = @"Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=Employee;Integrated Security=True;Pooling=False";
                try
                {
                    con.Open();
                    SqlCommand com = new SqlCommand("insert into Works (Person_Name,Company_Name,Salary) values (@name,@comp,@salary)", con);
                    com.Parameters.AddWithValue("@name", TextBox1.Text);
                    com.Parameters.AddWithValue("@comp", TextBox2.Text);
                    com.Parameters.AddWithValue("@salary", TextBox3.Text);
                    com.ExecuteNonQuery();
                    Label1.Text = "Data added";
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
            else if (RadioButtonList1.SelectedValue == "2")
            {
                SqlConnection con = new SqlConnection();
                con.ConnectionString = @"Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=Employee;Integrated Security=True;Pooling=False";
                try
                {
                    con.Open();
                    SqlCommand com = new SqlCommand("Select Person_Name, City from Works, Lives where Person_Name=Person and Company_Name=@comp", con);
                    com.Parameters.AddWithValue("@comp", TextBox4.Text);
                    SqlDataReader reader = com.ExecuteReader();
                    Label1.Text = "The names and cities of people working in " + TextBox4.Text;
                    while (reader.Read())
                    {
                        Label1.Text += "<br>Name: " + reader["Person_Name"] + "    City: " + reader["City"];
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
        protected void Enable(object sender, EventArgs e)
        {
            Panel1.Enabled = Panel2.Enabled = false;
            if (RadioButtonList1.SelectedValue == "1")
                Panel1.Enabled = true;
            else
                Panel2.Enabled = true;
        }
    }
}