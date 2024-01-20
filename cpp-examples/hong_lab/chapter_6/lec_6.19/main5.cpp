#include <cstdint>
#include <iostream>
#include <sys/types.h>

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

    int * matrix = new int[row*column];

    for (int r=0; r<row ; r++)
    {
        for (int c=0 ; c<column ; c++)
        {
            matrix[c + (column*r)] = arr[r][c];
            // matrix0 matrix1 matrix2 matrix3 matrix4
            // matrix5 matrix6 matrix7 matrix8 matrix9
            // matrix10 matrix11 matrix12 matrix13 matrix14
        }
    }

    for (int i=0; i<row ; i++)
    {
        for (int j=0; j<column; j++)
        {
            cout <<"["<< matrix[j + column*i] << "] " ;
        }
    }


    delete[] matrix;


    return 0;
}