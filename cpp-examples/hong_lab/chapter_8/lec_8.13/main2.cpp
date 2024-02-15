//Anonymous object
#include <iostream>

using namespace std;

class A
{
public:
    int m_value;
    A(const int& input)
    : m_value(input)
    {
        cout <<"Constructor"<< endl;
    }
    void print()
    {
        cout <<m_value<< endl;
    }
    ~A()
    {
        cout <<"Destructor"<< endl;
    }

};


int main()
{


    A a(1);
    a.print();

    A(2).print(); // R-value 임시객체라, 라인을 지나가면 바로 사라진다.

    return 0;
}