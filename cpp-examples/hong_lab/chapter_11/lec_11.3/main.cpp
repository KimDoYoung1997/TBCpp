#include <iostream>

using namespace std;

class Mother
{
public:
    int m_i;
    Mother(const int& i_in=0):m_i(i_in)
    {
        cout <<"Mother Construction" << endl;
    }
};


class Child : public Mother
{
public:
    double m_d;    
public:
    //Mother(){}
    Child() :m_d(1.0) ,Mother(1)
    {
        cout <<"Child Constructor"<<endl;
        // 아래 셋 다 같은 기능
        this ->m_i = 10;
        this ->Mother::m_i = 20;
        Mother::m_i = 1024;
    }

};

int main()
{
    Child d1;

    return 0;
}