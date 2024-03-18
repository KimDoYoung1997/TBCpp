#include <iostream>

using namespace std;

class A
{
public:
    virtual void print(int x)
    {
        cout <<" A " << endl;
    }
};

class B : public A
{
public:
    // 실수로 override 하려는 print 함수의 입력 인자를 int 타입이 아닌 short 타입을 넣었다. 만약 내 의도가 base 클래스의 print 함수를 "오버라이딩" 하려 했다면
    // 다음 아래는 내 의도치 않게 에러 없이 함수 "오버로딩" 의 원리에 의해 실행된다.
    // virtual void print(short x) override
    // {
    //     cout <<" B " << endl;
    // }


    // 즉 자식 클래스에서 부모 클래스의 특정 함수를 override 하고 싶은거라면, 내 의도가 그게 명확하다면 override 키워드를 사용함으로서 컴파일 에러를 미리 막을 수 있다.
    virtual void print(int x) override
    {
        cout <<" B " << endl;
    }


};

class C : public B
{
public:
    // 이후 생성 되는 자식 클래스들은 print 함수의 override 를 final 키워드를 사용함으로서 미리 막아둠
    virtual void print(int x) final
    {
        cout <<" C " << endl;
    }
};


int main()
{
    A a;
    B b;

    A &ref = b;
    //ref.print();
    ref.print(3);

    return 0;
}