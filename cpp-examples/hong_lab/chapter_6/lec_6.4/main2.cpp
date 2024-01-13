#include <iostream>

using namespace std;


void printArray(const int array[], const int length)
{
    for (int i=0; i<length ;i++ )
    {
        cout << array[i] << " " ;
    }
    cout << endl;
}

int main()
{

    /*                          value       index
    |3|   5   2   1   4             1           3       
     1   |5|  2   3   4             2           2
     1    2  |5|  3   4             3           3
     1    2   3  |5|  4             4           3
     1    2   3   4  |5| 
    */

    const int length = 5 ;

    int num_array[] = {3,5,2,1,4,} ;
    int temp = 0;

    printArray(num_array,length);

    for (int startIndex=0 ; startIndex<(length-1) ; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex+1; currentIndex<length ;++currentIndex)
        {
            if (num_array[startIndex] > num_array[currentIndex] )
            {
                smallestIndex = currentIndex;                
            }
            {
                temp= num_array[smallestIndex] ; 
                num_array[smallestIndex] = num_array[startIndex];
                num_array[startIndex] = temp;
            }
        printArray(num_array,length);

        }


\
    }

//    cout << num_array[0] << num_array[1] << num_array[2] << num_array [3] << num_array[4] << endl; 


    return 0;
}