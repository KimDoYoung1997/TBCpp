#include "MyArray.h"

int main()
{
    MyArray my_array(10);

    for (int i=0; i<my_array.getLength();i++)
    {
        my_array[i] = i*10;
    }

    my_array.print();
    return 0;
}