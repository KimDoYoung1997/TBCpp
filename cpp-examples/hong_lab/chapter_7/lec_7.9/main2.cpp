#include <iostream>

using namespace std;

int func()
{
    cout << "Im in func()" << endl;
    return 5;
}

int goo()
{
    return 10;
}


int main()
{


    //Address of function 'func' will always evaluate to 'true'
    //With my compiler, I can't directly get the address of function
    cout << func << endl;
    
    //By using these methods(trick) below, I can get the address of function
    printf("address of func() is :  %p \n", func);
    cout <<"address of func() is : "<< reinterpret_cast<void*>(func) << endl;

    int (*fcnptr)() ;

    cout <<"Not-initialized address of func() is : "<< reinterpret_cast<void*>(fcnptr) << endl;

    fcnptr = func;

    cout <<"fcnptr pointer initialization is done! : "<< reinterpret_cast<void*>(fcnptr)<<endl;

    cout <<"fcnptr() : " << fcnptr() << endl; 
    cout <<"func() : " << func() << endl; 

    fcnptr = goo;

    cout <<"fcnptr pointer is re-initialized with goo() : "<< reinterpret_cast<void*>(fcnptr)<<endl;


    return 0;
}