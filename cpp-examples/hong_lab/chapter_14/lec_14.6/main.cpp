#include <iostream>
#include <memory> //스마트 포인터
using namespace std;


// 예외처리의 위험성
// 1. 예외처리를 하다보면 메모리 처리가 안 돼서 memory leack 문제가 발생할 수 있다.

int main()
{
    try
    {
        int *i = new int[100];

        //do something with i

        throw "error";  // 만약 다음과 같이 에러가 발생한다면, 메모리 delete가 되지 않고 바로 catch가 넘어가는 leack문제가 발생함.

        std::cout <<"delete i" << std::endl;
        delete [] i;

    }
    catch(const char* str)
    {
        std::cout <<"main() catch error" << endl;

    }
    return 0;
}