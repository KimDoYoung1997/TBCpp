//Dynamic Memory Allocation
#include <iostream>

using namespace std;

int main()
{
    int *ptr = new(std::nothrow) int{7};


    if (ptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }
    
    else //if nullptr
    {
        cout << "could not allocate memory" << endl;
    }

    delete ptr;
    ptr = nullptr;
    cout << "delete ptr" << endl;


    return 0;
}