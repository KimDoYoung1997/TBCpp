// friend func and friend class
// 특정 멤버함수에게만 friend 선언을 하고싶을때.


#include <iostream>

using namespace std;

class B; //forward declaration

class A
{
private:
    int m_value = 1;

    //friend class B; // B 클래스에게 friend를 통째로 개방하는건 부담스러우니, B의 doSomething 멤버함수에게만 friend를 열어두고싶다면?
    friend void B::doSomething (A &a );
};

class B
{
private:
    int m_value = 2;
public:
    void doSomething (A &a )
    {
        cout <<a.m_value << endl; 
    }

};




int main()
{

    A a;
    B b;

    b.doSomething(a);

    return 0;
}