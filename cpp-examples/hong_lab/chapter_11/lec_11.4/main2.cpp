#include <iostream>

using namespace std;

class A
{
public:
    A(const int& a)
    {
        cout <<"A constructor :" << endl;
    }
    ~A()
    {
        cout <<"A destructor :" << endl;

    }
};

class B : public A
{
public:
    B(const int& a,const double& b):A(a)
    {
        cout <<"B constructor :" << endl;
    }
    ~B()
    {
        cout <<"B destructor :" << endl;
    }
};

class C : public B
{
public:
    C(const int& a,const double& b, const char c):B(a,b)
    {
        cout <<"C constructor :" << endl;
    }
    ~C()
    {
        cout <<"C destructor :" << endl;
    }
};



int main()
{
    C c(1024,3.14,'a');

    cout <<"size of Mother class : "<< sizeof(A) << endl;
    cout <<"size of Child class : "<< sizeof(B) << endl;



    return 0;
}