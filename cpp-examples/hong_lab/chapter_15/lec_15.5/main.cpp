#include <iostream>
#include <memory>
#include "include/Resource.h"

auto doSomething()
{
    // return std::unique_ptr<Resource>(new Resource(5));   // case 1
    /*  
    auto temp_res = std::make_unique<Resource>(5);  // case 2
    return temp_res;    // case 2 
    */
    return std::make_unique<Resource>(5);   // case 3
}

int main()
{
    Resource* res = new Resource(100);
    delete res;

    // 방법 1.
    std::unique_ptr<Resource> up_res(new Resource(10000000));   
    std::unique_ptr<int> up_i(new int(10000000));  
    std::unique_ptr<int> up_i2(new int);  

    // 방법 2.
    auto *ptr = new Resource(5);
    std::unique_ptr<Resource> up_res2(ptr);

    // 방법 3. (조금 더 권장됨)
    auto res1 = std::make_unique<Resource>(5);      // auto 선언
    std::unique_ptr<Resource> res2 = std::make_unique<Resource>(5);     // 명시적 선언
    auto res3 = std::make_unique<int>(5);      // auto 선언

    auto res4 = doSomething();


    return 0;
}