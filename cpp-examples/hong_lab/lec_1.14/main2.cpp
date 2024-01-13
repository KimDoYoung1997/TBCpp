#include <iostream>
#include <algorithm>

using namespace std;

//#define MY_NUMBER 333
//#define MY_NUMBER "Hello, World"


#define MAX(a,b) (((a)>(b)) ? (a):(b))
#define LIKE_APPLE

int main()
{
#ifdef LIKE_APPLE
    cout <<"APPLE" <<endl;
#endif

#ifndef LIKE_APPLE
    cout<<"ORANGE"<<endl;
#endif

    return 0;
}