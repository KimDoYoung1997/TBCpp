// friend func and friend class

#include <iostream>

using namespace std;

class B; //forward declaration

class A
{
private:
    int m_value = 1;
    friend void doSomething(A &a, B&b);
};

class B
{
private:
    int m_value=2;
    friend void doSomething(A &a, B&b);
};


void doSomething(A &a,B&b)
{
    cout << a.m_value << endl;
    cout << b.m_value << endl;
    //cout <<"hhii" << endl;
}



int main()
{

    A a;
    B b;
    doSomething(a,b);

    // cout <<"hi" << endl;
    return 0;
}