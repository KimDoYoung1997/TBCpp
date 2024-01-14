#include <cstdint>
#include <iostream>

using namespace std;

int main()
{


    int value = 7;
    int *ptr = &value;


    cout << (uintptr_t)(ptr-1) << endl; // 140733420203048
    cout << (uintptr_t)ptr << endl; // 140733420203052
    cout << (uintptr_t)(ptr+1) << endl; // 140733420203056


    return 0;
}