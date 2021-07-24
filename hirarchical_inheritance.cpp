#include<iostream>

class Superclass
{
    protected:
        int a;
    public:
    Superclass(int a)
    {
        this->a=a;
    }
    void display()
    {
        std::cout<<this->a<<std::endl;
    }
};


class Subclass1:public Superclass
{
    protected:
        int b;
    public:
        Subclass1(int a,int b):Superclass(a)
        {
            this->b=b;
        }
    void display()
    {   Superclass::display();
        std::cout<<this->b<<std::endl;
    }
};


class Subclass2:public Superclass
{
    protected:
        int c;
    public:
        Subclass2(int a,int c):Superclass(a)
        {
            this->c=c;
        }
    void display()
    {   Superclass::display();
        std::cout<<this->c<<std::endl;
    }
};

int main()
{   
    Subclass1 s1(10,20);
    Subclass1 s2(30,40);
    
    s1.display();
    s2.display();
    
    return 0;
}