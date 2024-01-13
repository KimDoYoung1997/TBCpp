#include <iostream>
#include <cstdint>
using namespace std;


int main()
{


    const int num_rows = 3;
    const int num_colums = 5;

    for (int row =0; row < num_rows; row++)
    {
        for (int col=0; col < num_colums ;col++ )
        {
            cout <<'['<<row<<']' << '['<<col<<']' << '\t';
        }
        cout <<endl;
    }
    cout <<endl;


    int array[num_rows][num_colums] = 
    {
        {1,2,3,4,5}, // row 0
        {6,7,8,9,10}, // row 1 
        {11,12,13,14,15} // row2
    };


    for (int row =0; row < num_rows; row++)
    {
        for (int col=0; col < num_colums ;col++ )
        {
            //cout << array[row][col] << '\t';
            //cout << (int)&array[row][col] << '\t';  // compile error 
            cout << (intptr_t)&array[row][col] << '\t';

        }
        cout <<endl;
    }
    cout <<endl;




    return 0;
}
