#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;


    if (x>10)
    {
    };
    cout << "end1" << endl;



    if (x>10)
    ;
    cout << "end2" << endl;
    

    if (x>10);
    {
        cout <<"Im in"<<endl;
    }
    cout << "end3" << endl;

    return 0;
}