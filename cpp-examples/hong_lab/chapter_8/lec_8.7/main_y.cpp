//this pointer and chaining member functions
#include <iostream>
#include <cstring>
using namespace std;


class Person
{
private:
    char *name;
    int age;
public:
    Person(char* myname, int myage)
    {
        int len = strlen(myname)+1;
        name = new char[len]; //dynamic allocation
        strcpy(name,myname);
        age = myage;

        cout <<"Constructor" << endl;
        cout << name <<" " << age << " " << endl;
    }

    Person()
    {
        name=nullptr;
        age=0;
        cout <<"called Person"<< endl;
    }

    void SetPersonInfo(char *myname, int myage)
    {
        name=myname;
        age=myage;
    }

    void ShowPersonInfo()
    {
        cout <<"-----------------------------"<<endl;
        cout <<"name : "<<name<<" ";
        cout <<"age : "<<age <<endl;
        cout <<"-----------------------------"<<endl;

    }

    ~Person()
    {
        delete[] name;
        cout <<"called destructor!" << endl;
    }

};


int main()
{
    //Person("JackJack",28);


    Person parr[3];
    cout << sizeof(parr) << endl;

    char namestr[100];
    char * strptr;
    int age;
    int len;

    for(int i=0;i<3;i++)
    {
        cout <<"name : ";
        cin >>namestr;
        cout <<"age : ";
        cin >> age;
        len = strlen(namestr)+1;
        strptr = new char[len];
        strcpy(strptr,namestr);
        parr[i].SetPersonInfo(strptr, age);

    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();


    return 0;
}