#include <iostream>

using namespace std;

int func(int x)
{
    cout << "Im in func(int x)" << endl;
    return 5;
}

int goo()
{
    return 10;
}

int goo2(int x)
{
    return 20;
}


int main()
{


    //Address of function 'func' will always evaluate to 'true'
    //With my compiler, I can't directly get the address of function
    cout << func << endl;
    
    //By using these methods(trick) below, I can get the address of function
    printf("address of func(int x) is :  %p \n", func);
    cout <<"address of func(int x) is : "<< reinterpret_cast<void*>(func) << endl;

    int (*fcnptr)(int) ;

    cout <<"Not-initialized address of func(int x) is : "<< reinterpret_cast<void*>(fcnptr) << endl;

    fcnptr = func;

    cout <<"fcnptr pointer initialization is done! : "<< reinterpret_cast<void*>(fcnptr)<<endl;

    cout <<"fcnptr(4) : " << fcnptr(4) << endl; 
    cout <<"func(4) : " << func(4) << endl; 

    fcnptr = goo2;

    cout <<"fcnptr pointer is re-initialized with goo2(int x) : "<< reinterpret_cast<void*>(fcnptr)<<endl;


    return 0;
}