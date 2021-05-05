<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Tour.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:GridView ID="GV1" DataSourceID="SqlDataSource1" runat="server" AllowSorting="True" AutoGenerateColumns="False" >
            <Columns>
                <asp:BoundField DataField="place" HeaderText="place" SortExpression="place" />
                <asp:BoundField DataField="days" HeaderText="days" SortExpression="days" />
                <asp:BoundField DataField="cost" HeaderText="cost" SortExpression="cost" />
                <asp:BoundField DataField="Travel_Agency" HeaderText="Travel_Agency" SortExpression="Travel_Agency" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:whatConnectionString2 %>" SelectCommand="SELECT * FROM [Tour] WHERE ([place] = @place)">
            <SelectParameters>
                <asp:QueryStringParameter Name="place" QueryStringField="place" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>
    </div>
    </form>
</body>
</html>
