//산술 연산자 오버로딩

#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents=0){m_cents=cents;}

    int getCents() const 
    {
        // cout <<"Int getCents() const"<< endl;

        return m_cents;
    }
    int& getCents() 
    {
        // cout <<"Int& getCents"<< endl;


        return m_cents;
    }
};

// Cents add(const Cents &cent1, const Cents &cent2)
// {
//     return Cents (cent1.getCents() + cent2.getCents());
// }

Cents operator +(const Cents &cent1, const Cents &cent2) // add 함수을 operator + 으로 바꿈. 연산자 오버로딩
{
    return Cents (cent1.getCents() + cent2.getCents()); // Anonymous object 익명 객체를 return으로 사용
}




int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents sum;
    // sum=add(cents1,cents2);

    sum=cents1+cents2;

    cout << sum.getCents() << endl;
    // cout << add(cents1,cents2).getCents() << endl;
    cout << (cents1+cents2).getCents() << endl;
    cout << (cents1+cents2+Cents(6)).getCents() << endl; // Anonymous object 익명 객체까지 add

    return 0;
}