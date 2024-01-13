#include <iostream>
#include <string>

using namespace std;


struct Person
{
   double height;
    float weight;
    int age ;
    string name ;

    void print()
    {
        cout << height << " " << weight << " " << age << " " << name << endl;
    }

};


struct Family
{
    Person me;
    Person mom;
    Person dad;
};

Person getYou()
{
    Person you{1.70,83.2,28,"Ryu Ryu"};
    you.print();
    return you;
}


/* 
void printPerson(Person person_to_print)
{
    cout << person_to_print.height << " " << person_to_print.weight << " " << person_to_print.age << " " << person_to_print.name << endl;
} 
*/



int main()
{


    Person me ;
 
    me.age = 20 ;
    me.name = "Jack Jack";
    me.height = 2.0;
    me.weight = 100.0;

    me.print(); // Initialization 1

    Person me2 = me ; // Initialization 2
    me2.print();

    Person me3(me) ; // Initialization 3
    me3.print();

    Person me4{me}; // Initialization 4
    me4.print();

    Person mom{1.8, 60.0f, 50, "Jane Jane"} ;
    Person dad ;

    Family doyoung ;
    doyoung.me.age = 27 ;
    doyoung.me.height = 173.0 ;
    doyoung.me.weight = 69.0f ;
    doyoung.me.name = "Kim";
    doyoung.me.print();

    getYou();

    return 0;
}