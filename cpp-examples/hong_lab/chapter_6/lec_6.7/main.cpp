#include <iostream>
#include <cstdint>

using namespace std;


// for local variable, it uses a "stack" memory. On the other hand, dynamic allocative memory, it uses "heap" memory
// CPU doesn't use all part of data size to use the part of huge size  memory, but only to use address of data which is necessary 

//pointer is a variable that holds the memory address of another variable.
int main()
{
    int x = 5;
    cout << "value of x : "<< x << endl;
    cout <<"address of x : " << (long)&x << endl;


    // de-reference operator (*)
    cout <<*(&x) << endl;


    return 0;
}