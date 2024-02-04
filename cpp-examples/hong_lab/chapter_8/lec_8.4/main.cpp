// Member Initializer List

#include <iostream>

using namespace std;


class Another
{

private:
    int m_b;

public:
    Another(const int& m_b_in)
        : m_b{m_b_in}
    {
        //m_b = m_b_in;
    }

};


class Something
{

private:
    int m_i;
    double m_d;
    char m_c;
    int m_arr[5];
    Another m_b;

public:
    Something()
        //Member Initialization list
        // :m_i(1), m_d(3.14), m_c('a')
        :m_i{1}, m_d{3.14}, m_c('a'), m_arr{1,2,3,4,5},m_b(m_i-1)

    {
        // m_i = 1;
        // m_d = 3.14;
        // m_c = 'a';
    }   

    // Something()
    // {
    //     m_i = 1;
    //     m_d = 3.14;
    //     m_c = 'a';
    // }   

    void print()
    {
        
        cout << m_i <<" " << m_d << " " <<m_c << endl;
        for (auto &element : m_arr)
            cout << element << " " ;
        cout << endl;

    }

};







int main()
{
    Something sth;
    sth.print();

    return 0;
}