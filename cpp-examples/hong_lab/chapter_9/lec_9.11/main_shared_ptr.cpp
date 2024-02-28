#include <iostream>
#include <cassert>
#include <cstring> // std::strlen을 사용하기 위해서
#include <memory>  // std::shared_ptr을 사용하기 위해서
using namespace std;

class MyString
{
public:
    shared_ptr<char[]> m_data;
    int m_length = 0;

public:
    MyString(const char* source="")
    {
        assert(source);
        m_length = std::strlen(source) + 1;
        m_data = shared_ptr<char[]>(new char[m_length]);

        strcpy(m_data.get(), source); // shared_ptr에 대한 get() 함수를 사용하여 실제 포인터에 접근
    }

    char* getString()
    {
        return m_data.get();
    }

    int getLength()
    {
        return m_length;
    }

    // 소멸자는 shared_ptr에 의해 자동으로 관리되므로 명시적으로 정의할 필요가 없습니다.
};

int main()
{
    MyString hello("Hello");
    cout << hello.getString() << endl;
    cout << static_cast<void*>(hello.getString()) << endl; // 포인터 주소 출력을 위해 void*로 캐스팅

    {
        MyString copy = hello; // shared_ptr는 자동으로 참조 카운트를 관리합니다.
        cout << static_cast<void*>(copy.getString()) << endl;  
        cout << copy.getString() << endl;
    } // copy가 범위를 벗어나도 hello의 m_data는 안전합니다.

    cout << hello.getString() << endl;

    return 0;
}
