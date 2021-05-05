<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="ProductAdd.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div style="height: 319px">
            <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" AutoGenerateColumns="false" AllowSorting="true" DataKeyNames="id">
                <Columns>
                    <asp:BoundField DataField="id" HeaderText="Id" ReadOnly="true" SortExpression="id"/>
                    <asp:TemplateField HeaderText="Name" SortExpression="name">
                    <ItemTemplate>
                        <b>Name:</b>
                        <%# Eval("name") %>
                    </ItemTemplate>
                    <EditItemTemplate>
                        <b>Name:</b>
                        <asp:TextBox ID="TextBox2" runat="server" Text='<%# Bind("name") %>'></asp:TextBox>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Name is required" EnableClientScript="false" ControlToValidate="TextBox2"></asp:RequiredFieldValidator>
                    </EditItemTemplate>
                    </asp:TemplateField>
                    
                    <asp:TemplateField HeaderText="Details">
                    <ItemTemplate>
                        <b>Price:</b>
                        <%# Eval("price") %>
                        <br />
                        <br />
                        <b>Quantity:</b>
                        <%# Eval("quantity") %>
                    </ItemTemplate>
                    <EditItemTemplate>
                        <b>Price:</b>
                        <%# Eval("price") %>
                        <br /> 
                        <br />
                        <b>Quantity</b>
                        <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("quantity") %>'></asp:TextBox>
                        <asp:RangeValidator ID="RangeValidator1" runat="server" ErrorMessage="Quantity should be between 1 and 20" ControlToValidate="TextBox1" EnableClientScript="false" Type="Integer" MinimumValue="1" MaximumValue="20"></asp:RangeValidator>
                    </EditItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ShowEditButton="true"/>
                </Columns>
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=TestDB;Integrated Security=True;Pooling=False" SelectCommand="SELECT * FROM Product" UpdateCommand="UPDATE Product SET quantity=@quantity,name=@name WHERE id=@id"></asp:SqlDataSource>
        </div>
    </form>
</body>
</html>

