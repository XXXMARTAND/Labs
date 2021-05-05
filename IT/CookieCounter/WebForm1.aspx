<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="CookieCounter.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>

</head>
<body>
    <div>
        <div >
            <div>
                <form id="form1" runat="server">
                    <div>
                        <asp:Label ID="Label2" runat="server" Text="Name"></asp:Label>
                        <asp:TextBox ID="name_tb" runat="server"></asp:TextBox>
                    </div>
                    <div class="form-group">
                        <asp:Label  ID="Label3" runat="server" Text="Registration Number"></asp:Label>
                        <asp:TextBox  ID="regno_tb" runat="server"></asp:TextBox>
                    </div>
                    <div class="form-group">
                        <asp:Label ID="Label1" runat="server" Text="Subjects"></asp:Label>
                        <asp:DropDownList  ID="sub_ddl" runat="server"></asp:DropDownList>
                    </div>
                    <asp:Button ID="Button1" runat="server" Text="Next" OnClick="Button1_Click" />
                </form>
            </div>
        </div>
    </div>
</body>
</html>

