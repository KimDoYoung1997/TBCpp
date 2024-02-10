//Static member variable
#include <iostream>

using namespace std;

int generateID()
{
    static int s_id=0;
    return ++s_id ;
}



int main()
{
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;

    return 0;
}