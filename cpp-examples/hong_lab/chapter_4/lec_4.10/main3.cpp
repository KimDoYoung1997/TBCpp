#include <iostream>
#include <string>

using namespace std;


struct Person
{
   double height=3.0;
    float weight = 200.0;
    int age = 100;
    string name = "Mr.Incredible";
    
    void print()
    {
        cout << height << " " << weight << " " << age << " " << name << endl;
    }

};



int main()
{


    Person me ;
 
    me.age = 20 ;
    me.name = "Jack Jack";
    me.height = 2.0;
    me.weight = 78.0;
    me.print();

    Person me2;
    me2.print();

    return 0;
}