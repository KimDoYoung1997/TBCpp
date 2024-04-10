/*
자료형이 아닌 템플릿 매개변수 사용 방법
*/

#include "MyArray.h"

#include <iostream>

int main()
{
    MyArray<double,template_array_size> my_array; 
    for (int i=0; i<my_array.getLength();++i)
    {
        my_array[i]= i+65;
    }

    my_array.print();
    return 0;
}