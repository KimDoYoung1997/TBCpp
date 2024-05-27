#include <iostream>
#include <memory> //스마트 포인터
using namespace std;


// 예외처리의 위험성
// 1. 예외처리를 하다보면 메모리 처리가 안 돼서 memory leak 문제가 발생할 수 있다.
//    ==> 스마트 포인터를 사용하여 안전하게 처리 가능

int main()
{
    try
    {
        int *i = new int[100];
        std::unique_ptr<int> up_i(i);
        //do something with i

        throw "error";  // 만약 다음과 같이 에러가 발생한다면, unique_ptr의 철학에 의거해 메모리가 올바르게 해제된다.
        std::cout <<"delete i" << std::endl;

    }
    catch(const char* str)
    {
        std::cout <<"main() catch error" << endl;
    }
    return 0;
}