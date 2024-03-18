#include <iostream>

using namespace std;


class A
{
public:
    void print(){cout <<" A " << endl;}
};

class B : public A
{
public:
    void print(){cout <<" B " << endl;}

};

class C : public B
{
public:

    void print(){cout <<" C " << endl;}

};

class D : public C
{
public:
    void print(){cout <<" D " << endl;}

};

int main()
{


    A a;
    B b;
    C c;
    D d;

    cout <<"-------------- Case 1 --------------"<< endl;
    A* ptr_a = &a;
    ptr_a->print();
    ptr_a = &b;
    ptr_a->print();
    ptr_a = &c;
    ptr_a->print();
    ptr_a = &d;
    ptr_a->print();
    cout <<"-------------- Case 2 --------------"<< endl;
    // reference 를 사용해보자
    A& ref = a;
    ref.print();
    A& ref2 = b;
    ref2.print();
    A& ref3 = c;
    ref3.print();
    A& ref4 = d;
    ref4.print();

    cout <<"-------------- Case 3 --------------"<< endl;
    // reference 를 사용해보자 2
    B& ref_ = b;
    ref_.print();
    B& ref2_ = c;
    ref2_.print();
    B& ref3_ = d;
    ref3_.print();



    return 0;
}