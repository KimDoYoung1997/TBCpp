#include <cstdint>
#include <iostream>

using namespace std;

int main()
{

    const int row = 3;
    const int column = 5;

    int arr[row][column] = 
    {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14}
    
    };

    int zero[row][column]{0};

    cout << sizeof(arr) << endl;

    for (int i=0 ; i<row ; i++)
    {

        for (int j=0 ; j<column ; j++ )
        {
            //cout << arr[i][j] << " " ;
            cout << zero[i][j] << " " ;
        }
        cout << endl;


    }
    cout << endl;



    return 0;
}