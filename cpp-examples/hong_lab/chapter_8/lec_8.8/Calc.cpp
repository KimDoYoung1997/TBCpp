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
//     Calc& Calc::add(int value)
//     {
//         m_value+=value;
//         return *this;
//     }
//     Calc& Calc::sub(int value)
//     {
//         m_value-=value;
//         return *this;
//     }
//     Calc& Calc::mult(int value)
//     {
//         m_value*=value;
//         return *this;
//     }

//     Calc& Calc::print()
//     {
//         cout <<"m_value : "<<m_value << endl;
//         return *this;
//     }

// };

    Calc::Calc(int init_value)
    :m_value(init_value)
    {cout << "init value : "<<init_value<< endl;}
    Calc& Calc::add(int value)
    {
        m_value+=value;
        return *this;
    }
    Calc& Calc::sub(int value)
    {
        m_value-=value;
        return *this;
    }
    Calc& Calc::mult(int value)
    {
        m_value*=value;
        return *this;
    }

    Calc& Calc::print()
    {
        cout <<"m_value : "<<m_value << endl;
        return *this;
    }

