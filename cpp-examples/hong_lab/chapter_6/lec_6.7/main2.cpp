#include <iostream>
#include <cstdint>

using namespace std;


int main()
{
    int x = 5;
    
    // Be careful when you declare multiple pointer variables at the same time

    // The reason why you have to know or declare the point type, such as int* , double*.. is that when you de-reference the pointer, 
    // you should need where is the end memory point of variable
    int *ptr_x=&x , *ptr_y=&x ;

    // by using typeid().name, you can know the variable type
    cout << typeid(ptr_x).name() << endl; //Pi : 'P'ointer to 'i'd


    int *ptr_z =&x;
    cout << *ptr_z << endl;
    cout << *(ptr_z+10) << endl; // when you see the screen, there is trash value

    cout << (intptr_t)ptr_z << endl;


    // By using typedef, you can also declare pointer variable like below.
    typedef int* pint;
    pint ptr_r=&x;
    cout << ptr_r << endl;

    // double d = 1.0;
    // int *q = &d ; // when you try to compile with this, error occured : "error: cannot convert ‘double*’ to ‘int*’ in initialization"

    //int i = 0;
    //double *ptr_d = &i ; //when you try to compile with this, error occured :  "error: cannot convert ‘int*’ to ‘double*’ in initialization"
    
    
    return 0;
}