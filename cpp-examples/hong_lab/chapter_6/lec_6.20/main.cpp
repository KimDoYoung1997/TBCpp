#include <iostream>
#include <array>
#include <typeinfo>
using namespace std;


// call by value
void printLength_value( array<int,5> my_array2)
{
    cout <<"--------------printLength_value in--------------------" <<endl;
    cout <<"address of my_array2 : "<< &my_array2 << endl;
    //cout<< my_array2.size() << endl;
    my_array2 = {11,22,33};
    cout << my_array2.at(0) << endl; // 11
    cout <<"--------------printLength_value out--------------------" <<endl;

}


void printLength_reference( array<int,5> &my_array2)
{
    cout <<"--------------printLength_reference in--------------------" <<endl;
    cout <<"address of my_array2 : "<< &my_array2 << endl;
    my_array2 = {110,220,330};
    cout << my_array2.at(0) << endl; // 110

    cout <<"--------------printLength_reference out--------------------" <<endl;

}

int main()
{


    int my_array[5] = {1,2,3,4,5} ;

    std::array<int,5> my_array2 = {1,2,3,4,5};
    array<int,5> my_array3 = {1,2,3,4,5};


    cout << typeid(my_array).name() << endl; //A5_i
    cout << typeid(my_array2).name() << endl; //St5arrayIiLm5EE


    my_array2 = {100,200,300};
    


    cout <<"--------------main--------------------" <<endl;
    cout <<"address of my_array2 : "<< &my_array2 << endl;
    cout << my_array2[0] << endl; // 100
    cout << my_array2.at(0) << endl; //100
    printLength_value(my_array2); // call by value

    cout << my_array2.at(0) << endl; // 100

    printLength_reference(my_array2); // call by reference
    cout << my_array2.at(0) << endl; // 110


    cout <<"--------------main out--------------------" <<endl;


    return 0;
}