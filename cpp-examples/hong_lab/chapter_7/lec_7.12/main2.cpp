//Recursive Function Call
#include <iostream>

using namespace std;


int sumTo(int num )
{
    if (num <=0)
        return 0;
    else if (num <=1)
    {
        return 1;
    }
    else return sumTo(num-1) + num;
}



int main()
{
    cout << sumTo(10) << endl;

    return 0;
}