#include <cstdint>
#include <iostream>

using namespace std;

// 기본 클래스
class Animal {
public:
    //clone() 메서드는 Animal 객체를 복제하고 그 포인터를 반환합니다.
    virtual Animal* clone() {
        cout << "Cloning an Animal..." << endl;
        return new Animal(*this);
    }

    virtual ~Animal() {}  // 가상 소멸자
};


/*
Cat과 Dog 클래스는 Animal을 상속받고 clone() 메서드를 오버라이드합니다. 이 때, 오버라이드된 clone() 메서드는 각각 Cat*와 Dog*를 반환합니다. 
이것이 공변 반환 타입의 예시입니다. 즉, 파생 클래스에서는 기본 클래스 메서드의 반환 타입을 그와 호환되는 더 구체적인 타입으로 변경할 수 있습니다.
*/


// 파생 클래스
//Cat과 Dog 클래스는 Animal을 상속받고 clone() 메서드를 오버라이드합니다.
class Cat : public Animal {
public:
    Cat* clone() override {
        cout << "Cloning a Cat..." << endl;
        return new Cat(*this);
    }
};

//Cat과 Dog 클래스는 Animal을 상속받고 clone() 메서드를 오버라이드합니다.
class Dog : public Animal {
public:
    Dog* clone() override {
        cout << "Cloning a Dog..." << endl;
        return new Dog(*this);
    }
};


int main() {
    Animal* myAnimal = new Cat();  // Animal 타입으로 Cat 객체 생성
    Animal* clonedAnimal = myAnimal->clone();  // Cat의 clone 호출

    cout << & myAnimal << endl;

    Animal* mySecondAnimal = new Dog(); // Animal 타입으로 Dog 객체 생성
    Animal* clonedSecondAnimal = mySecondAnimal->clone(); // Dog의 clone 호출

    delete myAnimal;
    delete clonedAnimal;
    delete mySecondAnimal;
    delete clonedSecondAnimal;

    return 0;
}



/*

[스택]                            [힙]
+-----------------+             +-----------------+
| main()          |             |                 |
| +-------------+ |             |  [Cat 객체]     |
| | myAnimal    |-------------> |                 |
| +-------------+ |             +-----------------+
|                 |             |                 |
| +-------------+ |             |  [Dog 객체]     |
| | mySecond... |-------------> |                 |
| +-------------+ |             +-----------------+
|                 |             |                 |
| +-------------+ |             |  [Cat 복제 객체]|
| | clonedAnimal|-------------> |                 |
| +-------------+ |             +-----------------+
|                 |             |                 |
| +-------------+ |             |  [Dog 복제 객체]|
| | clonedSecon.|-------------> |                 |
| +-------------+ |             +-----------------+
+-----------------+             


*/