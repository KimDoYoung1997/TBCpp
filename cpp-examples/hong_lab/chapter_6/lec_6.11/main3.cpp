//Dynamic Memory Allocation
#include <iostream>
#include <ostream>

using namespace std;

int main()
{
    int *ptr = new(std::nothrow) int{7};
    int *ptr2 = ptr;

    cout << ptr << endl; // 0x55cc48bbdeb0
    cout << ptr2 << endl; // 0x55cc48bbdeb0
    cout << *ptr2 << endl; // 7

    delete ptr;

    cout << ptr2 << endl; // 0x55cc48bbdeb0
    cout << *ptr2 << endl; // 1556384701
    ptr = nullptr;
    cout << "delete ptr" << endl; 

    if (ptr !=nullptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }

    cout << ptr2 << endl; // 0x55cc48bbdeb0
    cout << *ptr2 << endl; // 1556384701

    return 0;
}