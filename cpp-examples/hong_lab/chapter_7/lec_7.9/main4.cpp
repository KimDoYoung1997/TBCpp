#include <array>
#include <iostream>

using namespace std;


void printNumbers(std::array<int,10> &arr , bool print_even)
{
    cout << "address of my_array in printNumber() : " << &arr << endl;

    for(auto &element : arr)
    {
        if (element % 2 == 0 && print_even )
        {
            cout << element <<" ";
            //element +=10;
        }

        if (element % 2 == 1 && !print_even)
        {
            cout << element <<" ";
            //element +=10;
        }
    cout << endl;

    }

}



int main()
{
    std::array<int,10> my_array = {0,1,2,3,4,5,6,7,8,9};

    cout << "address of my_array in main() : " << &my_array << endl;

    printNumbers(my_array,true);
    printNumbers(my_array,false);




    // for(auto element : my_array)
    // {
    //         cout << element <<" ";
    // }
    // cout << endl;


    return 0;
}