#include <iostream>
#include <ostream>
using namespace std;

class Base
{
protected:
    int m_i;
public:
    Base(int value):m_i(value)
    {}

    void print() const 
    {
        cout <<"Im base" << endl;
    }

    friend std::ostream & operator<<(std::ostream& out,const Base& base)
    {
        cout <<"This is Base output operator" << endl;
        out << base.m_i ;
        return out;
    }

};

class Derived : public Base
{
public:
    Derived(int value):Base(value)
    {}

    // 부모 클래스의 print 함수를 호출하고, 그 다음 자식 클래스의 print를 호출하고 싶다면
    void print() 
    {
        Base::print();
        cout <<"Im derived" << endl;
    }
    friend std::ostream & operator<<(std::ostream& out,const Derived& derived)
    {
        cout << Base(derived) << endl;
        cout << static_cast<Base>(derived) << endl;
        cout <<"This is Derived output operator" << endl;
        out << derived.m_i ;
        return out;
    }
};


int main()
{
    Base base(5);
    //base.print();

    Derived derived(7);
    //derived.print();

    cout <<"================================"<<endl;

    cout << base << endl;
    cout <<"================================"<<endl;

    cout << derived << endl;

    return 0;
}