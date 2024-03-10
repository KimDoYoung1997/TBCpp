#include <iostream>

using namespace std;

class Mother
{
private:
    int m_i; //4 byte
public:
    Mother(const int& i_in):m_i(i_in)
    {
        cout <<"Mother Constructor"<< endl;
    }
};


class Child : public Mother
{
public:
    float m_f; // 4 byte
    double m_d; //8 byte
public:
    Child():Mother(1024),m_f(1.0f)
    {
        cout <<"Child Constructor"<< endl;
    }

};


int main()
{
    Child c1;

    cout <<"size of Mother class : "<< sizeof(Mother) << endl;
    cout <<"size of Child class : "<< sizeof(Child) << endl;



    return 0;
}