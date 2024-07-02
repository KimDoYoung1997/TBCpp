#include <iostream>
#include <algorithm>

using namespace std;

//#define MY_NUMBER 333
//#define MY_NUMBER "Hello, World"

#define MAX(a,b) (((a)>(b)) ? (a):(b))
#define LIKE_APPLE


void doSomething()
{
#ifdef LIKE_APPLE
    cout <<"APPLE" <<endl;
#else
    cout<<"ORANGE"<<endl;
#endif
}



int main()
{
    doSomething();
    return 0;
}