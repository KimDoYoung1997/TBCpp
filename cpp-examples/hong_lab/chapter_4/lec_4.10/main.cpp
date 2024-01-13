#include <iostream>
#include <string>

using namespace std;




/* 
void printPerson(double height , float weight , int age , string name)
{
    cout << height << endl;
}

 */

struct Sex
{
    string male ;
    string female ;
};

struct Person
{
   double height;
    float weight;
    int age ;
    string name ;
    Sex sex;
 
};

void printPerson(Person person_to_print)
{
    cout << person_to_print.height << " " << person_to_print.weight << " " << person_to_print.age << " " << person_to_print.name <<" " << person_to_print.sex.male << endl;
}



int main()
{
    //human description
/* 
    double height;
    float weight;
    int age ;
    string name ;
    
 */

    Person me ;
 
    me.age = 20 ;
    me.name = "Jack Jack";
    me.height = 2.0;
    me.weight = 100.0;
    me.sex.male = "male";

    Person mom{1.8, 60.0f, 50, "Jane Jane"} ;
    Person dad ;

    printPerson(me);


    return 0;
}