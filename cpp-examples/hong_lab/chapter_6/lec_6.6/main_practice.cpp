#include <iostream>

using namespace std;

int main()
{

    char myString[] = "string";

    cout <<"size of myString : " << sizeof(myString)/sizeof(char) << endl;


    for (int i=0;i<7;++i)
    {
        //cout << myString[i] << endl;
        cout << (int)myString[i] << endl;    
    }


    return 0;
}