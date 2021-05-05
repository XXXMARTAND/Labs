<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="EcomFirm.WebForm3" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h2>Choose Baggage</h2>
Bag1:<br />
<asp:ImageButton ID="ImageButton1" runat="server" Height="116px" ImageUrl="~/hp-001-blue-line-laptop-backpack-hp-original-imaevy9bnnrx6mjz.jpeg" Width="113px" />
<br />
<br />
Bag2:<br />
<asp:ImageButton ID="ImageButton2" runat="server" ImageUrl="~/rucksack.jpg" Width="122px" />
<br />
<br />
Bag3:<br />
<asp:ImageButton ID="ImageButton3" runat="server" ImageUrl="~/trolley-bags-500x500.jpg" OnClick="ImageButton3_Click" Width="168px" />
</asp:Content>
