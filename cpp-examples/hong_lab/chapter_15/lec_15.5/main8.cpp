#include <iostream>
#include <memory>
#include "include/Resource.h"
// https://chatgpt.com/c/d2613206-39a1-40ee-a8f0-9fc63c886289
// 논리상 오류 발생 예시 : unique_ptr를 shared_ptr 처럼 사용한 경우
int main()
{
    Resource *res = new Resource(10);
    res->setAll(3);
    res->print();
    std::unique_ptr<Resource> uq_ptr1(res);                 // uq_ptr1 초기화 완료
    std::unique_ptr<Resource> uq_ptr2(std::move(uq_ptr1));  // unique_ptr에서 unique_ptr로 소유권 이전

    std::cout <<std::boolalpha ; //std::cout << std::boolalpha;를 사용하면 bool 값을 true 또는 false로 출력할 수 있다.
    std::cout <<"res "<< static_cast<bool>(res) << std::endl;  
    std::cout <<"uq_ptr1 "<< static_cast<bool>(uq_ptr1) << std::endl;  
    std::cout <<"uq_ptr2 "<< static_cast<bool>(uq_ptr2) << std::endl;  


// free(): double free detected in tcache 2 Aborted (core dumped) 컴파일 에러 발생
    std::unique_ptr<Resource> uq_ptr3(res);                 // uq_ptr1 초기화 완료
    std::cout <<"uq_ptr3 "<< static_cast<bool>(uq_ptr3) << std::endl;  


    return 0;
}

