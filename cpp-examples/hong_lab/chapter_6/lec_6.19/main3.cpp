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

    int static_r1[] = {0,1,2,3,4};
    int static_r2[] = {5,6,7,8,9};
    int static_r3[] = {10,11,12,13,14};

    int* static_array[row] = {static_r1,static_r2,static_r3};
    int ** double_ptr = static_array;


    cout << "double_ptr" << endl;
    for (int i=0;i<row;i++)
    {

        for (int j=0;j<column;j++)
        {
            double_ptr[i][j];
        }

    }


// Dynamic allocation array
// Each r1,r2,r3 is a pointer
    int *r1 = new int[column]{0,1,2,3,4};
    int *r2 = new int[column]{5,6,7,8,9};
    int *r3 = new int[column]{10,11,12,13,14};

// int*[row]{r1,r2,r3} is a pointer array 
// row_db_ptr is a double pointer
    int ** row_db_ptr = new int*[row]{r1,r2,r3}; 

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            cout << row_db_ptr[i][j] << " " ;
        }cout << endl;
    }cout << endl;


    delete[] r1;
    delete[] r2;
    delete[] r3;
    delete[] row_db_ptr;



    return 0;
}