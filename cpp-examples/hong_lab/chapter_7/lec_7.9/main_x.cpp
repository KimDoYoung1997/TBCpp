#include <cstdint>
#include <iostream>

using namespace std;


// Chatgpt question
// https://chat.openai.com/share/d4518860-bec9-4df6-b22b-881d00fdfa2a 


int func()
{
    return 5;
}


int main()
{


    int a = 3;
    int b = 5;
    int *ptr = & a;

    cout << uintptr_t(ptr) << endl;
    
    ptr = &b;
    cout << uintptr_t(ptr) << endl;
    
    int arr[] = {1,2,3};
    int brr[] = {4,5,6};
    int *ptr_arr = arr;

    cout << arr << endl;
    cout << brr << endl;

    arr = brr;
    //arr = brr;

    return 0;
}