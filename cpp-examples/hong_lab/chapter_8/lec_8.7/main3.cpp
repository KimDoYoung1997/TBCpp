#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;


public:
    Simple(int id)
    {
        //setId(id);
        (*this).setId(id);
        
        cout <<"instance address : "<< this << endl;
    }

    void setId(int id)
    {
        //m_id = id;
        (*this).m_id = id;
    }

    int getId()
    {
        return (*this).m_id;
    }

};




int main()
{
    Simple s1(1) , s2(2);

    cout<< "address of s1 : "<< &s1 << endl;
    cout<< "address of s2 : "<< &s2 << endl;
    return 0;
}