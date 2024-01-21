#include <cstdint>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printElement(int* arr)
{
    cout << "--------------------printElement() in!----------------------" << endl;

    cout << arr << " " << *arr << endl;

    cout << "--------------------printElement() out!----------------------" << endl;

}

void printElement2(int arr[])
{
    cout << "--------------------printElement2() in!----------------------" << endl;

    cout << arr << " " << *arr << endl;

    cout << "--------------------printElement2() out!----------------------" << endl;

}

void printElement3(int *&arr)
{
    cout << "--------------------printElement3() in!----------------------" << endl;

    cout << arr << " " << *arr << endl;

    cout << "--------------------printElement3() out!----------------------" << endl;

}

void printElement4(int (&arr)[4])
{
    cout << "--------------------printElement4() in!----------------------" << endl;

    cout << arr << " " << *arr << endl;

    cout << "--------------------printElement4() out!----------------------" << endl;

}

void printElement5(vector<int> &arr_vec)
{
        cout << "--------------------printElement5() in!----------------------" << endl;

    cout << &(*arr_vec.begin()) << " " << arr_vec.at(0)  << endl;

    cout << "--------------------printElement5() out!----------------------" << endl;

}


int main()
{

    int arr[] {1,2,3,4};
    cout << arr << " " << *arr << endl;

    printElement(arr);
    printElement2(arr);

    int *ptr = arr;
    printElement3(ptr);
    // printElement3(arr);  compile error!
    printElement4(arr);


    vector<int> arr_vec{1,2,3,4};
    printElement5(arr_vec);

    return 0;
}