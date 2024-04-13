#include <iostream>
#include <array>

using namespace std;

template<typename T>
class A 
{
public:
    T intput_;
    A(const T& input):intput_(input)
    {}
    void doSomething()
    {
        cout << typeid(T).name() << endl;
    }

    void test()
    {}
};

// 클래스 템플릿 특수화 , 거의 클래스를 새로 만드는거와 같음. 결국은 다른 클래스라고 보면 됨.
template<>
class A<char>
{
public:
    char input_;
    A(const char& input):input_(input)
    {}
    void doSomething()
    {
        cout << "Char type specialization" << endl;
    }
    // void test()
    // {}
};




/*
클래스 템플릿 특수화와 , 함수 템플릿 특수화는 동시에 못 사용하는구나!

template<>
void A<char>::doSomething()
{
    cout << "Char type specialization2" << endl;
}

template<>
void A<char>::test()
{
    cout << "Char type specialization2" << endl;
}

*/


int main()
{
    A<int> a_int(2);
    A<double> a_double(3.14);
    A<char> a_char('a');

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();

    a_int.test();
    a_double.test();
    
    // 컴파일 에러
    //a_char.test();

    return 0;
}