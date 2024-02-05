#include <iostream>

using namespace std;

class Calc
{
private:
    int m_value;
public:
    Calc(int init_value)
    :m_value(init_value)
    {cout << "init value : "<<init_value<< endl;}
    void add(int value){m_value+=value;}
    void sub(int value){m_value-=value;}
    void mult(int value){m_value*=value;}

    void print()
    {
        cout <<"m_value : "<<m_value << endl;
    }

};

int main()
{
    Calc cal1(10);
    cal1.add(5);
    cal1.sub(7);
    cal1.mult(5);
    cal1.print();

    Calc cal2(10);
    Calc *cal_ptr = nullptr;
    cal_ptr = &cal2;
    cal_ptr->print();
    cal_ptr->add(3);



    return 0;
}