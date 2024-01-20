#include <cstdint>
#include <iostream>
#include <array>
#include <typeinfo>
#include <algorithm>

using namespace std;


int main()
{
    std::array<int, 5> my_arr = {1,21,3,40,5};


    for(auto &element : my_arr)
    {
        cout << element << " " ;
    }cout << endl;

    cout << &my_arr << " " << (uintptr_t)my_arr.begin() <<" "<<(uintptr_t)my_arr.end()<<" "<< endl;

    std::sort(my_arr.begin(),my_arr.end());


    cout <<"After sort" << endl;
    for(auto &element : my_arr)
    {
        cout << element << " " ;
    }cout << endl;



    cout <<"After reverse sort" << endl;
    std::sort(my_arr.rbegin(),my_arr.rend());

    for(auto &element : my_arr)
    {
        cout << element << " " ;
    }cout << endl;

    return 0;
}