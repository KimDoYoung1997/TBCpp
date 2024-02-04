//Delegating Constructors

#include <iostream>
#include <string>

using namespace std;


class Student
{
private:
    int m_id;
    string m_name;

public:

    //Delegating Constructors
    Student(const string& name_in)
        :m_name{name_in}, m_id(0)
    {}


    Student(const int& id_in, const string& name_in)
        :m_name(name_in) , m_id(id_in)
    {}

    void print()
    {
        cout << m_id <<" " << m_name << endl;
    }

};




int main()
{
    Student st1(0,"Jack Jack");
    st1.print();

    Student st2{"Dash"};
    st2.print();

    return 0;
}