//산술 연산자 오버로딩 직전 불편함 느끼기

#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    // Cents()
    // :m_cents(0)
    // {}

    Cents(int cents=0){m_cents=cents;}

    int getCents() const 
    {
        cout <<"Int getCents() const"<< endl;

        return m_cents;
    }
    int& getCents() 
    {
        cout <<"Int& getCents"<< endl;


        return m_cents;
    }
};

Cents add(const Cents &cent1, const Cents &cent2)
{
    //cout << static_cast<int>(cent1.getCents()) + static_cast<int>(cent2.getCents())  ;

    //Cents sum;
    // sum.getCents() = cent1.getCents() + cent2.getCents();

    return Cents (cent1.getCents() + cent2.getCents());
}



int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents sum;
    sum=add(cents1,cents2);

    cout << sum.getCents() << endl;



    return 0;
}