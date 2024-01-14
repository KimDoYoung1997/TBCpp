#include <cstdint>
#include <iostream>

using namespace std;





int main()
{

    int int_arr[5]= {1,3,5,7,9};
    char char_arr[] = "Hello, World!";
    const char * name = "Jack Jack";
    char * name2 = char_arr ;
    char c = 'Q';

    cout <<"1. int_arr : " << int_arr << endl; // 0x7ffd40737d90
    cout <<"2. char_arr : " << char_arr << endl; // Hello, World!
    cout <<"3. name :  " << name << endl; //Jack Jack
    cout <<"4. name2 :  " << name2 << endl; //Hello, World!
    cout <<"5. &c : " << &c << endl; //Q@єRV
    cout <<"6. (void*)&c : " << (void*)&c << endl; //Q@єRV
    cout <<"7. (char*)&c : " << (char*)&c << endl; //Q@єRV
    cout <<"8. static_cast<void*>(&c) : " << static_cast<void*>(&c) << endl; //0x7ffd9548bb5f
    cout <<"9. *(char*)(static_cast<void*>(&c)) : " << *(char*)(static_cast<void*>(&c)) << endl; //Q

    // 1. int_arr : 0x7ffd967b4ca0
    // 2. char_arr : Hello, World!
    // 3. name :  Jack Jack
    // 4. name2 :  Hello, World!
    // 5. &c : Ж^[U
    // 6. (void*)&c : 0x7ffd967b4c8f
    // 7. (char*)&c : Ж^[U
    // 8. static_cast<void*>(&c) : 0x7ffd967b4c8f
    // 9. *(char*)(static_cast<void*>(&c)) : Q


    return 0;
}