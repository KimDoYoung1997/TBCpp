#include <iostream>
#include "include/Timer.h"
#include "include/Resource.h"
#include "include/AutoPtr.h"
using namespace std;

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(1000000));   // 2. Resource(unsigned length) constructor 호출
                                                    // 3. AutoPtr default constructor 호출
    return res;     // return될 때 임시객체가 생성되면서 4. AutoPtr copy assignment 호출
                    // AutoPtr copy constructor 내부에서 5. Resource 클래스의 default constructor와 
                    // 6. Resource 클래스의 copy assignment가 호출
}

int main()
{
    cout << "hi 2" << endl;
    AutoPtr<Resource> at_res;   // 1. AutoPtr default constructor 호출
    at_res=generateResource();  // 7. 임시객체가 at_res에 다시 대입되면서 AutoPtr copy assignment 호출
                                // 8. Resource 클래스의 default constructor 가 호출
                                // 9. Resource 클래스의 copy assignment가 호출
    return 0;
}