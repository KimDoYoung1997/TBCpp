/*
객체 잘림(Object Slicing이라)과 Reference Wrapper

상속의 구조를 보면, 부모 클래스보다 자식 클래스가 더 많은 정보를 갖기 마련이다. 
자식 클래스에는 부모 클래스의 일반적인 경우보다는 더 구체화된 경우에 대해서 구현이 되기 때문에 추가적인 변수를 가지고 있을 수도 있고, 추가적인 함수를 가지고 있을 수 있다.

만약 보다 작은 부모의 객체에다가 보다 큰 자식 클래스의 객체를 강제로 대입한다고 생각해보자.
부모 클래스의 객체가 담을 수 있는 정보가 더 적기 때문에 자식 클래스에만 있는 정보들은 모두 잘려서 사라질 것이다.
이러한 것을 객체 잘림, 즉 Object Slicing이라 부른다. 
상당한 경우 다형성을 구현할 때 초보 프로그래머들이 실수로 객체 잘림 현상을 만들어내는 경우가 많다.

객체 잘림 현상을 방지할 수 있는 Reference Wrapper에 대해서도 추가로 공부해보자.

*/


#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1 ;

    virtual void print()
    {
        cout <<"I'm Derived" << endl;
    }
};


// 음. Base객체 또는 Base객체를 직접 혹은 간접적으로 상속하는 클래스의 객체(Derived)가 인자의 대상이 되는구나!  by 열혈C++ 363 page
// 음. 인자로 전달되는 객체의 실제 자료형에 상관 없이 함수 내에서는 Base 클래스에 정의된 함수만 호출할 수 있겠구나!  by 열혈C++ 363 page
void doSomething(Base& b) 
{
    b.print();  // & 덕분에 다형성 발현
    cout << b.m_i << endl;
}



int main()
{
    Derived derived;

    // 개발자의 실수인지, 참조자 없이 derived 객체를 base 객체에 "대입" 하고 있다.
    // 이럴경우 derived만 가지고 있는 멤버를 base에서 사용할 수 없다.
    Base base = derived;
    base.print();   //다형성이 사라짐. 객체 잘림

    doSomething(derived);

    return 0;
}