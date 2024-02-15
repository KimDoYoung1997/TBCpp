// friend func and friend class

#include <iostream>

using namespace std;

class B; //forward declaration

class A
{
private:
    int m_value = 1;
    //friend void doSomething(A &a);
};

void doSomething (A &a)
{
    //cout <<a.m_value << endl; // error: ‘int A::m_value’ is private within this context
}


int main()
{

    A a;

    // cout <<"hi" << endl;
    return 0;
}