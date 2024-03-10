#include <iostream>

using namespace std;

class Base
{
// 자식 클래스에서 멤버변수 접근을 허용해주기 위해 protected를 사용했음
protected:
    int m_value;
public:
    Base(int value):m_value(value)
    {}
};


class Derived: public Base
{
public:
    Derived(int value):Base(value)
    {

    }
    // Base에 있는 m_value 값을 바꾸는 것을 Derived 클래스에서 하도록 해보자.
    void setValue(int value)
    {
        Base::m_value = value;
    }

};


int main()
{

    return 0;
}