#include <iostream>
#include "MyConstants.h"
using namespace std;


extern void doSomething();


int main()
{
    cout <<"Hello World" <<endl;
    cout <<"In main.cpp file : "<<Constants::pi<<" " << &(Constants::pi) << endl;
    doSomething();

    // cout <<g_a<<endl;
    return 0;
}