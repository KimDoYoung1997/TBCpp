#include <iostream>
#include <array>
using namespace std;



int& get(std::array<int,100> &my_array, int index)
{
    return my_array[index] ;
}

int& RefRetFuncOne(int &ref)
{
    ref++;
    cout <<"type name of ref :" << typeid(ref).name() << endl;

    cout <<"ref address : "<< &ref << endl;

    return ref;
}

int RefRetFuncTwo(int &ref2)
{
    ref2++;
    cout <<"type name of ref2 :" << typeid(ref2).name() << endl;

    cout <<"ref2 address : "<< &ref2 << endl;

    return ref2;
}

int main()
{

    int num1 = 1;

    int &num2 = RefRetFuncOne(num1); //int& temp = num1 , int& num2 = temp
    int num3 = RefRetFuncTwo(num1); // int temp = num1 , int num3 = temp
    int num4 = RefRetFuncOne(num1); // int & temp = num1 , int num4 = temp
    //int& num5 = RefRetFuncTwo(num1); : Compile error!
    num1++;
    num2++;

    cout <<"num1 : "<< num1 <<" num1 address : "<<&num1<<endl;
    cout <<"num2 : "<< num2 <<" num2 address : "<<&num2<< endl;
    cout <<"num3 : "<< num3 <<" num3 address : "<<&num3<< endl;
    cout <<"num4 : "<< num4 <<" num4 address : "<<&num4<< endl;


    return 0;
}