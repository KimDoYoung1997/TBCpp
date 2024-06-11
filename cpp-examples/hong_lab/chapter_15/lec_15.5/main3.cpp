#include <iostream>
#include <memory>
#include "include/Resource.h"

auto doSomething2(std::unique_ptr<Resource> &res)   // 만약 참조 하지 않고 다음과 같이그대로 받으면 auto doSomething2(std::unique_ptr<Resource> res) , unique_ptr의 성질에 의해 컴파일 에러가 발생함
{

    return res->setAll(10);   // case 3
}

int main()
{
    auto res1 = std::make_unique<Resource>(5); 
    res1->setAll(1);
    res1->print();

    std::cout <<"doSomething2 함수 호출 전 "<<std::endl;
    doSomething2(res1);
    std::cout <<"doSomething2 함수 호출 완료 "<<std::endl;
    res1->print();



    return 0;
}

