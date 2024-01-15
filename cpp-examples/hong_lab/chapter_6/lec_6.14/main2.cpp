#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

    int value = 5;

    //int &ref; // reference must be initialized before compile. if not, error occured.
    //int &ref = 104; // reference can't be initialized with literal constant. because literal can't be allocated memory address
    int &ref= value;


    const int y =  8;
    const int &ref_y = y;

    cout <<y<<endl;

    return 0;
}