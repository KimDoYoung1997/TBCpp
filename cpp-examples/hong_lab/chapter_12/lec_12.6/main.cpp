/*
가상(함수) 표 : Virtual Tables

다형성을 사용할 때는 상속 구조에 따라서 가상 함수들이 어떻게 호출 될지 결정이 된다.
이때, 가상 함수에 대한 표를 마들ㄷ고 사용을 하게 되는데, 가상 함수 표에 대해서 알아보자.

*/

#include <iostream>
using namespace std;

class Base
{
public:
    //FunctionPointre *_vptr;
    int a;      // 4 byte    
    int a2;     // 4 byte

    // virtual pointer 8byte
    virtual void func1(){};     
    virtual void func2(){};
};

class Derived : public Base
{
public:
    //FunctionPointre *_vptr;
    int b;      // 4 byte
    int b2;     // 4 byte

    // virtual pointer 8byte
    virtual void func1(){};
    virtual void func3(){};
};




int  main()
{
    Base base;
    Derived derived;
    cout << sizeof(base) << endl;
    cout << sizeof(derived) << endl;
    cout << derived.a<<endl;
    return 0;
}