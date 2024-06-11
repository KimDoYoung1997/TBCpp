#include <iostream>
#include <memory>
#include "include/Resource.h"


int main()
{
    auto res1 = std::make_unique<Resource>(5); 

    res1->setAll(5);    // 모든 element 에 입력 argument값을 대입
    res1->print();
    std::unique_ptr<Resource> res2;     // 초기화가 되지 않았기때문에 nullptr임    
    std::unique_ptr<Resource> res3(new Resource());     
    auto res4 = std::make_unique<Resource>();

    std::cout <<std::boolalpha;
    std::cout <<"res1 "<< static_cast<bool>(res1) << std::endl;  // true res1은 Resource 객체를 소유하는 std::unique_ptr입니다. std::make_unique를 사용하여 Resource 객체를 동적으로 할당하고, res1이 그 자원을 소유하게 됩니다.
    std::cout <<"res2 "<< static_cast<bool>(res2) << std::endl;  // false res2은 Resource 객체를 소유하지 않는 빈 std::unique_ptr입니다. 초기화되지 않았기 때문에 기본적으로 nullptr로 설정됩니다.
    // std::cout <<"res3 "<< static_cast<bool>(res3) << std::endl;  // true res3은 Resource 객체를 소유하는 std::unique_ptr입니다. std::make_unique를 사용하여 Resource 객체를 동적으로 할당하고, res3이 그 자원을 소유하게 됩니다.
    // std::cout <<"res4 "<< static_cast<bool>(res4) << std::endl;  // true res4은 Resource 객체를 소유하는 std::unique_ptr입니다. std::make_unique를 사용하여 Resource 객체를 동적으로 할당하고, res4이 그 자원을 소유하게 됩니다.

    // unique ptr는 copy semantic 은 불가능, move semantic만 사용 가능함
    // res2 = res1; 할 경우 copy 이므로 컴파일 에러가 발생함!
    res2 = std::move(res1);   // std::make_unique<Resource>(5)에대한 res1 unique_ptr 의 소유권을 res2 unique_ptr 에 넘겨준다
    std::cout<<"***** after res2=std::move(res1) *****"<<std::endl;
    std::cout <<"res1 "<< static_cast<bool>(res1) << std::endl;  // true res2은 Resource 객체를 소유하지 않는 빈 std::unique_ptr입니다. 초기화되지 않았기 때문에 기본적으로 nullptr로 설정됩니다.
    std::cout <<"res2 "<< static_cast<bool>(res2) << std::endl;  // true res2은 Resource 객체를 소유하지 않는 빈 std::unique_ptr입니다. 초기화되지 않았기 때문에 기본적으로 nullptr로 설정됩니다.

    if (res1 != nullptr) res1->print();
    if (res2 != nullptr) res2->print();


    return 0;
}

