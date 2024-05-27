#include <iostream>
#include <memory> //스마트 포인터
using namespace std;


// 예외처리의 위험성
// 1. 예외처리를 하다보면 메모리 처리가 안 돼서 memory leak 문제가 발생할 수 있다.
//    ==> 스마트 포인터를 사용하여 안전하게 처리 가능
// 2. 클래스의 소멸자에서 throw하는 행위는 "금기시" 되는 행위이다.
// 3. 예외처리가 만사능통은 아니다.
//    ==> 예외처리 사용시 속도 저하는 꽤나 큰 문제이다.
class A 
{
public:
    ~A()
    {
        std::cout <<"A is destructed"<<std::endl;
        throw "error";  // 런타임 에러
    }
};


int main()
{
    try
    {
        A a;
    }
    catch(...)
    {
        std::cout <<"main() catch error" << endl;
    }
    return 0;
}