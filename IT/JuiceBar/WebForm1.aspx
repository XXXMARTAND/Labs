<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="JuiceBar.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="font-weight: 700">
    
        <h1>
    
        <strong>Welcome to Juice Bar!</h1>
        <br />
        Choose a Fruit:</strong><asp:CheckBoxList ID="CheckBoxList1" runat="server" style="margin-top: 0px" >
        </asp:CheckBoxList>
        <br />
        Choose an Ice-Cream:<asp:RadioButtonList ID="RadioButtonList1" runat="server">
        </asp:RadioButtonList>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Make Milkshake" />
        <br />
        <br />
        <asp:Label ID="Label1" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>

