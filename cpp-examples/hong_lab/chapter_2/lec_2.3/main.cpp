// Fixed-width Integers
#include <iostream>
#include <cstdint>

int main()
{
    using namespace std;
    std::int16_t i(5);          //typedef signed short int16_t

    std::int8_t my_int=65;      //typedef signed char int8_t

    cout<<my_int<<endl;
    cout<<sizeof(my_int)<<endl; //1 byte

    cout << sizeof(i) <<endl;   //2 byte


    std::int_fast8_t fi=5;
    cout << fi << endl;
}

