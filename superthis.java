class Parent
{
	static int a;
	int b=100;
	static
	{
	 a=10;
	}
}
class Child extends Parent
{
	int a=30;
   void fun()
	{
	  int a=20;
	  
	  System.out.println(a);
	  System.out.println(this.a);
	  System.out.println(super.a);
	   super.a=50;
	   this.a=60;
           //System.out.println(this.a);
	  //System.out.println(super.a);
	  // System.out.println(super);
 	  System.out.println(this);
	}
    static void gun()
	{
	  //System.out.println(super.b);
	 // System.out.println(super.a);
	}
    public static void main(String args [])
	{
	  Child c= new Child();
	  //c.fun();
	  Child.gun();
	}
}
