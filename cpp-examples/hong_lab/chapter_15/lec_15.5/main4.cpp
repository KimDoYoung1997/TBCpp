#include <iostream>
#include <memory>
#include "include/Resource.h"

// 만약 죽어도 auto doSomething2(std::unique_ptr<Resource> res) 를 써야하는 상황이라면, doSomething2 함수를 호출 하는 부분에서 std::move 를 사용해서 소유권을 이전해줘야 한다.
auto doSomething2(std::unique_ptr<Resource> res)   
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
    doSomething2(std::move(res1));  // res1이 move하여 소유권을 이전해주고, 이에 따라 res1은 nullptr이 되어버림
    std::cout <<"doSomething2 함수 호출 완료 "<<std::endl;

    std::cout <<std::boolalpha ; //std::cout << std::boolalpha;를 사용하면 bool 값을 true 또는 false로 출력할 수 있다.
    std::cout <<"res1 "<< static_cast<bool>(res1) << std::endl;  // false
    if (res1 != nullptr) res1->print();




    return 0;
}

