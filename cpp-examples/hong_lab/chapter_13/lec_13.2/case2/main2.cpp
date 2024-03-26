#include "MyArray.h"
// #include "MyArray.cpp"

int main()
{
    MyArray<int> my_array(10);

    for (int i=0; i<my_array.getLength();i++)
    {
        my_array[i] = i*10;
    }

    my_array.print();
    return 0;
}