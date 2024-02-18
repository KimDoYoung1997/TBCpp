#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0):m_cents(cents)
    {}

    Cents(Cents & copy): m_cents(copy.m_cents)
    {
        static int count;
        cout <<"copy constructor " << ++count << endl;
    }
    void showCents()
    {
        cout <<"m_cents: " << m_cents << endl;
    }


    friend Cents operator+(const Cents cents1 , const Cents cents2);

};


Cents operator+(const Cents cents1, const Cents cents2)
{
    Cents temp(cents1.m_cents+cents2.m_cents);
    return temp;
    
    // return Cents(cents1.m_cents+cents2.m_cents);

}

int main()
{
    Cents cents1(7), cents2(11);

    Cents cents3= cents1+cents2;
    cents3.showCents();
    return 0;
}