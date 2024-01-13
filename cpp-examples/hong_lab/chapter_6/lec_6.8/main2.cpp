#include <iostream>

using namespace std;

int main()
{

    int array[5] = {9,7,5,3,1};

    cout << array[0] << endl;
    cout << (long)array << endl; 
    cout << (long)&array[0] << endl;

    cout << *array << endl;
    cout << *(array+1) <<endl;

    char name[] = "Jackjack";
    cout << name << endl;
    cout <<*name<<endl;

    return 0;
}