#include <iostream>

using namespace std;

class Something
{
private: 
    // Static member variable
    static int s_value;
    // Non-static member variable
    int m_value;

public:
    // Static member function to get the value of s_value
    static int getValue()
    {
        // Returns the static member variable
        return s_value;
    }

    // Non-static member function that can access both static and non-static members
    int temp()
    {
        // Accesses the static member variable via this pointer
        return this->s_value;
    }

};

// Initialization of static member variable
int Something::s_value=10;

int main()
{
    // Calling static member function without an instance
    cout << Something::getValue()<< endl;

    Something something;
    // Calling static member function through an instance
    cout << something.getValue() << endl;
    // Calling non-static member function
    cout << something.temp() << endl;

    // Class Member Function Pointer for non-static function
    int (Something::*fptr1)()=&Something::temp;
    // Calling non-static function via function pointer

    cout <<"fptr1() : " << (something.*fptr1)() << endl;
    
    // Function pointer for static member function
    int (*fptr2)() = &Something::getValue;
    // Calling static function via function pointer
    cout <<"fptr2() : " << fptr2() << endl;

    // Direct assignment of function to function pointer and calling it
    int (*fptr3)()= something.getValue;
    cout <<"fptr3() : "<< fptr3() << endl;

    //Compile error
    // int (*fptr4)() = something.temp;
    // cout <<"fptr4() : "<< fptr4() << endl;


    return 0;
}
