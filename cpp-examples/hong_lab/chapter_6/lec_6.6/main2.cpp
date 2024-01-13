#include <iostream>
#include <cstring> // strcpy
#include <cstdint>

using namespace std;


int main()
{
    char source[] = "Copy this"; 
    //char dest[50] ; // max 50 characters
    char dest[5] ; // max 5 characters

    cout <<"1 "<< source<<" "<<(intptr_t)&(source) << " " << sizeof(source) << endl;
    cout <<"1 "<< dest<<" "<<(intptr_t)&(dest) << " "<< sizeof(dest) <<endl;

    //strcpy(dest,source); //copy source array contents to dest array contents 
    // strcpy(dest,source,4); //copy source array contents to dest array contents 
    strncpy(dest, source, 4); // Copying only 4 characters to prevent overflow

    cout << source<<" "<<(intptr_t)&(source) << " " << sizeof(source) << endl;
    cout << dest<<" "<<(intptr_t)&(dest) << " "<< sizeof(dest) <<endl;


    return 0;
}