#include <iostream>

using namespace std;


int main()
{

    int count(0) ;
/*
    char key ;


    do
    {
        cin>>key ;
        if (key =='a')
        break;
        cout << ++count << endl;

    }   
    while(1);
 */

/* 
    bool escape_flag = false;

    while(!escape_flag)
    {
        char ch;
        cin >> ch;

        cout <<ch<<" "<< ++count << endl;

        if (ch == 'x')
            escape_flag = true;



    }

 */

    while(true)
    {
        char ch;
        cin >> ch;

        cout << ch << " " << ++count << endl;

        if (ch == 'x')
            break;

    }

    return 0;
}