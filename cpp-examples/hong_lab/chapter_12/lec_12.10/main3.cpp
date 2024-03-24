/*
동적 형변환 (Dynamic Casting)

다형성을 사용하다 보면 종종 자식 클래스의 포인터를 부모 클래스의 포인터로 바꿨다가 다시 자식 클래스의 포인터로 바꿔줄 필요가 생긴다.
이때 사용할 수 있는 동적 형변환에 대해 알아보자.

*/

#include <iostream>
#include <string>
using namespace std;

class Base 
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout <<"I'm Base" << endl;
    }


};

class Derived1 : public Base
{
public:
    int m_j = 1024;
    virtual void print() override
    {
        cout <<"I'm Derived1" << endl;
    }
};



class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";
    virtual void print() override
    {
        cout <<"I'm Derived2" << endl;
    }
};


int main()
{
    Derived1 d1;
    Base *base = &d1;   // 다형성 적용. 이 경우 base에는 없고 derived1에만 있는 것들에 접근할 수 없다. (예를 들어 base에서 m_j에 접근할 수 없다.)
    auto * base_to_d1 = static_cast<Derived1*>(base);  //이번엔 dynamic_cast가 아닌 static_cast를 써보는 시도.

    if (base_to_d1 != nullptr)
        base_to_d1->print();    // 된다.
    else
        cout <<"Failed"<< endl;


    auto * base_to_d2 = static_cast<Derived2*>(base);  //이번엔 dynamic_cast가 아닌 static_cast를 써보는 시도 + Derived2로 형변환.

    if (base_to_d2 != nullptr)
        base_to_d2->print();    // 어? 된다. main2.cpp에선 안 된건데, static_cast를 쓰면 된다.   <--- static_cast는 할 수 있는한 최대로 형 변환하려 밀어 붙인다. 대신 런타임에선 에러 체크를 안 한다. 되도록 쓰지 마라.
    else
        cout <<"Failed"<< endl;



    return 0;
}


// Question 
/*
여기서 왜 64번째 줄의 base_to_d2->print();  의 실행 결과가 I'm Derived2 가 아닌 I'm Derived1 이야?
*/

// Answer
/*
static_cast를 사용하는 경우에 나타나는 현상에 대해 설명드리겠습니다. static_cast는 컴파일 시간에 타입 체크를 수행하는데, 이때 실제 객체의 타입이 아닌 코드 상에서 지정한 타입으로 변환을 시도합니다. 
다시 말해, static_cast는 포인터가 가리키는 실제 객체의 타입을 검사하지 않고, 개발자가 요청한 타입으로 무조건 변환을 시도합니다. 이는 런타임에 타입 안정성을 보장하지 않기 때문에 위험할 수 있습니다.

여기서 base 포인터는 실제로 Derived1 객체를 가리키고 있지만, static_cast<Derived2*>(base)를 사용하여 Derived2 타입으로 강제 변환을 시도합니다. 
이 변환은 컴파일 시간에 타입 체크를 통과하므로, 변환 자체는 성공적으로 이루어집니다. 하지만 실제 메모리에는 Derived1 객체가 있으므로, Derived2 타입으로 변환된 포인터를 사용하면 예기치 않은 동작이 발생할 수 있습니다.

64번째 줄에서 base_to_d2->print();가 I'm Derived1을 출력하는 것은 base_to_d2 포인터가 Derived2 타입으로 변환되었지만, 실제로 가리키는 객체는 Derived1 인스턴스이기 때문입니다.
이 코드에서는 Derived1과 Derived2 클래스가 동일한 베이스 클래스 Base를 상속받고 있고, print() 메서드는 가상 메서드로 오버라이드되었습니다. 따라서, base_to_d2 포인터를 통해 print() 메서드를 호출하면, 포인터가 실제로 가리키고 있는 객체의 타입에 따라 연결된 메서드가 호출됩니다. 
여기서는 base_to_d2가 실제로 Derived1 객체를 가리키고 있으므로, Derived1의 print() 메서드가 호출되어 I'm Derived1이 출력됩니다.

이러한 문제를 방지하기 위해 런타임에 타입 정보를 검사하고 안전하게 형 변환을 수행할 수 있는 dynamic_cast를 사용할 수 있습니다. dynamic_cast는 변환하려는 타입이 실제 객체의 타입과 호환되지 않는 경우 nullptr을 반환합니다(포인터에 대한 변환의 경우). 
따라서, dynamic_cast를 사용하면 이러한 타입의 오용을 런타임에 발견하고 안전하게 처리할 수 있습니다.
*/