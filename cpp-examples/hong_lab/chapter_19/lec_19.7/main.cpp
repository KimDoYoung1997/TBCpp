#include <iostream>
#include <vector>
#include <utility>  // std::forward

struct MyStruct
{

};

void func(MyStruct&s)
{
    std::cout<<"Pass by L-ref"<<std::endl;
}
void func(MyStruct&&s)
{
    std::cout<<"Pass by R-ref"<<std::endl;
}
// void func(MyStruct s)
// {
//     std::cout<<"Pass by value"<<std::endl;
// }

template<typename T>
void func_wrapper(T t)
{
    func(t);
}

int main()
{
    std::cout<<"일반 함수 에서는 L-value와 R-value를 구분하여 오버로딩한다. "<<std::endl;
    MyStruct s;
    func(s);            // L-value 전달
    func(MyStruct());   // R-value 전달
    std::cout<<"Template에서는 L-value와 R-value를 구분하지 않는다. "<<std::endl;
    func_wrapper(s);
    func_wrapper(MyStruct());

    return 0;
}