#pragma once

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents);

    // getCents함수 선언
    int getCents() const ;


//추가 1
// << 연산자 선언 및 정의
friend std::ostream& operator << (std::ostream& out, const Cents& cents)
{
     out << cents.m_cents << "cents";
     return out;
}

//추가 2	
// > 연산자 선언
friend bool operator > (const Cents& c1, const Cents& c2);
// {
// 	return (c1.m_cents > c2.m_cents);
// }

};

