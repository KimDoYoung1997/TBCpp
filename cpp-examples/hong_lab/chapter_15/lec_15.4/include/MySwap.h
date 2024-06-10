#include <iostream>

template<typename T>
void MySwap(T &a, T &b)
{
/*     T tmp = a;  // copy constructor
    a = b;      // copy assignment
    b = tmp;    // copy assignment */

    // 이번엔 move semantics 를 이용해보자.
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
