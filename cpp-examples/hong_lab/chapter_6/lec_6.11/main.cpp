//Dynamic Memory Allocation
#include <iostream>

using namespace std;

int main()
{

    //int array[1000000000000000000000000]; // stack
    new int;
    cout << typeid((new int)).name() << endl;

    int *ptr = new int{7};
    cout << typeid((ptr)).name() << endl;
    cout << ptr << endl;
    cout <<*ptr << endl;

    delete ptr;
    cout << "After delete" << endl;
    cout << ptr << endl;
    cout <<*ptr << endl;

    ptr = 0; // ptr = NULL  , ptr = nullptr
    cout << "add null" << endl;

    if (ptr!= nullptr)
    {   
        cout << ptr << endl;
        cout <<*ptr << endl;
    }

    
    return 0;
}