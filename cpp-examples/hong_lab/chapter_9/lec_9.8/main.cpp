//static_cast 형변환을 오버로딩 하기
#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0):m_cents(cents)
    {}
    int& getCents() 
    {
        return m_cents;
    }
    void setCents(int cents)
    {
        m_cents = cents;
    }
    operator int()  //int type으로 형변환
    {
        cout << "cast here" << endl;
        return m_cents;
    }
};
class Dollar
{
private:
    int m_dollars = 0;
public:
    Dollar(const int& input) : m_dollars(input)
    {}

    operator Cents() // 다음 오버로딩을 통해 Dollar의 객체는 앞으로 타입이 Cents으로 바뀌어 선언된다.
    {
        return Cents(m_dollars*100);
    }
};


void printInt(const int &value)
{
    cout << value << endl;
}


int main()
{
    Cents cents;
    printInt(cents.getCents()); // line 20 번째 코드가 없다면, 원래는 이렇게 표현해야됨

    printInt(cents); // line 20 번째 코드가 없다면 컴파일 에러 발생!

    Dollar dollars(2);
    Cents cents2 = dollars; // line 34에 의해, dollars 객체는 type이 Dollar가 아니라 Cents이고, 이를 Cents 클래스의 복사생성자를 통해 cents2 객체를 새로 생성한다. 이후
                            // line 20에 의해 생성된 cents2 객체는 다시 int type으로 오버로딩되고
    printInt(cents2);// 따라서 printInt함수의 입력인자인 정수로 사용될 수 있게 된다.
    return 0;
}