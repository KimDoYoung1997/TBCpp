// friend func and friend class
// 특정 멤버함수에게만 friend 선언을 하고싶을때.


#include <iostream>
#include "friend.h"
using namespace std;


A::A()
{
    m_value=1;
}

B::B()
{
    m_value = 2;
}
void B::doSomething(A &a)
{
    cout <<a.m_value << endl;
}


