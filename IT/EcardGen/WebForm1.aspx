<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="EcardGen.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body style="height: 400px">
    <form id="form1" runat="server" visible="True">
        Colour
        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem>Red</asp:ListItem>
            <asp:ListItem>Green</asp:ListItem>
            <asp:ListItem>Blue</asp:ListItem>
        </asp:DropDownList>
        &nbsp;Font
        <asp:DropDownList ID="DropDownList2" runat="server">
            <asp:ListItem>Verdana</asp:ListItem>
            <asp:ListItem>Courier</asp:ListItem>
            <asp:ListItem>Georgia</asp:ListItem>
        </asp:DropDownList>
        &nbsp;Font-Size
        <asp:DropDownList ID="DropDownList3" runat="server" Height="21px">
            <asp:ListItem>10</asp:ListItem>
            <asp:ListItem>20</asp:ListItem>
            <asp:ListItem>30</asp:ListItem>
        </asp:DropDownList>
        <br />
        <asp:CheckBox ID="CheckBox1" runat="server" Text="Image" OnCheckedChanged="CheckBox1_CheckedChanged" />
        <br />
        <br />
        Enter Text<br />
        <asp:TextBox ID="TextBox1" runat="server" OnTextChanged="TextBox1_TextChanged"></asp:TextBox>
        <br />
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Generate Ecard" />
        <br />
        <br />
        <asp:Panel ID="Panel1" runat="server" Height="123px" Width="210px">
            <asp:Image ID="Image1" runat="server" Height="62px" Width="206px" />
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        </asp:Panel>
    </form>
</body>
</html>

