#include <iostream>
#include <cmath>
using namespace std;

void addOne(int &y)
{
    cout << "--------------------add One() in!----------------------" << endl;
    y = y+1;
    cout << y <<" "<< &y << endl;

    cout << "--------------------add One() out!----------------------" << endl;

}

int main()
{

   int x = 5;

    cout << x <<" "<< &x << endl;

    addOne(x) ;

    cout << x <<" "<< &x << endl;


    return 0;
}