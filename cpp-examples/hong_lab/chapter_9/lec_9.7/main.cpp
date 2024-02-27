#include <iostream>
#include <ostream>
using namespace std;

class Accumulator
{
private:
    int m_counter=0;
public:
    int operator()(int i)
    {
        return (m_counter+=i);
    }
    friend std::ostream& operator << (std::ostream &out,Accumulator &acc)
    {
        out<< acc.m_counter;
        return out;
    }
};

int main()
{
    Accumulator acc;
    cout << acc << endl;
    cout << acc(3) << endl; 
    cout << acc << endl;
    cout << acc(10) << endl;
    cout << acc << endl;
    return 0;
}


