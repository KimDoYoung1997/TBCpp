#include <iostream>
using namespace std;

class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;

};

class Derived : private Base
{
public:
    Derived():Base()
    {
        m_public = 1;
        m_protected = 2;
        // m_private = 3;   컴파일 에러
    }
};

class GrandChild : public Derived
{
public:
    GrandChild():Derived()
    {
        // Derived::m_public = 2;       컴파일 에러
        // Derived::m_protected = 3;    컴파일 에러
        // Derived::m_private = 4;      컴파일 에러
    }
};

int main()
{
    Base base;
    base.m_public;

    
    Derived derived;
    
    //derived.m_public;     컴파일 에러
    
    return 0;
}