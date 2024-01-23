#include <iostream>
#include <array>
#include <tuple>
using namespace std;

std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.15;

    return std::make_tuple(a,d);
}

int main()
{
    std::tuple<int, double> my_tp = getTuple();
    cout << typeid(my_tp).name() << endl;  // St5tupleIJidEE

    cout << std::get<0>(my_tp) << endl; // 10

    cout << std::get<1>(my_tp) << endl; // 3.15



// C++ 17 grammer
    auto[a,d] = getTuple();
    cout << a << " " << d << endl;


    return 0;
}