#include<iostream>
#include<string.h>

class Employee
{
    private:
        char name[20];
        int age;
        int id;
    protected:
        float sal;
    public:
        Employee(const char *name="",int age=0,int id=0,float sal=0.0f)
        {
           strcpy(this->name,name);
            this->age=age;
            this->id=id;
            this->sal=sal;
        }
        const char* getName()
        {
            return this->name;
        }
        int getAge()
        {
            return this->age;
        }
        int getId()
        {
            return this->id;
        }
       virtual float getSal()
        {
            return this->sal;
        }
       virtual float cal_income()
        {
            return this->sal;
        }
      virtual void display()
        {
            std::cout<<"name: "<<this->name<<std::endl;
            std::cout<<"age: "<<this->age<<std::endl;
            std::cout<<"id: "<<this->id<<std::endl;
            std::cout<<"sal: "<<this->sal<<std::endl;
        }
};

class Manager:public Employee
{
    private:
        int bonus;
    public:
    Manager(const char *name="",int age=0,int id=0,float sal=0.0f,int bonus=0):Employee(name,age,id,sal)
    {
        this->bonus=bonus;
    }
    int getBonus()
    {
        return this->bonus;
    }
    float cal_income()
    {
        return this->sal+this->bonus;
    }
    void display()
    {
        Employee::display();
        std::cout<<"bonus: "<<this->bonus<<std::endl;
    }
};

class SalesMan:public Employee
{
     private:
        int incentive;
    public:
    SalesMan(const char *name="",int age=0,int id=0,float sal=0.0f,int incentive=0):Employee(name,age,id,sal)
    {
        this->incentive=incentive;
    }
    int getIncentive()
    {
        return this->incentive;
    }
    float cal_income()
    {
        return this->sal+this->incentive;
    }
    void display()
    {
        
        Employee::display();
        std::cout<<"incentive: "<<this->incentive<<std::endl;

    }

};

float total_sal(Employee *arr[],int n)
{
    float total_sal=0;
    for(int i=0;i<n;i++)
        {
            total_sal+=arr[i]->getSal();
        }
    return total_sal;
}

float total_income(Employee *arr[],int n)
{
    
    float total_inc=0;
    for(int i=0;i<n;i++)
        {
            total_inc+=arr[i]->cal_income();
        }
    return total_inc;

}


int main()
{   
    Employee* arr[5];
    arr[0]=new Employee("akshay",20,50,1000);
    arr[1]=new Manager("rohit",30,51,1000,500);
    arr[2]=new SalesMan("abhi",21,52,1000,300);
    arr[3]=new Employee("jay",20,53,1000);
    arr[4]=new SalesMan("hardik",25,54,1000,300);

    for(int i=0;i<5;i++)
    {
        arr[i]->display();
        
    }
   std::cout<<"total salary:"<<total_sal(arr,5)<<std::endl;
   std::cout<<"total income:"<<total_income(arr,5);

    return 0;
}