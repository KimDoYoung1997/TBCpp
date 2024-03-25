/*
여러가지 자료형에 대해 거의 비슷한 코드를 반복해서 작성하는 것을 방지해준다.

두 수의 대소비교를 해주는 코드
*/

#include <iostream>
#include <typeinfo>
#include "Cents.h"
using namespace std;


template<typename T>

T getMax(T x, T y)
{
    cout << typeid(x).name() <<" " << typeid(y).name() << endl;
    cout << sizeof(x) <<" " << sizeof(y) << endl;

    return (x > y)? x : y;
}


int main()
{
    cout <<"--------------case1--------------" << endl;
    std::cout << getMax(1, 2) << endl;
    cout <<"--------------case2--------------" << endl;
    std::cout << getMax(3.14, 1.59) << endl;
    cout <<"--------------case3--------------" << endl;
    std::cout << getMax(3.14f, 1.59f) << endl;
    cout <<"--------------case4--------------" << endl;
    std::cout << getMax('a','c') << endl;
    cout <<"--------------case5--------------" << endl;
    std::cout <<getMax(Cents(5),Cents(9))<<endl;
    return 0;
}