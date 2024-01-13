#include <iostream>

int main()
{
    using namespace std;

    int x = 3 ;
    int y = 10;
    int z = (++x,++y,13) ; // x 4 y 11

    // ++x;
    // ++y;
    // int z = y ;
    int a ;
    a = x,y; // a 4
    cout << x++ << endl;
    // cout << x << " " << y << " " << z << endl; // 4 11 11 
    cout << a <<endl;


    a = (x++,x+y); // x 5 // x+y = 5 + 11 = 16

    cout << x <<endl; // 5
    cout << a <<endl; // 16 

    return 0;
}