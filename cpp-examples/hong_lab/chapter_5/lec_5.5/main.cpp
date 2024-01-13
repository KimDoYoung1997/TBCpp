#include <iostream>

using namespace std;


int main()
{
    cout <<"While loop test" << endl;
//    int count = 0;

    int outer_count = 1;

    while(outer_count <=5)
    {
        int inner_count = 5;

        while (outer_count <= inner_count)
        {
            cout << inner_count--<<" " ;
        }
    cout << endl;

    outer_count++ ;

    }





    return 0;
}