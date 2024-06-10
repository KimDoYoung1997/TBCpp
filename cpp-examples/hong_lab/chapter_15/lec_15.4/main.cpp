#include <iostream>
#include "include/AutoPtr.h"
#include "include/Resource.h"
int main()
{
    using namespace std;
    AutoPtr<Resource> res1(new Resource(10000));
    cout <<"AutoPtr res1의 m_ptr 주소값 : "<< res1.m_ptr << endl;
    AutoPtr<Resource> res2(res1);   // res2는 AutoPtr클래스의 복사 생성자(copy constructor)를 통해 생성. 
                                    // 이 과정에서 Resource의 default constructor가 호출되고
                                    // 이후 Resource 클래스의 copy assignment가 호출됨

    cout <<"AutoPtr res1의 m_ptr 주소값 : "<< res1.m_ptr << endl;
    cout <<"AutoPtr res2의 m_ptr 주소값 : "<< res2.m_ptr << endl;

    AutoPtr<Resource> res3(std::move(res2));   // res3는 AutoPtr클래스의 이동 생성자(move constructor)를 통해 생성. 
    cout <<"AutoPtr res1의 m_ptr 주소값 : "<< res1.m_ptr << endl;
    cout <<"AutoPtr res2의 m_ptr 주소값 : "<< res2.m_ptr << endl;
    cout <<"AutoPtr res3의 m_ptr 주소값 : "<< res3.m_ptr << endl;

    return 0;
}
