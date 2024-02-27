// 복사 생성자, 복사 초기화 반환값 최적화, RVO(Return Value Optimization)
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



int main()
{
    Fraction frac(3,5);
    cout << frac << endl;

    Fraction frac_copy(frac);
    cout << frac_copy << endl;

    Fraction frac_copy2 = frac;

    Fraction frac_copy3(Fraction(3,5)); // 이 경우에는 복사생성자가 호출이 안 된다. 컴파일러가 알아서 복사생성자 호출을 막아줬다.

    return 0;
}