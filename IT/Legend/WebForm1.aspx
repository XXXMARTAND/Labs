<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Legend.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        Choose the genre: <asp:DropDownList ID="DropDownList1" runat="server" OnSelectedIndexChanged="Change" AutoPostBack="true"></asp:DropDownList><br />
        <asp:ListBox ID="ListBox1" runat="server" OnSelectedIndexChanged="Change2" AutoPostBack="true"></asp:ListBox><br />
        <asp:Label ID="Label1" runat="server"></asp:Label>
    </form>
</body>
</html>
