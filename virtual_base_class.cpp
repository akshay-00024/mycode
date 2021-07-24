#include<iostream>

class power
{
    public:
        int p=20;
    power(int pw)
    {
        std::cout<<pw<<std::endl;
    }
};

class scanner:virtual public power
{
    public:
    int s;
    scanner(int pw,int sc):power(pw)
    {
        std::cout<<sc<<std::endl;
        std::cout<<p<<std::endl;

    }
};

class printer:virtual public power
{
    public:
    int pr;
    printer(int pw,int prt):power(pw)
    {
        std::cout<<prt<<std::endl;
    }
};

class copy:public scanner,public printer
{
    public:
    int c;
    copy(int pw,int sc,int prt,int cp):power(pw),scanner(pw,sc),printer(pw,prt)
    {
        std::cout<<cp<<std::endl;
        std::cout<<p<<std::endl;
        
    }
};


int main()
{
    copy ob(1,2,3,4);
    return 0;
}