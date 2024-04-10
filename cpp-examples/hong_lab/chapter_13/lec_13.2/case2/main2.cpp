#include "MyArray.h"
// #include "MyArray.cpp"

int main()
{
    std::cout <<"============int===============" << std::endl;

    MyArray<int> my_int_array(10);  //클래스 템플릿을 사용할땐 어떤 타입(여기선 int)을 사용할지 명시해야만 한다. 

    for (int i=0; i<my_int_array.getLength();i++)
    {
        my_int_array[i] = i*10;
    }
    my_int_array.print();

    std::cout <<"============double===============" << std::endl;
    MyArray<int> my_double_array(10);

    for (int i=0; i<my_double_array.getLength();i++)
    {
        my_double_array[i] = i*10;
    }
    my_double_array.print();

    std::cout <<"============char===============" << std::endl;
    MyArray<char> my_char_array(10);

    for (int i=0; i<my_char_array.getLength();i++)
    {
        my_char_array[i] = i+65;
    }
    my_char_array.print();

    return 0;
}