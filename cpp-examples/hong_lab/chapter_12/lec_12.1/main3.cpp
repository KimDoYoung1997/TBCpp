/*
다형성의 기본 개념

자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면?

*/
#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    std::string m_name;
public:
    Animal(std::string name_in):m_name(name_in)
    {}
public:
    string getName()
    {
        return m_name;
    }
    // 가상 함수 virtual 키워드 이용
    virtual void speak() const
    {
        cout << m_name <<" ??? "<< endl;
    }
};

// Cat is an Animal 
class Cat : public Animal
{
public:
    Cat(std::string name_in):Animal(name_in)
    {}
public:
    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

//Dog is an Animal
class Dog : public Animal
{
public:
    Dog(std::string name_in):Animal(name_in)
    {}
public:
    void speak() const
    {
        cout << m_name <<" Woof " << endl;
    }
};



int main()
{
    Cat cats[] = {Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5")};
    Dog dogs[] = {Dog("dog1"),Dog("dog2")};

    Animal* animals[] = {&cats[0],&cats[1],&cats[2],&cats[3],&cats[4],&dogs[0],&dogs[1]};
    cout <<"-------------------------------------------------"<< endl;
    for(int i=0; i<7 ; i++)
    {
        animals[i]->speak();
        /*
        cat1 Meow 
        cat2 Meow 
        cat3 Meow 
        cat4 Meow 
        cat5 Meow 
        dog1 Woof 
        dog2 Woof 
        */
    }


    return 0;
}