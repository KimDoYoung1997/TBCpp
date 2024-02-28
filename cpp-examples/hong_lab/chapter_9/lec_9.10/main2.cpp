//프로그래머의 편의를 위해 생성자를 변환하는 Converting constructor(변환 생성자)
//이렇게 생성된 변환 샌성자를 사용하지 못하게 막아버리는 explicit 키워드
//또한 특정 생성자를 사용 못하게 하는 delete 키워드에 대해 배워보겠다.

#include <iostream>
#include <cassert>
#include <ostream>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    explicit Fraction(int num=0, int dem=1):m_numerator(num),m_denominator(dem) // 기본 생성자에 explicit을 넣는 순간, 입력 인자의 정확한 타입을 요구한다. 
    {
        assert(dem!=0);
    }
    Fraction(const Fraction& fraction):m_numerator(fraction.m_numerator),m_denominator(fraction.m_denominator)
    {
        cout <<"Copy constructor called"<< endl;
    }

    friend std::ostream& operator<<(std::ostream &out,Fraction &frac)
    {
        out << frac.m_numerator <<" / " << frac.m_denominator;
        return out;
    }

};

void doSomething(Fraction frac)
{
    cout << frac << endl;
}

int main()
{
    Fraction frac(7);
    cout << frac<< endl;

    doSomething(Fraction(7));   // 컴파일 잘 됨, 결과 : 7/1
    //doSomething(7);                 // explicit 키워드를 사용하는 순간, 이제 컴파일 에러가 발생함.
    //Fraction frac=7;                // 심지어 이것도 explicit 키워드때문에 컴파일 에러가 발생
    doSomething(frac);              // 이 경우는 컴파일 에러 없이 잘 돌아감
    return 0;
}