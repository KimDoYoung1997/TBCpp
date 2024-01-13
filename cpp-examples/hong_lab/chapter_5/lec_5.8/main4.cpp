#include <iostream>

using namespace std;


int main()
{

    int count(0) ;

    do
    {
        //count++;

        if (count ==5)
        continue;

        cout << count <<endl;


        //count++;
    } //while(count < 10);
    while(++count < 10);

    cout << count << endl;

    return 0;
}