#include <iostream>

using namespace std;

int func()
{
    return 5;
}


int main()
{


    //Address of function 'func' will always evaluate to 'true'
    //With my compiler, I can't directly get the address of function
    cout << func << endl;
    
    //By using these methods(trick) below, I can get the address of function
    printf("%p \n", func);
    cout << reinterpret_cast<void*>(func) << endl;

    return 0;
}