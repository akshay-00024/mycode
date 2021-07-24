#include<iostream>
#include<string.h>

class Person
{
    private:
        char name[30];
        int age;
    public:
        Person(const char *name="",int age=0)
            {
                strcpy(this->name,name);
                this->age=age;

            }
        const char *getName()
        {
            return(this->name);
        }
        int getAge()
        {
            return(this->age);
        }
        void display()
        {
            std::cout<<"Name:"<<this->name<<std::endl<<"Age:"<<this->age<<std::endl;
        }
};

class Employee:public Person
{
    private:
        int id;
        float sal;
    public:
        Employee(const char* name="",int age=0,int id=0,float sal=0.0f):Person(name,age)
        {
            this->id=id;
            this->sal=sal;
        }
    int getId()
    {
        return(this->id);
    }
    int getSal()
    {
        return(this->sal);

    }
    void display()
    {
        Person::display();
        std::cout<<"id:"<<this->id<<std::endl<<"salary:"<<this->sal<<std::endl;

    }

};

int main()
{
    Employee e("rohit",32,45,50000.0f);
    e.display();
    return 0;
}