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

class Derived : public Base
{
public:
    Derived():Base()
    {
        m_public = 1;
        m_protected = 2;
        // m_private = 3;   컴파일 에러
    }
};

int main()
{
    Base base;
    base.m_public;
    
    // base.m_protected;   컴파일 에러
    // base.m_private;     컴파일 에러
    
    Derived derived;
    derived.m_public;
    
    return 0;
}