
#include <iostream>
#include "MyConstants.h"

//int a = 123 ;

void doSomething()
{
    using namespace std;
    cout << "do something function activated" << endl;
    cout <<"In test.cpp: "<< Constants::pi<< &(Constants::pi)  << endl;
    //cout <<a<< endl;

}