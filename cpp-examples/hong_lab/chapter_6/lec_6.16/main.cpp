#include <iostream>

using namespace std;

struct Person
{
    int age;
    double weight; 

};




int main()
{

    Person person;

    person.age = 5;
    person.weight = 30.0;


    Person &ref = person;
    cout <<"Ref : "<< ref.age << endl;
    cout <<"Ref : "<< ref.weight << endl;


    Person *ptr = &person;
    cout <<"Pointer (*ptr).age : "<< (*ptr).age << endl;
    cout <<"Pointer (*ptr).weight : "<< (*ptr).weight << endl;
    cout <<"Pointer ptr->age : "<< ptr->weight << endl;
    cout <<"Pointer ptr->weight : "<< ptr->weight << endl;


    Person &ref2 = *ptr;
    cout <<"ref2.age : "<< ref2.age << endl;
    cout <<"ref2.weight : "<< ref2.weight << endl;

    return 0;
}