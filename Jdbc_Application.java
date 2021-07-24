import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.util.Scanner;
import java.sql.ResultSet;


class Application
{
	public static void main(String args[])throws Exception
	{
	  Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/employee","root","root");
	  Statement st=con.createStatement();
	  Scanner sc=new Scanner(System.in);
	  
	  System.out.println("Enter username and password");
	  String s="select count(*) from userinfo where username='"+sc.next()+"'and password='"+sc.next()+"'";
	  ResultSet rs=st.executeQuery(s);
	   rs.next();
          if(rs.getInt(1)==0)
	    {
		System.out.println("user not found");
	     }
	   else
		{
		  System.out.println("user verified");
		}

	 }
}