#include <iostream>

using namespace std;

class Digit
{
private:
    int m_digit;
public:
    Digit(int digit=0):m_digit(digit)
    {}


    friend Digit& operator++(Digit& ref)
    {
        ref.m_digit +=1; 
        return ref;
    }

    friend Digit operator++(Digit& ref,int)
    {
        Digit temp(ref);
        ref.m_digit+=1;
        return temp;
    }

    Digit& operator --()
    {
        this->m_digit -=1;
        return *this;
    }

    Digit operator-- (int)
    {
        Digit temp(*this);
        m_digit -=1;
        return temp;
    }

    friend std::ostream &operator <<(std::ostream &out,const Digit &d)
    {
        out<<d.m_digit;
        return out;
    }

};

int main()
{
    Digit digit1(3);
    cout << digit1<< endl;
    cout <<++digit1<<endl;
    cout << --digit1<<endl;
    cout << digit1++ << endl;
    cout << digit1 << endl;
    cout << digit1-- << endl;
    cout << digit1 << endl;
    return 0;
}