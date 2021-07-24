class Employee
{
	String name;
	int id;
	float salary;
	static String company_name="Infosys";
	Employee(String name,int id,float salary)
	{
		this.name=name;
		this.id=id;
		this.salary=salary;
	}

    float calSalary()
	{
	  return this.salary;
	}
   static void fun()
	{
	   System.out.println("Employee fun");
	
	}
}
class Salesman extends Employee
{
     float incentive;
     Salesman(String name,int id,float salary,float incentive)
	{
	   super(name,id,salary);
	   this.incentive=incentive;
	}
     
    float calSalary()
	{
	  return this.salary+this.incentive;
	}
static void fun()
	{
	   System.out.println("salesman fun");
	
	}
}
class Manager extends Employee
{
   float bonus;
    Manager(String name,int id,float salary,float bouns)
	{
	   super(name,id,salary);
	   this.bonus=bouns;
	}
   float calSalary()
	{
	  return this.salary+this.bonus;
	}
   static void fun()
	{
	   System.out.println("Manager fun");
	
	}
    public static void main(String args[])
	{
	   Employee e=new Manager("Pratik",10,10000.0f,500.0f);
	      System.out.println(e.calSalary());
	      e.fun();
	}
}
     
	