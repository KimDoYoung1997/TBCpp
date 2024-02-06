#include <iostream>
#include "Calc.h"
using namespace std;

// class Calc
// {
// private:
//     int m_value;
// public:
//     Calc(int init_value)
//     :m_value(init_value)
//     {cout << "init value : "<<init_value<< endl;}
//     Calc& add(int value)
//     {
//         m_value+=value;
//         return *this;
//     }
//     Calc& sub(int value)
//     {
//         m_value-=value;
//         return *this;
//     }
//     Calc& mult(int value)
//     {
//         m_value*=value;
//         return *this;
//     }

//     Calc& print()
//     {
//         cout <<"m_value : "<<m_value << endl;
//         return *this;
//     }

// };

int main()
{


    Calc cal1(10);
    cal1.add(7).print().sub(9).print();


    cout <<"-----------------"<< endl;

    Calc cal2(10);
    Calc &temp1 = cal2.add(7);
    Calc &temp2 = cal2.print();
    Calc &temp3 = temp2.sub(9);
    Calc &temp4 = temp1.print();


    return 0;
}