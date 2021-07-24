import java.sql.Connection;
import java.sql.DriverManager;
import java.util.Scanner;
import java.sql.PreparedStatement;
import java.io.FileInputStream;

class ImageStore
{
	public static void main(String args[])throws Exception
	{
	Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/employee","root","root");
	Scanner sc=new Scanner(System.in);
	
	System.out.println("Enter your name");
	String name=sc.next();
	
	System.out.println("Enter path of your image");
	String path=sc.next();
	
	
	FileInputStream fs=new FileInputStream(path);
	
	String q="insert into demostore values(?,?)";
	
	
	PreparedStatement ps=con.prepareStatement(q);
	ps.setString(1,name);
	ps.setBinaryStream(2,fs);
	
	int rs=ps.executeUpdate();
	System.out.println(+rs+" rows affected");
	}
	
	
	
}
