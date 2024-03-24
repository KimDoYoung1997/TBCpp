/*
순수(pure) 가상 함수, 추상(abstract) 기본 클래스, 인터페이스(interface) 클래스

지금까지는 다형성에서 Virtual Function을 구현할 때 자식 클래스에서 조금 더 자기에게 적합한 함수를 오버라이딩 하는 관점을 공부했다.
이번 시간에는 설계라는 관점에서 기본 클래스를 만들 때, 자식 클래스에게 이러이러한 걸 반드시 해야 된다라는 제약을 걸어두고, 기본 클래스가 만들어질때
이러 이러한 이유로 만들어 졌다 라는 것을 지킬 수 있도록 강제하는 방법에 대해서 배워볼 것이다.

"순수(pure) 가상 함수"는 body가 없음. 따라서 자식 클래스에서 반드시 override 해줘야하는 강제성이 존재함
이러한 순수 가상 함수가 포함이 된 클래스를 "추상 클래스"라 부른다. 보통은 기본(base) 클래스 를 추상 클래스로 만든다.
또한, 순수 가상 함수로만 이루어진 클래스를 "인터페이스 클래스" 라고 부른다.

*/

#include <iostream>
#include <string>
using namespace std;

class Animal 
{
protected:
    string m_name;
public:
    Animal(std::string name_in):m_name(name_in)
    {}

public:
    std::string getName()
    {
        return m_name;
    }

    // virtual void speak() const
    // {
    //     cout << m_name << " ??? " << endl;
    // }

    // 순수 가상 함수 : 클래스 중에서 객체 생성을 목적으로 정의되지 않는 클래스도 존재한다. 가상함수를 '순수' 가상 함수로 선언하여 객체의 생성을 문법적으로 막기 위해 사용되었다.
    virtual void speak() const = 0;

};

class Cat : public Animal
{
public:
    Cat(std::string name_in):Animal(name_in)
    {}

    virtual void speak() const override
    {
        cout << m_name << " Meow " << endl;
    }

};

class Dog  : public Animal
{
public:
    Dog(string name_in):Animal(name_in)
    {}

    virtual void speak() const override
    {
        cout << m_name << " Woof " << endl;
    }
};


class Cow  : public Animal
{
public:
    Cow(string name_in):Animal(name_in)
    {}

    virtual void speak() const override
    {
        cout << m_name << " Mooo " << endl;
    }
};


int main()
{
    // 순수 가상 함수 : 클래스 중에서 객체 생성을 목적으로 정의되지 않는 클래스도 존재한다. 가상함수를 '순수' 가상 함수로 선언하여 객체의 생성을 문법적으로 막기 위해 사용되었다.
    //Animal animal("animal");
    // animal.speak();

    Animal* animals[] = {new Cat("cat1"),new Cat("cat2"),new Dog("dog1"), new Dog("dog2"),new Cow("cow1")};

    for(int i=0 ; i<5;i++)
    {
        animals[i]->speak();
    }
    
    for(int i=0 ; i<5;i++)
    {
        delete animals[i];
    }
    
    return 0;
}