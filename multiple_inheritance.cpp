#include<iostream>

class Father
{
    protected:
        int a;
    Father(int a)
    {
        this->a=a;
    }
    void display()
    {
        std::cout<<this->a<<std::endl;
    }
};
class Mother
{
    protected:
        int b;
        Mother(int b)
        {
            this->b=b;
        }
    void display()
    {
        std::cout<<this->b<<std::endl;
    }
};
class child:public Father,public Mother
{
    private:
        int c;
    public:
    child(int a,int b,int c):Father(a),Mother(b)
    {
        this->c=c;

    }
    void display()
    {
        Father::display();
        Mother::display();
        std::cout<<this->c<<std::endl;
    }
};

int main()
{   
    child c(10,20,30);
    c.display();
    return 0;
}