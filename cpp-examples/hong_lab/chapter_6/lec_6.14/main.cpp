#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

//pointer
    // int value =5 ;
    // int * ptr = nullptr;
    // ptr = &value;


    int value = 5;
    int &ref = value;


    cout <<ref << endl;
    
    cout <<"type of value is : "<<typeid(value).name() << endl; // int
    cout <<"type of ref is : "<<typeid(ref).name() << endl; // int
    ref = 10; // Simillar with *ptr=10

    cout << value<< " " <<(uintptr_t)&value <<" "<<ref <<" "<< (uintptr_t)&ref  <<endl;


    int *ptr = nullptr;
    ptr = &value;


    cout << (uintptr_t)ptr << endl;
    cout << (uintptr_t)(&ptr) << endl;






    return 0;
}