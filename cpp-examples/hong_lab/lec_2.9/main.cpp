#include <iostream>
using namespace std;


void printNumber(const int& my_number)
{
    cout << my_number << endl;
    int n=my_number + 1;
    //  my_number = 3;
}

int main()
{
    printNumber(3);
    return 0;
}