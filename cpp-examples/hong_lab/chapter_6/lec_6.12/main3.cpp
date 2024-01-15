#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

    int fixedArray[] = {1,2,3,4,5};

    for (int i=0 ; i<( sizeof(fixedArray) / sizeof(int) ) ; i++)
    cout << fixedArray[i] << endl;


    //int * unfixedArray = new int[]{1,2,3,4,5}; // impossible. compile error!
    int *unfixedArray = new int[5]{1,2,3,4,5}; // possible. 
    delete[] unfixedArray;


    // Q. resize is possible??
    // A. Directly impossible but should take detour method.
    // how?  : Firstly, get bigger size another memory. And then, copy the original one to bigger one. Finally append newly allocated things.
    

    return 0;
}