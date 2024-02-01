//Defensive Programming
#include <iostream>
//#include <string>

using namespace std;

int main()
{

    //syntax error
    //semantic error
    //violated assumption

    string hello = "hello, my name is jack";

    int ix;
    cin >> ix;

    cout << hello[ix] << endl;



    return 0;
}