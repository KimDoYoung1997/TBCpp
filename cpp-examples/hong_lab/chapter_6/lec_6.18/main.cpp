#include <cstdint>
#include <iostream>

using namespace std;


// void pointer, generic pointer

int main()
{
    int i = 5;
    float f = 3.0;
    char c = 'a';

    void *ptr = nullptr;

    cout<<ptr << endl;
    

    if (ptr !=nullptr)
        {
            cout << *(int*)ptr << endl;
            cout << (uintptr_t)ptr << endl;

            //cout << *ptr << endl; // compile error

        }
    else if (ptr == nullptr)
        {
            cout << "Im NULL" << endl;
        }



    cout << "----------------------------------------------------" << endl;
    ptr = &i;

    if (ptr !=nullptr)
        {
            cout << *(int*)ptr << endl;
            cout << (int*)ptr << endl;
            cout << (double*)ptr+1 << endl;
            cout << (int*)ptr+2 << endl;
            cout << *static_cast<int*>(ptr) << endl;

            //cout << *ptr << endl; // compile error

        }
    else if (ptr == nullptr)
        {
            cout << "Im NULL" << endl;
        }



    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;


    int a = 4;
    int *ptr_a = & a ;

    cout << ptr_a << endl; 
    cout << ptr_a+1 << endl; 


    return 0;
}