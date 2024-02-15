#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(const char* myname, int myage)
    {
        cout <<"Default Constructor"<<endl;
        int len=strlen(myname)+1; //12 +1
        name = new char[len];
        strcpy(name,myname);
        age=myage;
    }

    Person(Person &people)
    {
        cout <<"Copy Constructor" << endl;
        age=people.age;
        name = new char[strlen(people.name)+1];
        strcpy(name,people.name);

    }

    ~Person()
    {
        static int num_destruct ;
        if (name !=nullptr)
        {
            num_destruct++;
            delete[] name;
            name = nullptr;
            cout <<"Called Destructor "<<num_destruct<<  endl;
        }
        else 
        {
            cout <<"Im null" << endl;
        }

    }

};


int main()
{
    Person man1("Kim Do Young",28); //len : 12 without null
    //Person man2("Park ji sung",38);
    Person man3(man1);
    return 0;
}