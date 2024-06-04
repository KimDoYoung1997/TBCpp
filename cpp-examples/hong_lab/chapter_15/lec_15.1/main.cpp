#include <iostream>
#include "include/Resource.h"
#include "include/AutoPtr.h"
using namespace std;

// Move semantics and Smart pointer
// RAII : Resource Acuisition is Initialization : new한 곳에서 delete 해줘야 한다.

void doSomething()
{
    try
    {
        // Resource 자료형을 인자로 받는 AutoPtr 템플릿 클래스를 auto_res 객체로 동적 인스턴스화 함
        // 먼저 Resource 클래스의 생성자가 호출되고
        // AutoPtr 생성자가 그 다음 호출된다.
        AutoPtr<Resource> auto_res(new Resource);   // new Resource 는 임시객체

        // work with res
        if (true)
        {
            std::cout<<"throw" <<std::endl;
            throw -1;
        }

    }



    catch(...)
    {
        std::cout<<"catch exception" <<std::endl;
    }
    // delete res;

    std::cout <<"hhh" << std::endl;

    // if work done, exit
    return ;
}

int main()
{
    std::cout <<"main start" <<std::endl;
    doSomething();


    return 0;
}