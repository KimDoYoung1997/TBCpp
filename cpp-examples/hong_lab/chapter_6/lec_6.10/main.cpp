#include <cstdint>
#include <iostream>

using namespace std;



const char* getName()
{
    cout <<"Im in getName" << endl;
    cout <<"Im out getName" << endl;

    return "Jack jack";

}


int main()
{

    //char name[] = "Jack jack";
    //cout << name << endl;


    //char *name = "Jack jack"; // Causing error
    const char *name = "Jack jack"; // By using const, keep error from causing
    const char *name2 = "Jack jack"; // By using const, keep error from causing
    const char *name3 = "Jack jack2"; // By using const, keep error from causing


    cout << (uintptr_t)name << endl;  //94666991112196

    cout << (uintptr_t)name2 << endl; //94666991112196

    cout << (uintptr_t)name3 << endl; //94666991112206


    const char *name4 = getName(); // Causing error

    cout << (uintptr_t)name4 << endl; //94666991112196

    return 0;
}