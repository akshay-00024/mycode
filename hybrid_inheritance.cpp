#include<iostream>

class Base
{
    protected:
        int a;
    public:
    Base(int a)
    {
        this->a=a;
    }
    void display()
    {
        std::cout<<this->a<<std::endl;
    }
};


class Subclass1:public Base
{
    protected:
        int b;
    public:
        Subclass1(int a,int b):Base(a)
        {
            this->b=b;
        }
    void display()
    {   Base::display();
        std::cout<<this->b<<std::endl;
    }
};


class Subclass2:public Base
{
    protected:
        int c;
    public:
        Subclass2(int a,int c):Base(a)
        {
            this->c=c;
        }
    void display()
    {  // Base::display();
        std::cout<<this->c<<std::endl;
    }
};

class Sub:public Subclass1,public Subclass2
{
    private:
        int d;
    public:
    Sub(int a,int b,int c,int d):Subclass1(a,b),Subclass2(a,c)
    {
        this->d=d;

    }
    void display()
    {
        Subclass1::display();
        Subclass2::display();
        std::cout<<this->d<<std::endl;
    }
};

int main()
{
    Sub s(10,20,30,40);
    s.display();
    return 0;
}