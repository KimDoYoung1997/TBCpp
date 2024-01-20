#include <iostream>

using namespace std;

int foo(int x, int y);

int main()
{


    int x = 1, y =2 ;
    cout << foo(3,4) << endl; // 6, 7 : arguments : actual parameters

    cout << foo(x, y+1) << endl;








    return 0;
}

int foo(int x, int y) // x and y are parameters
{

    return x + y ;
} // x and y are destroyed here