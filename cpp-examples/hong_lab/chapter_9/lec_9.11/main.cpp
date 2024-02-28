//대입 연산자 오버로딩
//깊은 복사 vs 얕은 복사

/*
동적 할당된 메모리에 대한 포인터 변수를 class의 멤버변수로 갖는 경우, 이 동적할당 포인터 멤버변수를 복사하거나 대입할때 깊은 복사인지,얕은 복사인지에 따라  
대입연산자 오버로딩 , 복사생성자 구현이 조금 까다로워진다.
*/

#include <iostream>
#include <cassert>
#include <cstring> // std::strlen을 사용하기 위해서
using namespace std;

class MyString
{
//private:
public:
    char * m_data = nullptr;
    int m_length = 0;
public:
    MyString(const char* source="")
    {
        assert(source);     //문자열이 비었다면 컴파일 에러 

        m_length = std::strlen(source)+1; // 문자열에 몇글자가 들어있는지 세보기 위해서. 문자열의 마지막인 null을 추가하기 위해 1을 미리 더함. strlen은 애당초 null을 제외한 길이를 출력하기 떄문이다.
        cout <<"m_length: " << m_length << endl; //null 공간까지 포함한 길이
        m_data = new char[m_length];

        for (int i=0;i<m_length;i++)
        {
            m_data[i]=source[i];
            //cout <<m_data<<" ";
        }//cout << endl;
        m_data[m_length-1]='\0';
        //cout << m_data[m_length-1] << endl;
    }

    char* getString()
    {
        return m_data;
    }

    int getLength()
    {
        return m_length;
    }

    ~MyString()
    {
        
        delete[] m_data;
        m_data = nullptr;
    }
};


int main()
{
    MyString hello("Hello");
    cout <<hello.m_data << endl;
    cout <<(int*)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
        MyString copy = hello;              // 기본 복사 생성자를 호출하는데, 기본 복사 생성자는 얕은 복사를 사용해서 문제가 발생함
        cout << (int*)copy.m_data << endl;  
        cout << copy.getString() << endl;
    }
    cout << hello.getString() << endl;      // 이미 heap에 메모리를 지웠기때문에 쓰레기값이 들어가있다.

    return 0;
}