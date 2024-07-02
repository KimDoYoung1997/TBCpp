#include <iostream>
#include <iomanip>
#include <limits> // lecture 2.2
#include <cmath> // lecture 2.2

int main()
{
    using namespace std;

    double d(123456789.0);
    float f(123456789.0f); // 10 significalnt valid digits exist
    cout<<setprecision(9)<<endl; // set 9 significalnt valid  // #include iomnip
    cout<<f<<endl; // 123456792
    cout<<d<<endl;

    double d2(0.1);
    double d3(0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1);
    double d4(0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1);

    cout<<setprecision(17)<<endl;      
    cout <<d2<<endl; // 0.10000000000000001
    cout << (0.10000000000000001== d2) << endl;
    cout << d3 << endl;
    cout << d4 << endl;
    return 0;
}