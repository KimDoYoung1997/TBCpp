/*
상속 받은걸 사용하지 않는 방법
*/

#include <iostream>
using namespace std;

class Base
{
protected:
    int m_i;
public:
    Base(const int& value):m_i(value)
    {}

    void print()
    {
        cout <<"Im base"<< endl;
    }

    void onlyParent()
    {
        cout <<"Parent only" << endl;
    }

};

class Derived : public Base
{
private:
    double m_d;
// 아래 코드를 통해 Derived에서는 print 함수를 외부에서 호출할 수 없게된다.
private:
    using Base::print;

public:
    Derived(const int& value):Base(value)
    {}

    // 아래 코드를 통해 Derived에서는 m_i 멤버변수가 public으로 변한다
    using Base::m_i;

// 자식 클래스에서는 onlyParent 함수에대한 접근이 금지됨
private:
    void onlyParent() = delete;


};

int main()
{
    Base base(5);
    base.print();
    base.onlyParent();
    Derived derived(7);

    derived.m_i;
    derived.onlyParent(); //컴파일 에러

    
    //derived.print();  컴파일 에러


    return 0;
}
