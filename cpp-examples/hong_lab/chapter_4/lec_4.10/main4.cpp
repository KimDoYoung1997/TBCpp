#include <iostream>
#include <string>

using namespace std;


struct Employee // expectation : 2 + 4 + 8 bytes = 14 bytes
{
    short       id  ; //2 bytes
    int         age ; //4 bytes
    double      wage; //8 bytes
    

};



int main()
{

    Employee emp1;
    cout << sizeof(Employee) << endl; // result : 16 bytes = 14 + 2 bytes // padding 
    return 0;
}