<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="EcomFirm.WebForm1" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <p>
    Mobiles</p>
<p>
    Choose Mobile model:
    <asp:DropDownList ID="DropDownList1" runat="server">
        <asp:ListItem>Samsung</asp:ListItem>
        <asp:ListItem>OnePlus</asp:ListItem>
        <asp:ListItem>Apple</asp:ListItem>
        <asp:ListItem>MI</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    Choose Vendor:
    <asp:DropDownList ID="DropDownList2" runat="server">
        <asp:ListItem>Vendor 1</asp:ListItem>
        <asp:ListItem>Vendor 2</asp:ListItem>
        <asp:ListItem>Vendor 3</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    &nbsp;</p>
<p>
    Laptops</p>
<p>
    Choose Mobile model:
    <asp:DropDownList ID="DropDownList3" runat="server">
        <asp:ListItem>Sony</asp:ListItem>
        <asp:ListItem>Lenovo</asp:ListItem>
        <asp:ListItem>Apple</asp:ListItem>
        <asp:ListItem>HP</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    Choose Vendor:
    <asp:DropDownList ID="DropDownList4" runat="server">
        <asp:ListItem>Vendor 1</asp:ListItem>
        <asp:ListItem>Vendor 2</asp:ListItem>
        <asp:ListItem>Vendor 3</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    &nbsp;</p>
<p>
    Printers</p>
<p>
    Choose Mobile model:
    <asp:DropDownList ID="DropDownList5" runat="server">
        <asp:ListItem>Xerox</asp:ListItem>
        <asp:ListItem>HP</asp:ListItem>
        <asp:ListItem>Canon</asp:ListItem>
        <asp:ListItem>MI</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    Choose Vendor:
    <asp:DropDownList ID="DropDownList6" runat="server">
        <asp:ListItem>Vendor 1</asp:ListItem>
        <asp:ListItem>Vendor 2</asp:ListItem>
        <asp:ListItem>Vendor 3</asp:ListItem>
        <asp:ListItem></asp:ListItem>
    </asp:DropDownList>
</p>
<p>
    &nbsp;</p>
</asp:Content>
