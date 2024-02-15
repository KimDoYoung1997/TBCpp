// friend func and friend class
// 특정 멤버함수에게만 friend 선언을 하고싶을때.


#include <iostream>

using namespace std;

class A; //forward declaration

class B
{
private:
    int m_value = 2;
public:
    void doSomething (A &a );

    // void doSomething (A &a )
    // {
    //     cout <<a.m_value << endl; 
    // }

};


class A
{
private:
    int m_value = 1;
    friend void B::doSomething(A &a); // 특정 멤버함수에게만 friend 선언을 하고싶을때.


};



void B::doSomething (A &a)
{
    cout <<a.m_value << endl; 
}




int main()
{

    A a;
    B b;

    b.doSomething(a);

    return 0;
}