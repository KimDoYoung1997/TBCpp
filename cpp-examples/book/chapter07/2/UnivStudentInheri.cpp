#include <iostream>
#include <cstring>
using namespace std;


class Person
{
private:
    int age;
    char name[50];
public:
    Person(const char* myname,int myage):age(myage)
    {
        strcpy(name,myname);
        cout <<"Person 생성자 호출"<<endl;
    }

    void WhatYourName() const
    {
        cout<<"My name is "<<name<<endl;
    }

    void HowOldAreYou() const
    {
        cout<<"My age is "<<age<<endl;
    }
 
    
};


class UnivStudent : public Person
{
private:   
    char major[50];
public:
    UnivStudent(const char* myname,int myage,const char* my_major):Person(myname,myage)
    {
        strcpy(major,my_major);
        cout << "UnivStudent 생성자 호출" << endl;
    }
    void WhoAreYou()
    {
        WhatYourName();
        HowOldAreYou();
        cout<<"My major is"<<major<<endl;
    }
};

int main()
{
    UnivStudent ustd1("Lee",22,"Computer eng");
    ustd1.WhoAreYou();
    return 0;
}