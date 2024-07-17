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
/* 
std::forward는 C++에서 완벽한 전달(perfect forwarding)을 구현할 때 사용됩니다. 
완벽한 전달이란 함수 인자가 전달될 때 원래의 값 카테고리(lvalue, rvalue)를 보존하여 다른 함수에 전달하는 것을 의미합니다.

일반적으로 함수 템플릿에서 인자를 전달할 때는 값 카테고리가 변경될 수 있습니다. 이를 방지하기 위해 std::forward를 사용하여 인자의 원래 값 카테고리를 유지합니다.
 */
template<typename T>
void func_wrapper(T &&t)
{
    func(std::forward<T>(t));
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
    std::cout<<"std::forward 는 입력 인자의 type을 그대로 보존해서 전달하는 기능을 수행한다."<<std::endl;
    func_wrapper(MyStruct());   // Pass by R-ref
    func_wrapper(s);            // Pass by L-ref

    return 0;
}