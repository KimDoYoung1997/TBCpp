#include <ios>
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

    int getCents() const {return m_cents;} // for Anonymous object, such as " Cents(3) ""
    int & getCents(){return m_cents;}

    friend std::ostream& operator << (std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents;
        return out;
    }

    friend bool operator  == (const Cents&cl, const Cents c2);
    friend bool operator  != (const Cents&c1, const Cents c2);

    // bool operator != (const Cents &c2) const
    // {
    //     return  (this->m_cents !=c2.m_cents) ;
    // } 


    // bool operator != (const Cents &c1, const Cents &c2) const
    // {
    //     return  (c1.m_cents !=c2.m_cents) ;
    // } 



    friend bool operator !(const Cents& cents);
    friend bool operator >(const Cents&c1, const Cents&c2);
    friend bool operator <(const Cents&c1, const Cents&c2);

    friend bool operator >=(const Cents&c1, const Cents&c2);
    friend bool operator <=(const Cents&c1, const Cents&c2);



};


bool operator  == (const Cents&c1, const Cents c2)
{
    return (c1.m_cents==c2.m_cents);
}


bool operator  != (const Cents&c1, const Cents c2)
{
    return (c1.m_cents!=c2.m_cents);
}



bool operator !(const Cents& cents)
{
     return (cents.m_cents ==0) ? true : false;
}

bool operator >(const Cents&c1 , const Cents&c2)
{
    return (c1.m_cents > c2.m_cents);
}

bool operator <(const Cents&c1 , const Cents&c2)
{
    return (c1.m_cents < c2.m_cents);
}

bool operator >=(const Cents&c1 , const Cents&c2)
{
    return (c1.m_cents >= c2.m_cents);
}


int main()
{



    Cents cents1(0);
    Cents cents2(0);
    Cents cents3(3);

    cout << (cents1==cents2) << endl;
    cout << (cents2==cents3) << endl;
    cout << (cents1!=cents3) << endl;
    cout << !(cents1==cents2) << endl;
    cout << (cents1>=cents2) << endl;
    cout << (cents1>cents2) << endl;




    // if (cents1.getCents()==cents2.getCents())
    // {
    //     cout <<"Equal" << endl;
    // }
    

/*

    int a=3, b=3;
    if (a==b)
    {
        cout <<"Equal" << endl;
    }
*/


/*
    if (cents1==cents2)
    {
        cout <<"Equal" << endl;
    }
*/







    cout << std::boolalpha;


    return 0;
}