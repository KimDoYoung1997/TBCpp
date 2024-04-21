#include <iostream>
using namespace std;

template<typename T>
class A 
{
private:
    T m_value;
public:
    A(const T &input):m_value(input)
    {
    }

    template<typename TT>
    void doSomething(const TT& input)
    {
        cout << typeid(T).name() <<" " << typeid(TT).name() << endl;
        cout <<(TT)m_value << endl;
    }
    void print()
    {
        cout << m_value << endl;
    }

};

int main()
{

    A<int> a_int(16);
    a_int.print();
    a_int.doSomething<double>(123.4);
    a_int.doSomething('a');


    return 0;
}

