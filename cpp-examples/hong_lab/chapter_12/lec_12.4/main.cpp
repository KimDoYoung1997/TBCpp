/*
가상 소멸자

상속 구조에서 생성자는 보통 자식 클래스 자신의 생성자를 사용해왔다.
하지만 소멸자는 가상 소멸자를 사용해야 한다.
이번 시간에 왜 가상 소멸자를 사용해야하는지 그 중요성을 알아보도록 하자.
*/


/*
아래 코드 실행 결과, 문제 없이 작동된다. 하지만 main2.cpp에서 다형성을 논하기 시작하면서 문제가 발생한다. 

Base()
Derived()
~Derived()
~Base()

*/

#include <iostream>

using namespace std;

class Base
{
public: 
    Base()
    {
        cout<<"Base()" << endl;
    }
    ~Base()
    {
        cout <<"~Base()" << endl;
    }


};

class Derived : public Base
{
private:
    int *m_array;
public:
    Derived(int length)
    {
        cout <<"Derived()"<< endl;
        m_array = new int[length];
    }

    ~Derived()
    {
        cout <<"~Derived()"<< endl;
        delete[] m_array;
    }


};


int main()
{
    //Base base;
    Derived der(3);

    return 0;
}