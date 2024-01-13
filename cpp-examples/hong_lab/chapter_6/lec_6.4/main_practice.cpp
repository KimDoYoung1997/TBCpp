#include <iostream>

using namespace std;


void printArray( int array[], int length)
{

    cout << "--- pointArray void Funct in ---" << endl;

    cout << "memory address of array is : "<< (long)array << endl;  
    cout << "meaning of const int array is that you can't modify the value of array"  <<endl;

    for (int i=0; i<(length-1) ;++i)
    {    

        for (int j=i+1; j<(length); ++j)
        {
            if (array[i] > array[j])
            {
                int temp = 0;
                temp = array[i]  ; 
                array[i] = array[j];
                array[j] = temp;

            }

        }
    
        cout << array[0]  << array[1] << array[2] << array[3] << array[4] << endl;
    }

    cout << "--- pointArray void Funct out ---" << endl;


}


int main()
{

    /*                          value       index
    |3|   5   2   1   4             1           3   25314 15324     
     1   |5|  2   3   4             2           2
     1    2  |5|  3   4             3           3
     1    2   3  |5|  4             4           3
     1    2   3   4  |5| 
    */

    const int length = 5 ;

    int num_array[length] = {3,5,2,1,4} ;


    printArray(num_array,length);

        cout << num_array[0]  << num_array[1] << num_array[2] << num_array[3] << num_array[4] << endl;

    return 0;
}