#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

// Re-assign? -> Possible
    int value1 = 5;
    int value2 = 10;

    int &ref1 = value1;

    cout << ref1 << endl; // 5


    ref1 = value2;

    cout << ref1 << endl; // 10

    return 0;
}