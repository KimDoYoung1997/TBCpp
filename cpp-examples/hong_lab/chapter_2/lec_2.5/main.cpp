#include <iostream>
#include <iomanip>
#include <limits> // lecture 2.2
#include <cmath> // lecture 2.2

int main()
{
    using namespace std;

    float f ;
    double d ;
    long double ld;

    cout <<sizeof(f)<<endl; // 32 bit = 4 Byte
    cout <<numeric_limits<float>::max()<<endl; // 2^(128)
//  cout <<(sizeof(float)*8-1)<<endl;
    cout <<numeric_limits<float>::min()<<endl; // 2^(128)
    cout <<numeric_limits<float>::lowest()<<endl; // 2^(128)

    cout <<"---------------------------"<<endl;

    cout <<sizeof(d)<<endl;
    cout <<numeric_limits<double>::max()<<endl; 
    cout <<numeric_limits<double>::min()<<endl; 
    cout <<numeric_limits<double>::lowest()<<endl; 

    cout <<"---------------------------"<<endl;

    cout <<sizeof(ld)<<endl;
    cout <<numeric_limits<long double>::max()<<endl;
    cout <<numeric_limits<long double>::min()<<endl;
    cout <<numeric_limits<long double>::lowest()<<endl;
    return 0;
}