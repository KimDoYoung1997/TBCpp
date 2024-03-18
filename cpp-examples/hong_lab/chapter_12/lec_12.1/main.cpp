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
    void speak() const
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
    Animal animal("animal");
    Cat cat("cat");
    Dog dog("dog");

    cout <<"-------------------------------------------------"<< endl;
    animal.speak();
    cat.speak();
    dog.speak();
    cout <<"----------------------다형성 적용 이후---------------------------"<< endl;
    
    //자식  클래스를 부모 클래스 타입의 포인터를 사용해서 캐스팅을 시킨후, 호출하면 자기가 부모 클래스 인줄 알고 작동한다.
    Animal* ptr_animal1 = &cat;
    Animal* ptr_animal2 = &dog;
    ptr_animal1->speak(); // cat ??? 
    ptr_animal2->speak(); //dog ??? 



    return 0;
}