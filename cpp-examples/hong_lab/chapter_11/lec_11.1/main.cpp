/*
상속의 기본(1)

*/

#include <iostream>
using namespace std;


class Mother
{
protected:
    int m_i;

public:
    void setValue(const int& i_in)
    {
        m_i = i_in ;
    }
    int getValue()
    {
        return m_i;
    }



};

class Child : public Mother
{
private:
    double m_d;
public:
    void setValue(const int& i_in,const double& d_in)
    {
        m_i = i_in;
        m_d = d_in;
    }
    double getValue() 
    {
        return m_d ;
    }
};

int main()
{
    Mother mother;
    mother.setValue(1024);
    cout << mother.getValue() << endl;

    Child child;
    child.setValue(2048,10.0);
    cout << child.getValue()<<endl;
    return 0;
}