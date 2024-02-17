//단항 연산자 오버로딩을 friend로 하기.

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

    friend int operator -(const Cents &cents);


};



std::ostream& operator <<(std::ostream &out, const Cents &cents)
{
    out << cents.m_cents ;
    return out;
}

int operator -(const Cents &cents)
{

    return -cents.getCents();
}






int main()
{
    Cents cents1(6);
    Cents cents2(0);
    cout << -cents1 << endl;
    cout << cents1 << endl; 
    cout << Cents(-10) << endl; // Anonymous object 
    cout << -(Cents(-10)) << endl;




    return 0;
}