
// global variable , static variable 
#include <iostream>

using namespace std;

int value = 10 ;
//


int main()
{


    cout << value << endl;

    int value = 1;

    cout <<"This is global value: "<<::value << endl; 
    cout <<"This is locaal value: "<< value << endl;

    
    return 0;
}