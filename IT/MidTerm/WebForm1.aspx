<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="MidTerm.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Name:<br />
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            RegNo:<br />
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <br />
            Option:<br />
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Odd</asp:ListItem>
                <asp:ListItem>Even</asp:ListItem>
                <asp:ListItem>Divisible by three</asp:ListItem>
            </asp:DropDownList>
            <br />
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Next" />
        </div>
    </form>
</body>
</html>
