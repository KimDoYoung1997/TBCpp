#include <iostream>
#include <array>
using namespace std;

//https://chat.openai.com/share/0969d0f1-5741-457b-bcf2-1531249d0b57

int& get(std::array<int,100> &my_array, int index)
{
    cout << my_array[index] << endl;
    return my_array[index] ; // the return of get() is R-value, which means there is no memory address.
}




int main()
{

    std::array<int,100> my_array;
 
    cout << my_array.at(0) << endl;
 
    my_array[30] = 10;

    int &temp = my_array[30];
    get(my_array,30) = 1024; //  same meaning : int &temp = my_array[30];    temp = 1024 ; 


    cout << my_array[30] << endl;

    return 0;
}