#include  <iostream>

using namespace std;

void foo(int *arr, int length)
{
    cout << "Im in foo()"<<endl;

    for (int i =0 ; i<length ; i++)
    {
        cout <<arr[i] << " ";
    }cout << endl;
    cout << "Im out foo()"<<endl;

    arr[0] = 88;

}


int main()
{

    int arr[] = {5,4,3,2,1};

    cout << arr << " " << arr[0] << endl;

    int *ptr = arr;

    cout <<"main() : &ptr = "<< &ptr << endl;


    foo(arr,5);
    //foo(&value);

    cout << arr[0] << endl;







    return 0;
}