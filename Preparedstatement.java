import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;




class Prestate
{
	public static void main(String args[])throws Exception
	{
	   Scanner sc=new Scanner(System.in);

	  Connection con=null;
	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/employee","root","root");
	  if(con==null)
	  {
	    System.out.println("Connection not Established");
	  }
	
	  else
		{


		  
		   /*String s="insert into userinfo values(?,?)";
		  PreparedStatement ps=con.prepareStatement(s);
 		   
		  ps.setString(1,"akshay");
	          ps.setString(2,"aks123");
		  int rs=st.executeUpdate();
	          System.out.println(+rs+" rows inserted");*/

		 PreparedStatement ps1=con.prepareStatement("select *from userinfo where username=?");
		 ps1.setString(1,"akshay");
	  	 ResultSet r=ps1.executeQuery();
	          while(r.next())
			{
			   System.out.println(r.getString(1)+" "+r.getString(2));
			}

		

		}
	}
}