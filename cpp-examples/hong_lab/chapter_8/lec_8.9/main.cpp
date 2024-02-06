#include <iostream>

using namespace std;

class Something
{
public:
    int m_value=0;
    void setValue(int value)
    {
        m_value = value;
    }

    int getValue()
    {
        return m_value;
    }

};

class Another
{
public:
    int m_value=0;
    void setValue(int value)
    {
        m_value = value;
    }

    int getValue() const
    {
        return m_value;
    }

};

// class Theother
// {
// public:
//     int m_value=0;
//     void setValue(int value) 
//     {
//         m_value = value;
//     }

//     int getValue() const
//     {
//         return m_value;
//     }

// };

int main()
{

    //const int i=0;
    //i=1 ; // Compile error

    Something something;
    something.setValue(3);
    cout << something.getValue() << endl;

    const Something something2;
    //something2.setValue(3); // Compile error
    //cout << something2.getValue() << endl;

    Another another1;
    another1.setValue(5);
    cout << another1.getValue() << endl;

    const Another another2;
    //another2.setValue(5);
    cout << another2.getValue() << endl;

    // const Theother theother1;
    // //theother1.setValue(5);
    // cout << theother1.getValue() << endl;



    return 0;
}