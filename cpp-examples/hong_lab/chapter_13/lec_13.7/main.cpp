#include <iostream>
using namespace std;

template<typename T>
class A 
{
private:
    T m_value;
public:
    A(const T & input):m_value(input)
    {}

    void print()
    {
        cout << m_value << endl;
    }
};


template<typename T>
class A<T*> 
{
private:
    T* m_value;
public:
    A( T* input):m_value(input)
    {}

    void print()
    {
        cout <<"hi" << endl;
        cout << m_value << endl;
    }
};


int main()
{
    A<int> a_int(123);
    a_int.print();

    int temp = 456;
    A<int*> a_int_ptr(&temp);
    cout << &temp << endl;
    a_int_ptr.print();

    cout <<"--------------------" << endl;

    double temp_d(3.14);
    A<double*> a_double_ptr(&temp_d);
    cout <<&temp_d << endl;
    a_double_ptr.print();

    return 0;
}