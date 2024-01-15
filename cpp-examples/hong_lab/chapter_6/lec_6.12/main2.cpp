#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

    int length ;

    cin >> length;

    int *array = new int[length]{13,23,33,43,55,63,73};


    array[0] = 97;
    array[1] = 11;


    for (int i=0;i<length;i++)
    {
        cout << array[i] << endl;
        cout << (uintptr_t)(array+i) << endl;
    }
    cout <<endl;


    delete[] array;
    array = nullptr;


    return 0;
}