#include <iostream>

using namespace std;


int main()
{
    char myString[] = "string";

    for (int i=0;i<7;++i)
    {
        //cout << myString[i] << endl;
        //cout << (int)myString[i] << endl;
    }

    cout << sizeof(char) << endl;
    cout << sizeof(myString[0]) << endl;
    cout << sizeof(myString) << endl;


    char yourString[255] ;
    cin.getline(yourString,255);

    //cin >> yourString;
    // cout << yourString << endl;
    // cout << sizeof(yourString) << endl;
    // cout << sizeof(yourString[11]) << endl;
    // yourString[11] = 'A' ; 
    // cout << yourString << endl;
    // yourString[4] = '\0';
    // cout << yourString << endl;

    int ix = 0;

    while (true)
    {
        if(yourString[ix] == '\0') break;

        cout << yourString[ix] <<" " << (int)yourString[ix] << endl;
        ++ix;
    }
    

    return 0;
}