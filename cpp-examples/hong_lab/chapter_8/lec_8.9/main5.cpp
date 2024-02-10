#include <iostream>

using namespace std;



class Something
{
public:

    Something()
    {
        cout <<"Im a basic constructor" << endl;
        cout <<"basic constructor, this address : " << this << endl;
    }

    Something(Something& sth)
    {
        cout <<"Im a Copy constructor" << endl;
        cout <<"Copy constuctor, this address : " << this << endl;
    }


    int m_value = 0;


    void setValue(int value)
    {
        m_value = value;
    }

    int getValue() const
    {
        return m_value;
    }
    
};


void print(Something st)
    {
        cout <<st.m_value << endl;

        cout<<"print, something copy address : " << &st << endl;
    }
void print2(const Something &st)
    {
        cout<<"print2, something copy address : " << &st << endl;
        st.getValue();
    }


int main()
{

    Something something;
    cout <<"main, something address : "<<&something << endl;
    print(something);
    print2(something);

    return 0;
}