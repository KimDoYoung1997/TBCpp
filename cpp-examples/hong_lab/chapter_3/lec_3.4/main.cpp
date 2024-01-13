#include <iostream>

int main()
{
    using namespace std;



    sizeof(float); //4 bytes 

    float b ;
    sizeof(b); // 4 

    cout << sizeof(b) << endl; // size of is not a function but an operator. 

    cout << sizeof b << endl; // size of is not a function but an operator. 

    return 0;
}