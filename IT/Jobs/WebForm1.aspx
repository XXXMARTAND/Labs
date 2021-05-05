<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Jobs.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:RadioButtonList ID="RadioButtonList1" runat="server" OnSelectedIndexChanged="Enable" AutoPostBack="true">
            <asp:ListItem Text="Insert into Works DB" Value="1" />
            <asp:ListItem Text="Retrieve Data"  Value="2"/>
        </asp:RadioButtonList>
        <asp:Panel ID="Panel1" runat="server">
                Person Name: <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                Company Name: <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                Salary: <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
        </asp:Panel>
        <asp:Panel ID="Panel2" runat="server">
            Company Name: <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
        </asp:Panel>
        <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="Submit"/><br />
        <asp:Label ID="Label1" runat="server" ></asp:Label>
    </form>
</body>
</html>

