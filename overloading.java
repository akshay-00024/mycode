class Demo
{
  // void fun(int a)
	//{
	  //System.out.println("int fun");
	//}
   void fun(float a)
	{
	  System.out.println("float fun");
	}
   void fun(double b)
	{
	  System.out.println("double fun");
	}
    void fun(Integer a)
	{
	   System.out.println("Interger fun");
	}
	public static void main(String args[])
	{
	  Demo d=new Demo();
	   d.fun(10);
	}
}