#include <iostream>

using namespace std;

void doSomething(int y)
{
    cout <<"In func, value of y : " << " " << y << endl;
    cout <<"In func, address of y : " << " " << &y << endl;
}

int main()
{

    doSomething(5);

    int x = 6;

    cout <<"In func, value of x : " << " " << x << endl;
    cout <<"In func, address of x : " << " " << &x << endl;

    doSomething(x);


    return 0;
}