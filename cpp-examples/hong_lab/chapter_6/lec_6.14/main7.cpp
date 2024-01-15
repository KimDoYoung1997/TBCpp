#include <cstdint>
#include <iostream>

using namespace std;


struct Something
{
    int v1;
    float v2;
};


struct Other
{
    Something st;
};


int main()
{

    int value = 5;
    int *const ptr = &value; // address is fixed.
    int &ref = value;

    // functionality of both line 24 and line 25 is same.

    *ptr = 10; // == ref=10;

    return 0;
}