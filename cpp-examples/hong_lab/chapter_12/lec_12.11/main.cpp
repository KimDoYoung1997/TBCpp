/*
유도 클래스에서 출력 연산자 사용하기

다형성은 여러가지로 편리하고 유연한 사용방법을 제공하지만, 모든 경우에 다 다혀성을 사용할 수 없다. 대표적인 예가 출력 연산자이다.
출력 연산자는 오버라이딩 할 수 없다. 유도 클래스에서 출력 연산자를 다형성과 함께 사용하려면 어떻게 해야하는지 살펴보자

*/

# include <iostream>
using namespace std;


class Base
{
public:
    Base(){}

    // friend 는 멤버가 아니기때문에 직접 오버라이딩을 할 수 없다. 그래서 print 멤버 함수를 하나 만들고 이 멤버를 통해 간접적으로 출력 연산자를 오버로딩하자.
    friend std::ostream& operator <<(std::ostream &out , const Base &b)
    {
        return b.print(out);
    }
    virtual std::ostream& print(std::ostream &out) const
    {
        out <<"Base";
        return out;
    }

};

class Derived : public Base
{
public:
    virtual std::ostream& print(std::ostream &out) const
    {
        out <<"Derived";
        return out;
    }
};





int main()
{
    Base base;
    Derived derived;

    cout << base << endl;
    cout << derived << endl;

    Base& bref = derived;

    cout << bref << endl;


    return 0;
}