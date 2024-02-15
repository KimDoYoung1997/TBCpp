//Anonymous object
#include <iostream>

using namespace std;

class A
{
public:

    A()
    {
        cout <<"Constructor"<< endl;
    }
    void print()
    {
        cout <<"Hello"<< endl;
    }
    ~A()
    {
        cout <<"Destructor"<< endl;
    }

};


int main()
{
    //A a;
    //a.print();

    A a;
    A().print(); // A()는 R-value처럼 작동함. -> 재사용 불가.
    A().print(); // A()는 R-value처럼 작동함. -> 재사용 불가.



    A()=a; // Anonymous object에 a 를 복사. -> 복사생성자
    /*
    A()=a; 이 구문은 흥미롭습니다. 여기서는 익명 객체를 생성하고, 명명된 객체 a를 이 익명 객체에 복사할당합니다.
    그러나 이 경우, 복사 생성자가 아닌 복사 할당 연산자가 호출됩니다. 복사 생성자는 객체가 생성될 때 호출되는 반면,
    복사 할당 연산자는 이미 생성된 객체에 대해 다른 객체의 상태를 복사할 때 호출됩니다. 
    이 코드는 익명 객체가 l-value처럼 동작할 수 있음을 보여주지만, 복사된 후 바로 소멸되므로 실제 유용성은 제한적입니다.
     "Constructor"와 "Destructor" 메시지만 출력되며, 복사 생성자나 할당 연산자에 의한 추가 출력은 없습니다.
    */
   
    
    A a3{A()};
    /*
    A a3{A()};는 익명 객체를 사용해 a3 객체를 초기화하는 과정을 보여줍니다.
    여기서도 익명 객체의 생성자가 호출되어 "Constructor"가 출력되고, 이 객체는 a3를 초기화한 후 바로 소멸합니다.
    따라서 "Destructor" 메시지도 출력됩니다. 이 구문에서는 복사 생성자가 호출될 수 있으나,
    컴파일러 최적화로 인해 실제 복사 생성자 호출이 생략되고 직접 초기화가 이루어질 수 있습니다(RVO, 반환 값 최적화).
    */
    return 0;
}