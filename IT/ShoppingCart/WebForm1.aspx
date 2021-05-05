<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="ShoppingCart.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    
</head>
<body>
    <div class="container">
        <div>
            <div style="width: 25em;">
                <div>
                    <form id="form1" runat="server">
                        <div class="form-group">
                            <asp:Label ID="Label2" runat="server" Text="Enter Name"></asp:Label>
                            <asp:TextBox  ID="name_tb" runat="server"></asp:TextBox>
                        </div>
                        <div class="form-group">
                            <asp:Label ID="Label3" runat="server" Text="Item "></asp:Label>
                            <asp:TextBox ID="i1" runat="server"></asp:TextBox>
                        </div>
                        <div class="form-group">
                            <asp:Label ID="Label4" runat="server" Text="Item "></asp:Label>
                            <asp:TextBox ID="i2" runat="server"></asp:TextBox>
                        </div>
                        <div class="form-group">
                            <asp:Label ID="Label5" runat="server" Text="Item "></asp:Label>
                            <asp:TextBox ID="i3" runat="server"></asp:TextBox>
                        </div>
                        <asp:Button ID="Button1" runat="server" Text="Continue Shopping" OnClick="Button1_Click" />
                    </form>
                </div>
            </div>
        </div>
        <div id="status" class="jumbotron" runat="server">
            <h3>Items Saved in the cart</h3>
        </div>

        <div id="items_list" runat="server">
            <h2 runat="server" id="welcome_msg"></h2>
            <p runat="server" id="item1"></p>
            <p runat="server" id="item2"></p>
            <p runat="server" id="item3"></p>
        </div>
    </div>
</body>
</html>
