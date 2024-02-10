//Static member variable
#include <cstdint>
#include <iostream>

using namespace std;


class Something
{
public:
    static const int s_value;
    int m_second=2;

};

 const int Something::s_value=1;
// int Something::s_value=5;


int main()
{

    cout <<Something::s_value <<" "<<(uintptr_t)&Something::s_value<< endl;

    Something st1;
    Something st2;
    cout <<(uintptr_t)&st1 <<" " << (uintptr_t)&st1.s_value << " " << st1.s_value<<  endl;
    cout <<(uintptr_t)&st2 <<" " << (uintptr_t)&st2.s_value << " " << st2.s_value<<  endl;

    // st1.s_value = 2;
    // cout <<(uintptr_t)&st1 <<" " << (uintptr_t)&st1.s_value << " " << st1.s_value<<  endl;
    // cout <<(uintptr_t)&st2 <<" " << (uintptr_t)&st2.s_value << " " << st2.s_value<<  endl;

    // Something::s_value=5;
    // cout <<(uintptr_t)&st1 <<" " << (uintptr_t)&st1.s_value << " " << st1.s_value<<  endl;
    // cout <<(uintptr_t)&st2 <<" " << (uintptr_t)&st2.s_value << " " << st2.s_value<<  endl;


    // cout <<(uintptr_t)&st1 <<" " << (uintptr_t)&st1.s_value << " " << st1.s_value<<  endl;
    // cout <<(uintptr_t)&st1.m_second << endl;
    // cout <<(uintptr_t)&st2 <<" " << (uintptr_t)&st2.s_value << " " << st2.s_value<<  endl;
    // cout <<(uintptr_t)&st2.m_second << endl;

    return 0;
}