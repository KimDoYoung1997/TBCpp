#include <array>
#include <iostream>
using namespace std;


bool isEven(const int& number)
{
    if (number % 2 ==0)
    {
        return true;
    }

    else return false;
}


bool isOdd(const int& number)
{
    if (number % 2 ==1)
    {
        return true;
    }
    else return false;
}


typedef bool (*check_fcn)(const int&);

//void printNumbers(std::array<int,10> &arr , bool (*check_fcn)(const int&)=isEven)
void printNumbers(std::array<int,10> &arr , check_fcn=isEven)
{
    cout << "address of my_array in printNumber() : " << &arr << endl;

    for(auto &element : arr)// bool isOdd(const int& number)
// {
//     if (number % 2 ==1)
//     {
//         return true;
//     }
// }

    {
        if (check_fcn(element) ==true )
        {
            cout << element <<" ";
        }

        // if (element % 2 == 1 && !print_even)
        // {
        //     cout << element <<" ";
        //     //element +=10;
        // }
    cout << endl;

    }

}



int main()
{
    std::array<int,10> my_array = {0,1,2,3,4,5,6,7,8,9};

    cout << "address of my_array in main() : " << &my_array << endl;

    printNumbers(my_array,isEven);
    printNumbers(my_array,isOdd);
    printNumbers(my_array); // default parameter 




    // for(auto element : my_array)
    // {
    //         cout << element <<" ";
    // }
    // cout << endl;


    return 0;
}