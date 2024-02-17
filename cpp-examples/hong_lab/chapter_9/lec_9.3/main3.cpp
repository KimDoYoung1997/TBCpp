#include <iostream>
#include <ostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents=0):m_cents(cents)
    {}

    int getCents() const
    {
        return m_cents;
    }

    int &getCents() 
    {
        return m_cents;
    }

    friend std::ostream& operator << (std::ostream &out, const Cents &cents);


    // Cents operator -() 
    // {
    //     this->m_cents = -m_cents;
    //     return  *this;
    // }

    Cents operator -() const
    {
        return Cents(-m_cents); // Anonymous object
    }

    bool operator !() const
    {
        //!Cents() -> true
        return (m_cents ==0) ? true : false;
    }

};



std::ostream& operator <<(std::ostream &out, const Cents &cents)
{
    out << cents.m_cents ;
    return out;
}







int main()
{
    Cents cents1(6);
    Cents cents2(0);
    // cout << -cents1 << endl;
    // cout << cents1 << endl; 
    // cout << Cents(-10) << endl; // Anonymous object 
    // cout << -Cents(-10) << endl;

    auto temp1 = !cents1 ; //false
    auto temp2 = !cents2 ; //true

    cout << !cents1 << " " << !cents2 << endl;

    return 0;
}