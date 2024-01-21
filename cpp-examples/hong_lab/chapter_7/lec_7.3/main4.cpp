#include <iostream>
#include <cmath>
using namespace std;

void foo(int* &ptr)
{
    cout << "--------------------foo() in!----------------------" << endl;

    cout << ptr << " " << &ptr << endl;

    cout << "--------------------foo() out!----------------------" << endl;

}

typedef int* pint;


void boo (pint &ptr)
{
    cout << "--------------------boo() in!----------------------" << endl;

    cout << ptr << " " << &ptr << endl;

    cout << "--------------------boo() out!----------------------" << endl;
}



int main()
{

    int x = 5;
    int *ptr = &x;

    cout << ptr << " " << &ptr << endl;
    foo(ptr);
    boo(ptr);

    return 0;
}