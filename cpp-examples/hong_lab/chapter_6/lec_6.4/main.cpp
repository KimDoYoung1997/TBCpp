#include <iostream>

using namespace std;


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

    int num_array[] = {3,5,2,1,4} ;
    int temp = 0;


    for (int i=0 ; i<(length-1) ; i++)
    {

        for (int j = i+1; j<length ;j++)
        {
            if (num_array[i] > num_array[j] )
            {

                cout << "trap activated " <<num_array[i] << " " <<num_array[j] << endl;
                temp=num_array[i] ; 
                num_array[i] = num_array[j];
                num_array[j] = temp;

                cout << "trap result " <<num_array[i] << " " <<num_array[j] << endl;
            }
        }

    }

    cout << num_array[0] << num_array[1] << num_array[2] << num_array [3] << num_array[4] << endl;


    return 0;
}