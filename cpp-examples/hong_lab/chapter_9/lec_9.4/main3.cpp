#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <algorithm>
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

    vector<Cents> arr(20);
    for (unsigned i=0 ; i<20 ; i++)
    {
        arr[i].getCents() = i ;
    } 

    std::random_shuffle(begin(arr),end(arr));

    for (auto element : arr )
    {
        cout << element<<" " ;
    }cout << endl;

    cout << "------------- sorting process finished ------------------" <<endl;
    std::sort(begin(arr),end(arr));
    for (auto element : arr )
    {
        cout << element<<" " ;
    }cout << endl;
 



    cout << std::boolalpha;


    return 0;
}