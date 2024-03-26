#include <iostream>
#include "Cents.h"
using namespace std;

// 생성자 정의
Cents::Cents(int cents) {m_cents = cents;}

// getCents 함수 정의
int Cents::getCents() const {return m_cents;}

// > 연산자 정의
bool operator > (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents > c2.m_cents);
}
