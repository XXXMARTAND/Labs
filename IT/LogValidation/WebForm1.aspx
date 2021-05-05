<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="LogValidation.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <div class="container">
        <div>
            <div>
                <div>
                    <form id="form1" runat="server">
                        <div>
                            <asp:Label ID="Label2" runat="server" Text="Username"></asp:Label>
                            <asp:TextBox ID="name_tb" runat="server"></asp:TextBox>
                        </div>
                        <div class="form-group">
                            <asp:Label ID="Label1" runat="server" Text="Password"></asp:Label>
                            <asp:TextBox ID="pw_tb" runat="server" TextMode="Password"></asp:TextBox>
                        </div>
                        <div class="text-center">
                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:Button CssClass="btn btn-dark" ID="btn_login" runat="server" Text="Login" OnClick="btn_login_Click"/>
                        </div>
                    </form>
                </div>
            </div>
        </div>
            <div class="row">
                <div class="col-6 text-center">
                    <span class="h3 text-uppercase">Attempts succesfull : </span>
                    <strong id="_success_count_holder" class="display-4" runat="server">-</strong></div>
                <div class="col-6 text-center">
                    <span class="h3 text-uppercase">Failed attempts : </span>
                    <strong id="_failure_count_holder" class="display-4" runat="server">-</strong>
                </div>
            </div>
            <div class="text-center">
                <h2 id="status" runat="server"></h2>
            </div>
        </div>
</body>
</html>

