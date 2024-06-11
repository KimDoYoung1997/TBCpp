#include <ios>
#include <iostream>
#include <memory>
#include "include/Resource.h"
// 만약 참조 하지 않고 다음과 같이그대로 받으면 auto doSomething2(std::unique_ptr<Resource> res) , unique_ptr의 성질에 의해 컴파일 에러가 발생함
// 만약 죽어도 auto doSomething2(std::unique_ptr<Resource> res) 를 써야하는 상황이라면, doSomething2 함수를 호출 하는 부분에서 std::move 를 사용해서 소유권을 이전해줘야 한다.

// auto doSomething2(std::unique_ptr<Resource> res)   
// {
//     std::cout <<"case 1."<<std::endl;
//     return res->setAll(10);   // case 3
// }

// 다음과 같이 R-value reference를 사용해서 받으면 
auto doSomething2(std::unique_ptr<Resource> &&res)   
{
    std::cout <<"case 2."<<std::endl;
    return res->setAll(10);   // case 3
}

auto doSomething2(std::unique_ptr<Resource> &res)   
{
    std::cout <<"case 3."<<std::endl;
    return res->setAll(20);   // case 3
}

int main()
{
    auto res1 = std::make_unique<Resource>(5); 
    res1->setAll(1);
    res1->print();
    auto res2 = std::make_unique<Resource>(5); 
    res2->setAll(2);
    res2->print();


    std::cout <<"doSomething2 함수 호출 전 "<<std::endl;
    // doSomething2(res1);
    doSomething2(std::move(res1));  // res1이 move가 되므로 nullptr이 되어버림. res1이 case2에서 R-value참조됨.
    doSomething2(res2);             // res2가 case3에서 l-value 참조됨.
    std::cout <<"doSomething2 함수 호출 완료 "<<std::endl;

    std::cout <<std::boolalpha ; //std::cout << std::boolalpha;를 사용하면 bool 값을 true 또는 false로 출력할 수 있다.

    std::cout <<"res1 "<< static_cast<bool>(res1) << std::endl;  // true res1이 move가 되므로 nullptr이 되어버릴줄 알았으나, R-value 참조자때문인지 소유권이 남아있음
    std::cout <<"res2 "<< static_cast<bool>(res2) << std::endl;  // true res2은 Resource 객체를 소유하지 않는 빈 std::unique_ptr입니다. 초기화되지 않았기 때문에 기본적으로 nullptr로 설정됩니다.

    if (res1 != nullptr) res1->print();
    if (res2 != nullptr) res2->print();




    return 0;
}

