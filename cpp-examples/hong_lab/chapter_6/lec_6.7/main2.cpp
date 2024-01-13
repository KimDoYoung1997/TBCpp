#include <iostream>
#include <cstdint>

using namespace std;



int main()
{
    int x = 5;
    int *ptr_x=&x , *ptr_y=&x ;
    cout << typeid(ptr_x).name() << endl;


    int *ptr_z;
    cout << *ptr_z << endl;
    cout << (intptr_t)ptr_z << endl;

    return 0;
}