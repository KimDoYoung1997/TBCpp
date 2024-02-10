#include <iostream>

using namespace std;

class Something
{
public:
    string m_value = "default";

    const string& getValue() const
    {
        cout <<"const string& getValue() const"<<endl;
        return m_value;
    }

    string& getValue() 
    {
        cout<<"string& getValue() " << endl;
        return m_value;
    }

};


int main()
{

    Something something ;
    cout <<something.getValue()<<endl;
    something.getValue() = 10;
    // cout <<&something.m_value<<endl;
    // cout <<&something.getValue()<<endl;

    const Something something2;
    cout <<something2.getValue()<<endl;
    //something2.getValue() = 10;

    return 0;
}