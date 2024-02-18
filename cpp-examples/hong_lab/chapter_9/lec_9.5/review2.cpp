#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0):m_cents(cents)
    {}

    Cents(Cents &copy):m_cents(copy.m_cents)
    {
        cout <<"copy constructor" << endl;
    }

    void showCents()
    {
        cout << "m_cents : " << m_cents << endl;
    }

    const int getCents() const
    {
        return m_cents;
    }

    Cents operator+ (const Cents cents2)
    {
        return Cents(this->m_cents+cents2.m_cents);
        // Cents temp (this->m_cents+cents2.m_cents);
        // return temp;
    }

};


int main()
{
    Cents cents1(10);
    Cents cents2(7);


    Cents cents3 = cents1.operator+(cents2);
    cents3.showCents();

    
    return 0;
}