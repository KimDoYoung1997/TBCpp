#include <cstdint>
#include <iostream>
#include <sys/types.h>

using namespace std;

int main()
{

    const int row = 3;
    const int column = 5;

// int*[row]{r1,r2,r3} is a pointer array 
// matrix is a double pointer
    int ** matrix = new int*[row]; 


    int i = 0;
    int j = 0;
    for(int r=0 ; r<row ; r++)
    {
        
        matrix[r] = new int[column];
        for (int c=0 ; c<column ; c++)
        {
            matrix[r][c] = i+j ;
            cout <<"["<< matrix[r][c]<<"]" <<" " ;
            j++;
        }cout << endl;

        i++;
    }cout << endl;



    delete[] matrix ;

    for(int r=0 ; r<row ; r++)
    {
        
        delete[] matrix[r] ;

    }





    return 0;
}