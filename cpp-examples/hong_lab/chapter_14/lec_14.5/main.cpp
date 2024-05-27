#include <iostream>

class A 
{
public:
    A(int x):m_x(x)
    {
        if (x <= 0)
        {
            throw -1;
        }
    }
private:
    int m_x;

};

class B : public A 
{
public:
    B(int x):A(x)
    {}

};


int main()
{
    try 
    {
        B b(-1);
    }
    catch (int) 
    {
        std::cout <<"[ERROR] x is negative" << std::endl;
    }
    return 0;
}