#include <iostream>
#include <string>
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
        cout <<"string& getValue()"<<endl;

        return m_value;
    }

};


int main()
{

    Something something;
    cout <<something.getValue()<< endl;

    const Something something2;
    cout <<something2.getValue()<<endl;

    // string a ="sexy";
    // const string& str= a;
    return 0;
}