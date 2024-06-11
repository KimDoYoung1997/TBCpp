#include <iostream>
#include <memory>
#include "include/Resource.h"

// unique_ptr 의 메소드인 get() 함수를 이용하여, 담고 있는 데이터의 포인터값을 얻을 수 있다. 이를 doSomething2 의 입력 인자로 전달
auto doSomething2(Resource *res)   
{
    std::cout <<"case 1."<<std::endl;
    res->setAll(10);   // case 3
    return res->setAll(10);   // case 3
}

int main()
{
    auto res1 = std::make_unique<Resource>(5); 
    res1->setAll(1);
    res1->print();



    std::cout <<"doSomething2 함수 호출 전 "<<std::endl;
    // doSomething2(res1);
    doSomething2(res1.get());  // unique_ptr 의 메소드인 get() 함수를 이용하여, 담고 있는 데이터의 포인터값을 얻을 수 있다.
    std::cout <<"doSomething2 함수 호출 완료 "<<std::endl;

    std::cout <<std::boolalpha ; //std::cout << std::boolalpha;를 사용하면 bool 값을 true 또는 false로 출력할 수 있다.
    std::cout <<"res1 "<< static_cast<bool>(res1) << std::endl;  // false
    if (res1 != nullptr) res1->print();




    return 0;
}

