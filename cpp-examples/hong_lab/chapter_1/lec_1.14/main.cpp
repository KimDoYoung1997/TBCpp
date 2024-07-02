#include <iostream>
#include <algorithm>

using namespace std;

//#define MY_NUMBER 333
//#define MY_NUMBER "Hello, World"


#define MAX(a,b) (((a)>(b)) ? (a):(b))

int main()
{
    cout << MAX(2,3) << endl;
    cout <<max(1+3,2)<<endl;
    return 0;
}