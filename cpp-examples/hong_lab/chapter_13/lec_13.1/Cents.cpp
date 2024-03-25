#include <iostream>
#include "Cents.h"
using namespace std;


Cents::Cents(int cents) {m_cents = cents;}

int Cents::getCents() const {return m_cents;}

bool operator > (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents > c2.m_cents);
}
