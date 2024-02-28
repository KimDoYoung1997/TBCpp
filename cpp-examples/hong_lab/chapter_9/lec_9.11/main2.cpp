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
        //cout <<"m_length: " << m_length << endl; //null 공간까지 포함한 길이
        m_data = new char[m_length];

        for (int i=0;i<m_length;i++)
        {
            m_data[i]=source[i];
            //cout <<m_data<<" ";
        }//cout << endl;
        m_data[m_length-1]='\0';
        //cout << m_data[m_length-1] << endl;
    }

    // 복사생성자(Copy constructor)에 깊은 복사 개념 도입
    MyString(MyString& source)
    {
        cout <<"Copy constructor" << endl;
        m_length = source.m_length;
        if (source.m_data != nullptr) // deepcopy
        {
            m_data = new char[m_length]; // 그냥 힙에 새로 메모리공간을 할당받은 후 깊은 복사 해버린다.
            for (int i=0;i<m_length;i++)
            {
                m_data[i]=source.m_data[i];
            }

        }
        else 
        {
            m_data=nullptr;
        }
    }

    // = 대입 연산자 오버로딩
    MyString& operator=(const MyString&source)
    {
        cout <<"Assignment operator"<< endl;

        if (this==&source)              // prevent self-assignment  ex) hello = hello 
        {
            return *this;
        }

        delete[] m_data;                //기존에 메모리공간에 무언가 있따면 이를 지우기

        m_length = source.m_length;

        if (source.m_data!=nullptr)
        {
            m_data = new char[m_length]; // 메모리 재할당
            for (int i=0;i<m_length;i++)
            {
                m_data[i]=source.m_data[i];
            }
        }
        else 
        {
            m_data = nullptr;
        }

        return *this;

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
    //cout <<hello.m_data << endl;
    cout <<(int*)hello.m_data << endl;      //0x559332bd0eb0
    cout << hello.getString() << endl;

    {
        MyString copy = hello;              // 기본 복사 생성자를 호출하는데, 기본 복사 생성자는 얕은 복사를 사용해서 문제가 발생함 -> 커스텀한 복사생성자로 문제 해결하자
        cout << (int*)copy.m_data << endl;  // 0x559332bd12e0
        cout << copy.getString() << endl;
    }
    cout << hello.getString() << endl;



    
    MyString str1 = hello;  // Copy constructor가 호출되는 경우. str1이 만들어지는 순간이므로 복사생성자가 호출된다. 분명 assignment operator가 있지만 이처럼 표현하면 복사생성자가 호출된다.
    MyString str2;

    str2 = hello;           // assignment operator가 호출되는 경우. str1과 hello는 이미 둘 다 생성자가 한 번 호출된 이후이다. 생성자는 객체당 한 번씩만 호출되는 특징이 있다. 
                            // 따라서 이미 호출이 끝난 객체들끼리 대입하는 경우에는 대입 연산자가 호출된다.
    

    return 0;
}