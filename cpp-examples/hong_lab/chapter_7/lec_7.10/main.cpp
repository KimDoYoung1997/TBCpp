#include <iostream>

int g_i = 0; // global variabe -> code

int second (int x)
{
    return 2 * x;
}

int first(int x)
{
    int y = 3; 
    return second(x+y);
}

int main()
{
    using namespace std;

    int a = 1 , b;
    b = first(a);
    cout << b <<endl;


    return 0;
}