#include <cstdint>
# include <iostream>
#include <sys/types.h>

using namespace std;




int main()

{

// //CASE 1
//     const int value = 5;
//     const int* ptr = &value;
//     //*ptr = 6;  //impossible
//     // value=6 ; //impossible
//     cout << ptr << endl;


// // CASE2
//     int value = 5;
//     const int* ptr = &value;
//     //*ptr = 6; //impossible
//     value=6; //possible
//     cout << *ptr << endl; // 6 


// // CASE3
//     const int value = 5;
//     int* ptr = &value;
//     *ptr = 6; //impossible
//     cout << *ptr << endl; // compile error


// // CASE4
//     int value1 = 5;
//     const int *ptr = &value1;
//     cout <<"Step1. int *ptr = &value1 : " << (uintptr_t)ptr << endl;

//     int value2 = 6;
//     ptr=&value2;
//     cout <<"Step2. &value2 : " << (uintptr_t)&value2 << endl;


//     cout <<"Step3. ptr=&value2 : " <<(uintptr_t)ptr << endl;
//     cout <<"de-reference of ptr is : " << *ptr <<endl; // result : 6


// // CASE5
//     int value = 5;
//     int *const ptr = &value;

//     cout << *ptr << endl; // 5
//     *ptr = 78;
//     cout << *ptr << endl ; // 78

//     int value2 = 78;
//     ptr = &value2; //compile error


// // CASE6
//     int value = 5;
//     // const int *const ptr; // compile error. in this CASE6, it requires initialization. unless initialization, compile error occured.
//     const int *const ptr= &value;

//     // in this case neither change address or memory nor de-reference is possible.


// SUMMARY
    int value = 5;
    const int *ptr1 = &value;
    int *const ptr2 = &value;
    const int *const ptr3  = &value;

    

    return 0;
}