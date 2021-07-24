#include<iostream>

class Demo
{  
    
     int a,b;
    public:
    Demo(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    Demo(const Demo &obj)
    {
        this->a=obj.a;
        this->b=obj.b;
    
    }
    void display()
    {
        std::cout<<a<<std::endl;
        std::cout<<b;
    }
};
int main()
{
    Demo d(10,20);
    Demo d1(d);
    d.display();
    d1.display();

    return 0;

}