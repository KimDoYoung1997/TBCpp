#include <iostream>

using namespace std;



int* allocateMemory(int length)
{

    return new int[length];


}



int main()
{


    // It is also dangerous. because memory allocation is proceeded in allocateMemory func but after that func is called
    // there is no way where to delete memory
    int * array = allocateMemory(1024);


    delete[] array ;




    return 0;
}