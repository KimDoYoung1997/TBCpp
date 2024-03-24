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
    //cout << base->m_j << endl; 컴파일 에러
    auto * base_to_d1 = dynamic_cast<Derived1*>(base);  //base 객체가 Derived1으로 형변환
    cout << base_to_d1->m_j << endl;
    base_to_d1->m_j = 2048;
    cout << d1.m_j << endl;


    return 0;
}