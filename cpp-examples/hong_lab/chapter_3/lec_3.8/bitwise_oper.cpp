#include <iostream>
#include <bitset>

int main()
{
    using namespace std;

    // << left shift
    // >> right shift
    // ~ not
    // & and
    // | or
    // ^ xor


    unsigned int a = 1024;
    cout << std::bitset<16>(a) <<endl;

// bitwise left shift
    /*     cout << std::bitset<16>(a << 1) <<" "<< (a<<1) <<endl;
        cout << std::bitset<16>(a << 2) <<" "<< (a<<2) <<endl;
        cout << std::bitset<16>(a << 3) <<" "<< (a<<3) <<endl;
        cout << std::bitset<16>(a << 4) <<" "<< (a<<4) <<endl;
    */

// bitwise right shift
    /*     cout << std::bitset<16>(a >> 1) <<" "<< (a>>1) <<endl;
        cout << std::bitset<16>(a >> 2) <<" "<< (a>>2) <<endl;
        cout << std::bitset<16>(a >> 3) <<" "<< (a>>3) <<endl;
        cout << std::bitset<16>(a >> 4) <<" "<< (a>>4) <<endl;   
    */

// bitwise not ~
    cout <<std::bitset<16>(~a) << " " << (~a) << endl; // ! = Logical not

    unsigned int binary_a = 0b1100; 
    unsigned int binary_b = 0b0110; 
    
    cout << binary_a << " " << binary_b << endl;
    cout << binary_a << " " << (binary_b << 1) << endl;

// bitwise and &
    cout << std::bitset<4>(binary_a & binary_b) << endl; 
// bitwise or |
    cout << std::bitset<4>(binary_a | binary_b) << endl;
// bitwise xor ^
    cout << std::bitset<4>(binary_a ^ binary_b) << endl;

// compressed operator
    binary_a &=binary_b ; //binary_a = binary_a & binary_b
    cout << std::bitset<4>(binary_a) << endl;

}
