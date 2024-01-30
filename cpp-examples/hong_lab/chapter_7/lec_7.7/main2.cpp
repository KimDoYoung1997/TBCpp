#include <iostream>

using namespace std;

void getRandom(int &x)
{
    x++;
}

void getRandom(double &x)
{
    
}

int main()
{

    int x = 4;
    getRandom(x);
    cout << x << endl;

    return 0;
}