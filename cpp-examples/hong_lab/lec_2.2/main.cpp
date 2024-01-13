#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    using namespace std;

    short   s = 1;      // 16bits
    int     i = 1;      // 32bits
    long    l = 1;      // 256bits
    long long   ll = 1; //256 bits 
    unsigned int ui = 1;

    cout << sizeof(short) << endl;      // 2 bytes
    cout << std::pow(2,(sizeof(short)*(8)-1))-1 <<endl;

    cout << std::numeric_limits<short>::max() <<endl;
    cout << std::numeric_limits<short>::min() <<endl;
    cout << std::numeric_limits<short>::lowest() <<endl;

    s = 32767 ;
    s += 1 ; //32768
    cout <<"overflow: "<<s<<endl;

    s += 1 ; //32769


    s = std::numeric_limits<short>::min() ;//-32768
    s -= 1 ; //-32769
    cout <<"overflow: "<<s<<endl;
    s -= 1 ; //-32770
    cout <<"overflow: "<<s<<endl;

    ui = std::numeric_limits<unsigned int>::max();
    cout<<"unsigned max_value is: "<<ui<<endl;
    ui +=1;
    cout<<"unsigned max_value + 1 is: "<<ui<<endl;
    ui =-1;
    cout<<"unsigned -1 is: "<<ui<<endl;


    cout << sizeof(int) << endl;        // 4

    cout << sizeof(long) << endl;       // 8

    cout << sizeof(long long) << endl;  //8

    cout << sizeof(unsigned int) << endl;
    cout << std::pow(2,(sizeof(unsigned int)*(8)))-1 <<endl;


    return 0;
}