#include <iostream>

using namespace std;





int main()
{
    //1.  int my_array[5] = {1,2,3,4,5}; // array initialization
    //2.  int my_array[5] = {2,1,}; // array initialization
    //3.  int my_array[] = {1,2,3,4,5}; // automatically assign the size of array by using right 
    int my_array[] {1,2,3,4,5}; // it is similiar with uniform initialization

    for (int i=0 ; i<5 ; i++)
    {
        cout << my_array[i] << endl;
    }

    cout <<"hi" << my_array << endl;
    return 0;
}