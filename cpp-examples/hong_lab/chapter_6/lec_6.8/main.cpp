#include <cstddef>
#include <iostream>

using namespace std;



void doSomething(double *ptr)
{
    cout << "-------------doSomething func() in --------------" << endl;
    cout << (long)ptr << endl;

    if (ptr !=nullptr)
    {
     cout <<"Well come to asshole : " <<"*ptr : " << (long)*ptr<< endl;
        // do something useful
    }

    else 
    {
        cout << "Im in NULL" << endl;
        // cout <<"Well come to NULL : " << "*ptr : " << *ptr << endl;  // because ptr is null, when you execute this line, error occured!
        // do nothing with ptr 
    }


    cout << "-------------doSomething func() out --------------" << endl;

}

int main()
{
    //double *ptr = 0; // c-style pointer initialize
    //double *ptr = NULL ; // c-style pointer initialize
    //double *ptr =  nullptr; // modern C++
    double *ptr{nullptr}; // modern C++
    double *ptr_uninitialized; // Uninitialized
    
    double d = 0.0;
    double *ptr_initialized = &d;
    doSomething(ptr);
    doSomething(ptr_uninitialized);
    doSomething(ptr_initialized);
    
    // std::nullptr_t nptr; //declare "nptr" as null ptr type 
    cout << "value of ptf : " << ptr << endl;
    cout << "address of pointer variable in main() : " << (long)&ptr << endl;

    return 0;
}