#include <iostream>
int main()
{

    using namespace std;

    bool bValue = false;
    char chValue = 'A';
    char chValue2 = 66;

    cout << bValue << endl;
    cout << ((bValue) ? 1 : 0) <<endl;
    cout << chValue <<endl;
    cout << (int) chValue <<endl;
    cout << int (chValue) <<endl;
    cout << chValue2 << endl;

    float fValue = 3.141592;
    double dValue = 3.141592;
    auto aValue = 3.141592;
    auto aValue2 = 3.141592f;

    cout <<fValue << endl;
    cout <<dValue <<endl;
    cout <<aValue<<endl;
    cout <<sizeof(aValue)<<" Byte"<<endl;
    cout <<sizeof(aValue2)<<" Byte"<<endl;
    cout <<sizeof(bool)<<" Byte"<<endl;

    cout <<aValue2<<endl;


// initilization 3 methods.
// 1. copy initialization
    int a = 1.23;
    cout <<a<< endl;

// 2. direct initialization
    int b(1.23);
    cout <<b<< endl;

// 3. uniform initialization
    //int c{ 1.23 } ;
    //cout <<c<< endl;
    int k=12,l=23,m=123;


    return 0;   
}