using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace HouseKeeping
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        DataSet ds = new DataSet();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                SqlConnection con = new SqlConnection();
                con.ConnectionString = @"Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=HouseKeeping;Integrated Security=True";
                try
                {
                    con.Open();
                    SqlCommand comm = new SqlCommand("select distinct StaffID from Staff", con);
                    SqlDataReader reader = comm.ExecuteReader();
                    while (reader.Read())
                    {
                        DropDownList1.Items.Add(reader["staffID"].ToString());

                    }
                }
                catch
                {

                }
                finally
                {
                    con.Close();
                }
            }
        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        


        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=HouseKeeping;Integrated Security=True";
            try
            {
                //con.Open();
                SqlCommand comm = new SqlCommand("update Staff set City = @param1 where StaffID = @param2", con);
                comm.Parameters.AddWithValue("@param1", ListBox1.SelectedValue);
                comm.Parameters.AddWithValue("@param2", DropDownList1.SelectedItem.Text);
                con.Open();
                comm.ExecuteNonQuery();

                
            }
            catch
            {
                Console.WriteLine("err");
            }
            finally
            {
                con.Close();
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            
                SqlConnection con = new SqlConnection();
                con.ConnectionString = @"Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=HouseKeeping;Integrated Security=True";
                SqlCommand comm = new SqlCommand("select FirstName,LastName,DNo,City from Staff where StaffID = @staffID", con);
                comm.Parameters.AddWithValue("@staffID", DropDownList1.SelectedItem.Text);
                SqlDataAdapter adapter = new SqlDataAdapter(comm);
                adapter.Fill(ds, "Staff_Details");
                Label1.Text = (string)ds.Tables["Staff_Details"].Rows[0]["FirstName"] + " " + (string)ds.Tables["Staff_Details"].Rows[0]["LastName"];
                Label2.Text = ds.Tables["Staff_Details"].Rows[0]["DNo"].ToString();
                Label4.Text = (string)ds.Tables["Staff_Details"].Rows[0]["City"];

            
        }
    }
}