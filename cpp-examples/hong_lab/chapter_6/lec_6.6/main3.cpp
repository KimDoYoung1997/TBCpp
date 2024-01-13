#include <iostream>

using namespace std;

int main()
{

    char myString[255];

//    cin >> myString;
    cin.getline(myString,255);
    cout <<myString<<endl ;

    int index=0;

    while (true)
    {
        if (myString[index]=='\0') break;
        cout << myString[index] <<" "<< (int)myString[index] << endl;
        index++;

    }


    return 0;
}