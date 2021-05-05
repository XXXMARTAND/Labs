<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        #form1 {
            height: 399px;
        }
        #TextArea1 {
            height: 38px;
            width: 172px;
        }
        .auto-style1 {
            height: 459px;
        }
    </style>
</head>
<body style="height: 495px">
    <form id="form1" runat="server" class="auto-style1">
        <asp:DropDownList ID="DropDownList1" runat="server" Height="35px" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged" Width="125px">
            <asp:ListItem>1.png</asp:ListItem>
            <asp:ListItem>2.png</asp:ListItem>
            <asp:ListItem>3.png</asp:ListItem>
            <asp:ListItem>4.png</asp:ListItem>
        </asp:DropDownList>
        <asp:DropDownList ID="DropDownList2" runat="server" Height="35px" Width="125px" BackColor="White">
            <asp:ListItem>Red</asp:ListItem>
            <asp:ListItem>Orange</asp:ListItem>
            <asp:ListItem>Purple</asp:ListItem>
            <asp:ListItem>Yellow</asp:ListItem>
        </asp:DropDownList>
        <asp:DropDownList ID="DropDownList3" runat="server" Height="35px" Width="125px">
            <asp:ListItem>10</asp:ListItem>
            <asp:ListItem>20</asp:ListItem>
            <asp:ListItem>30</asp:ListItem>
        </asp:DropDownList>
        <asp:DropDownList ID="DropDownList4" runat="server" Height="35px" Width="125px">
            <asp:ListItem>Red</asp:ListItem>
            <asp:ListItem>Blue</asp:ListItem>
            <asp:ListItem>Green</asp:ListItem>
            <asp:ListItem>Yellow</asp:ListItem>
        </asp:DropDownList>
        <br />
        Image&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Background&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Font-Size&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Font-Colour<br />
        <asp:TextBox ID="TextBox1" runat="server" Height="42px"></asp:TextBox>
        <br />
        Title<br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Generate" />
        <br />
        <br />
        <asp:Panel ID="Panel1" runat="server" Height="321px" Width="223px">
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<asp:Image ID="Image1" runat="server" Height="167px" Width="99px" />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </asp:Panel>
    </form>
</body>
</html>
