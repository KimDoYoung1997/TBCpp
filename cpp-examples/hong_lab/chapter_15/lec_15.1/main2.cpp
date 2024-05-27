#include <ios>
#include <iostream>
#include "include/Resource.h"
#include "include/AutoPtr.h"
using namespace std;

// Move semantics and Smart pointer
// RAII : Resource Acuisition is Initialization : new한 곳에서 delete 해줘야 한다.


int main()
{
    AutoPtr<Resource> res1(new Resource);   // int i ; int *ptr1(&i)
    AutoPtr<Resource> res2; // int *ptr2 = nullptr;

    cout <<std::boolalpha ; //std::cout << std::boolalpha;를 사용하면 bool 값을 true 또는 false로 출력할 수 있다.
    cout <<"res1.isNull() " << res1.isNull() <<endl;
    cout <<"res2.isNull() " << res2.isNull() <<endl;

    cout << res1.m_ptr << endl;
    cout << res2.m_ptr << endl;

    res2 = res1;    // res2의 기본 대입 연산자 호출


    cout <<"res1.m_ptr 주소 "<< res1.m_ptr << endl;
    cout <<"res2.m_ptr 주소 "<< res2.m_ptr << endl;
    cout <<"res1.m_ptr == res2.m_ptr ? " << (res1.m_ptr == res2.m_ptr) <<endl;

    // 동일한 메모리를 2번 해제하므로  "free(): double free detected in tcache 2" 에러 발생
    return 0;
}