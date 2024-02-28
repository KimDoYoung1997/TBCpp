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
    Fraction(int num=0, int dem=1):m_numerator(num),m_denominator(dem)
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
    doSomething(7);                 // 심지어 이것도 컴파일 잘 됨, 결과 : 7/1 이는 Converting constructor(변환 생성자)에 의한 묵시적 형변환이 있었기 때문임
    return 0;
}