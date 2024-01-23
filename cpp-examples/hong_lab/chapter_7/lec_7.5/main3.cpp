#include <cstdint>
#include <iostream>

using namespace std;



int& getValue(int x)
{

    int value = x*2;
    int &ref = value; 

    cout << (uintptr_t)&value <<" " << (uintptr_t)&ref << endl; //  140732915264668 140732915264668

    ref = ref+5;

    return ref;
}



int main()
{

    int value =getValue(3); // int& temp = ref

    cout << (uintptr_t)&value << endl;  //140732915264716

    cout << value << endl; //11


    int &ref_value = getValue(3);
    cout << (uintptr_t)&ref_value << endl; //140732915264668

    cout << ref_value << endl; // 1765053174 : bull shit !


    return 0;
}