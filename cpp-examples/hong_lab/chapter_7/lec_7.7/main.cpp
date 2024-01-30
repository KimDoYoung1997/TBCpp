#include <iostream>

using namespace std;

int add(int x, int y)
{
    cout << "Im in [int add(int x, int y)] !" << endl;

    return x+y ;
}

double add(double x, double y)
{
    cout << "Im in [double add(double x, double y)]  !" << endl;
    return x+y ;
}

double add(int x, double y)
{
    cout << "Im in [double add(int x, double y)]  !" << endl;
    return x+y ;
}



int main()
{
    add(1, 2);
    add(2.0, 3.0);
    add(3,4.0);
    
    //Call to 'add' is ambiguous   -> Compile error!!
    //add(3.0,4);


    return 0;
}