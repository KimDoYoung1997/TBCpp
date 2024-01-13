#include <iostream>

using namespace std;

int main()
{

    double x;

    tryAgain : //label

    cout <<"Enter a non-negative numger" << endl;
    cin >> x;

    if (x<0.0)
        goto tryAgain;



    goto wormhole; 
    cout << "Im in Blackhole" << endl;
    wormhole :
    cout << "I'm alive Interstella"<<endl;


    return 0;
}