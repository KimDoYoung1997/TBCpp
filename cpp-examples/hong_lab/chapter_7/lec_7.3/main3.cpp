#include <iostream>
#include <cmath>
using namespace std;

void foo(int &x)
{
    cout << "--------------------foo() in!----------------------" << endl;

    cout << x << endl;

    cout << "--------------------foo() out!----------------------" << endl;

}

void boo(const int &x)
{
    cout << "--------------------foo() in!----------------------" << endl;

    cout << x << endl;

    cout << "--------------------foo() out!----------------------" << endl;

}

int main()
{


    //foo(6); // compile error. because there is no origin variable to refer
    
    boo(6); // in this case, no error.

    return 0;
}