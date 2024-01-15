#include <cstdint>
#include <iostream>

using namespace std;


void printElements(int (&ref)[5])
{
    cout << "In printElements : " <<(uintptr_t)ref<< endl;

}


int main()
{

    const int length = 5;
    int arr[length] = {1,2,3,4,5};

    int (&ref)[length] = arr; 
    cout << (uintptr_t)arr << endl;
    cout << (uintptr_t)ref << endl;

    printElements(arr);


    return 0;
}