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
void func_wrapper_a(T &t)
{
    func(t);
}
template<typename T>
void func_wrapper_b(T &&t)
{
    func(t);
}

int main()
{
    // std::cout<<"일반 함수 에서는 L-value와 R-value를 구분하여 오버로딩한다. "<<std::endl;
    MyStruct s;
    // func(s);
    // func(MyStruct());
    std::cout<<"Template에서는 L-value와 R-value를 구분하지 않는다. "<<std::endl;
    std::cout<<"func_wrapper_a, func_wrapper_b 에서 인자를 &로 받나, &&로 받나 똑같이 Pass by L-ref만 출력된다."<<std::endl;
    func_wrapper_a(s);
    func_wrapper_b(s);
    func_wrapper_b(MyStruct());
    std::cout<<"이러한 배경으로 std::forward 사용이 대두된다."<<std::endl;

    return 0;
}