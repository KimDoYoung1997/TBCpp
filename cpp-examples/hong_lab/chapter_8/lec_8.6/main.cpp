#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(const int& id_in)
    : m_id(id_in)
    {
        //m_id = id_in;
        cout << "Constructor " << m_id << endl; // Constructor 3

    }

    ~Simple()
    {
        cout << "Destructor " << m_id << endl; //Destructor 3
    }



};


int main()
{

    Simple s1(3);
    Simple s2(4);



    return 0;
}