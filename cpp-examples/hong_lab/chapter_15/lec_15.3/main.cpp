#include <iostream>
#include "include/Timer.h"
#include "include/Resource.h"
#include "include/AutoPtr.h"
using namespace std;


int main()
{
    cout << "hi" << endl;
    int num = 6;
    Resource res(num);  // Base Constructor 기본 생성자
    Resource res2(res); // Copy Constructor 복사 생성자
    res2=res;           // Copy assignment 대입 연산자

    std::cout <<std::endl;
    AutoPtr<Resource> at_res;

    std::cout <<std::endl;
    AutoPtr<Resource> at_res2(at_res);
    return 0;
}