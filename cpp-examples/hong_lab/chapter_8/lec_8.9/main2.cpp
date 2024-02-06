#include <iostream>

using namespace std;


class Another
{
public:
    int m_value=0;
    Another()
    {
        cout <<"------------------------------------"<<endl;
        cout <<"Constructor"<<endl;
    }

    Another(const Another& st_in)
    :m_value(st_in.m_value)
    {
        cout <<"------------------------------------"<<endl;
        cout <<"Copy Constructor"<<endl;
        //m_value=(st_in.m_value);
    }

    void setValue(int value)
    {
        m_value = value;
    }

    int getValue() const
    {
        return m_value;
    }

};

void print(Another anoth)
{
    cout << anoth.m_value << endl;
    cout << "In print(), address of input is : "<<&anoth << endl;
}

int main()
{


    const Another another1;
    //another1.setValue(3); // Compile error
    another1.getValue();
    cout <<"In main(), address of another1 is : "<< &another1 <<  endl;    
    print(another1);
    cout <<"------------------------------------"<<endl;

    const Another another2;
    //another1.setValue(3); // Compile error
    another2.getValue();

    cout <<"In main(), address of another2 is : "<< &another2 <<  endl;
    print(another2);
    cout <<"------------------------------------"<<endl;





    return 0;
}