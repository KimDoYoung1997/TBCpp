#include <cstdint>
#include <iostream>

using namespace std;

int main()
{

    int *ptr = nullptr;
    int **ptr_ptr = nullptr;

    int value = 5;
    ptr = &value;
    ptr_ptr = &ptr;

    cout << (uintptr_t)ptr <<" "<< *ptr <<" "<< (uintptr_t)&ptr <<endl;
    cout << (uintptr_t)ptr_ptr <<" "<< (uintptr_t)*ptr_ptr<<" "<< **ptr_ptr << endl;





    return 0;
}