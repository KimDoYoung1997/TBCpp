#include <iostream>
#include <cstring> // strcpy
#include <cstdint>

using namespace std;


int main()
{
    char source[] = "Copy this!";
    char dest[50];
    strcpy(dest, source);
    int arr[3] ={1,2,3};

    cout <<"source : " << source << endl;
    cout << "memory address of source : " <<(long)(int*)&(source[0]) << endl;
    cout <<"dest : "<< dest << endl;
    cout << "memory address of dest : " << (long)(int*)&(dest[0]) << endl;

    cout << "arr : " << arr << endl;

    return 0;
}