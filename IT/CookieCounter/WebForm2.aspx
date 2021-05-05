<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="CookieCounter.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div>
                <div id="main" style="width: 18rem" runat="server">
                    <p id="name_holder"  runat="server"></p>
                    <p id="regno_holder"  runat="server"></p>
                    <p id="subject_holder" runat="server"></p>
                    <div class="text-center">
                        Counter = <asp:Label id="_counter_holder" runat="server">0</asp:Label>
                        <asp:Button ID="Button1" runat="server" Text="Increment" OnClick="Button1_Click" />
                    </div>
                </div>
            </div>
        </div>
    </form>
</body>
</html>

