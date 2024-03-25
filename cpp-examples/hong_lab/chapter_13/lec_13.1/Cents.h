#pragma once

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents);

    int getCents() const ;


//추가 1
friend std::ostream& operator << (std::ostream& out, const Cents& cents)
{
     out << cents.m_cents << "cents";
     return out;
}

//추가 2	
friend bool operator > (const Cents& c1, const Cents& c2);
// {
// 	return (c1.m_cents > c2.m_cents);
// }

};

