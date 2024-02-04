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
        cout << "hi" << endl;
    }

};


class Something
{

private:
    int m_i = 100;
    double m_d = 100.0;
    char m_c ='F';
    int m_arr[5]{100,200,300,400,500};
    Another m_b{1024};

public:
    Something()
        //Member Initialization list
        // :m_i(1), m_d(3.14), m_c('a')
        :m_i{1}, m_d{3.14}, m_c('a'), m_arr{1,2,3,4,5},m_b(m_i-1)

    {
         m_i *= 3;
         m_d *= 3;
         m_c += 1;
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