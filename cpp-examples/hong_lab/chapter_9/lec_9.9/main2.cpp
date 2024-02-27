// 복사 생성자, 복사 초기화 반환값 최적화, RVO(Return Value Optimization)
// https://chat.openai.com/share/02d42bc2-02b7-4c16-ae90-65691048406c
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
    static int num;
    Fraction(int num=0, int den=1):m_numerator(num),m_denominator(den)
    {
        assert(den!=0); // 분모가 0 이면 의도적으로 컴파일 에러 생성하기
    }

    Fraction(Fraction& copy):m_numerator(copy.m_numerator),m_denominator(copy.m_denominator)
    {
        cout <<"Copy constuctor called " <<++num << endl;
    }

    friend std::ostream& operator << (std::ostream &out, const Fraction& frac)
    {
        out << frac.m_numerator << " / " << frac.m_denominator ;
        return out;
    }

};
int Fraction::num=0;

Fraction doSomething()
{
    Fraction temp(1,2);
    cout <<&temp << endl;
    return temp;
}

int main()
{
    Fraction result = doSomething(); // 이번에도 복사 생성자가 호출되지 않음. 컴파일러가 자동으로 막아준듯.
    cout << result << endl;  // 0x7ffe7fefcef0
    cout << &result << endl; // 0x7ffe7fefcef0  서로 주소가 같음. Return Value Optimization이 된거라고 해석하면 될듯
    return 0;
}