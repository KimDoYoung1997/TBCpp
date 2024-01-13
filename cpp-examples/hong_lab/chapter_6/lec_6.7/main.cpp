#include <iostream>
#include <cstdint>

using namespace std;


int main()
{
    int x = 5;
    cout << x << endl;
    cout << &x << endl;
    cout <<(intptr_t)&x << endl;

    cout <<*&x << endl;


    return 0;
}