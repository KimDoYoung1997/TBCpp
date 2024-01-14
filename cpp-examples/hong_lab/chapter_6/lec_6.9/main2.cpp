#include <cstdint>
#include <iostream>

using namespace std;

int main()
{

    int array[] = {9,7,5,3,1};

    for (int i=0;i<5;i++)
    {
        cout << array[i] << " " << (uintptr_t)&array[i] << endl;
    }
    // cout << array[0] << " " << (uintptr_t)&array[0] << endl;
    // cout << array[1] << " " << (uintptr_t)&array[1] << endl;
    // cout << array[2] << " " << (uintptr_t)&array[2] << endl;
    // cout << array[3] << " " << (uintptr_t)&array[3] << endl;

    cout << "===================================================" << endl;

    int *ptr = array;

    for (int i=0;i<5;i++)
    {
        cout << *(ptr+i) <<" "<< uintptr_t(ptr + i) << endl;
    }

    return 0;
}