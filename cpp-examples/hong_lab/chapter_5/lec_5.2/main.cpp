#include <iostream>

using namespace std;

int main()
{


    int x ;
    cin >> x ;
    
    if (x>10)
        cout << x << " is greater than 10" << endl;
    else if (x<10)
        cout << x << "is not greater than 10"<<endl;    
    else
        cout << x << " is 10" << endl;


    if (1)
    {    
        cout << x << endl;
        int x = 5;
        cout << x << endl;
    }

    else
        int x = 6;

    cout << x << endl;

    return 0;
}