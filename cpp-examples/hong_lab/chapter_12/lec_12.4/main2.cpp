/*
가상 소멸자

상속 구조에서 생성자는 보통 자식 클래스 자신의 생성자를 사용해왔다.
하지만 소멸자는 가상 소멸자를 사용해야 한다.
이번 시간에 왜 가상 소멸자를 사용해야하는지 그 중요성을 알아보도록 하자.
*/


/*
함수의 다형성을 고려하면 여러 문제가 발생한다. 대부분 자식 클래스의 부모가 누구인지 모르기 마련이다.
그래서 보통 부모 클래스의 포인터를 이용하여 메모리 delete를 하는 경우가 많다.
부모 함수에서 가상 소멸자를 사용하지 않고, 그대로 메모리 delete 하는경우 문제가 발생할 수 있다.

좀 더 쉽게 말하자면 부모 클래스(Animal)는 하나고, 자식 클래스(Cat,Dog,Dragon...)는 대부분 여러가지 일 것이다.
다형성의 장점을 사용한다는 것은 메모리를 지울때 부모 클래스 포인터의 메모리 delete로, 그 자식 클래스들까지 메모리 delete하는것을 의미한다.

이번 main2.cpp에서 어떤 문제가 발생하는지 몸으로 느껴보자.



/*
실행 결과는 아래와 같다. 즉 자식 클래스의 소멸자가 호출되지 않아 메모리 leak이 발생한다.
물론 컨테이너 자료형을 사용하면 이러한 문제는 해결 되겠지만,, 지금은 초심자의 마음으로 공부해보자.

Base()
Derived()
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
    // 동적할당
    Derived *derived = new Derived(5);

    // 다형성 적용
    Base *base = derived;

    // 부모클래스의 base 를 메모리 delete 해보자. 자식 클래스(derived)의 소멸자가 호출 되는가?
    // 다형성의 장점이 그대로 반영되었다면, base객체를 delete함으로서 derived 객체의 메모리까지 delete하는것의 개발자의 의도일 것이다.
    delete base;






    return 0;
}