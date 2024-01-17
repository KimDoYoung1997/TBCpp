#include <iostream>
using namespace std;


int main()
{
     int x = 5;
    const int &ref_x = x;
    const int &ref_2 = ref_x;

    cout << ref_x << endl;
    cout << &ref_x << endl;
    cout << &x << endl;
    cout << ref_2 << endl;

    cout << "-------------" << endl;

    const int &ref_3 = 3+5;
    cout << ref_3 << endl;
    cout << &ref_3 << endl;
    return 0;
}