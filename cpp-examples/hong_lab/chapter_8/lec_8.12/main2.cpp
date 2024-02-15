// friend func and friend class

#include <iostream>

using namespace std;

class B; //forward declaration

class A
{
private:
    int m_value = 1;
    friend void doSomething (A &a ,B &b);
};

class B
{
private:
    int m_value = 2;
    friend void doSomething(A&a,B&b);
};



void doSomething (A &a ,B &b)
{
    cout <<a.m_value << endl; // error: ‘int A::m_value’ is private within this context
    cout <<b.m_value << endl;
}


int main()
{

    A a;
    B b;

    doSomething(a,b);

    return 0;
}