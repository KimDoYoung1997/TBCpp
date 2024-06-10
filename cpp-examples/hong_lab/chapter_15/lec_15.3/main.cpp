#include <iostream>
#include "include/Timer.h"
#include "include/Resource.h"
#include "include/AutoPtr.h"    // copy constructor 와 copy assignment 구현

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000));
    return res;
}


int main()
{
    // using namespace std;
    // streambuf* origin_buf = cout.rdbuf();

    // Timer timer;
    // {
    //     AutoPtr<Resource> main_res;
    //     main_res = generateResource();
    // }

    // cout.rdbuf(origin_buf);
    // // cout << << endl;
    // cout << (timer.elapsed()) << endl;
    int num = 6;
    Resource res(num);  // Base Constructor 기본 생성자
    Resource res2(res); // Copy Constructor 복사 생성자
    res2=res;           // Copy assignment 대입 연산자

    std::cout <<std::endl;
    // AutoPtr<Resource> at_res;
    AutoPtr<Resource> at_res(new Resource(6));

    // std::cout <<std::endl;
    std::cout <<"-------------------------------------------------------"<<std::endl;
    AutoPtr<Resource> at_res2(at_res);  // AutoPtr 복사 생성자 호출
    std::cout <<"-------------------------------------------------------"<<std::endl;

    std::cout <<"all code is executed. Now stack is unwinded" << std::endl;
    std::cout <<std::endl;

    return 0;
}