#include <cstdint>
#include <iostream>

using namespace std;


int main()
{

    const int length = 5;

    //cin >> length;

    int *array = new int[3]{3,2,1};

    cout << *array <<" "<< *(array+1) <<" "<< *(array+2)<< endl;
    cout << array[0] <<" "<< array[1] <<" "<< array[2]<< endl;


    cout << *array <<" "<< *(array-1) <<" "<< *(array-2)<< endl;
    cout << *array <<" "<< *(array+3) <<" "<< *(array+50)<< endl;

    cout << (uintptr_t)array <<" "<< (uintptr_t)(array+1) <<" "<< (uintptr_t)(array+2)<< endl;

    //int array[length];

    cout << (uintptr_t)&array << endl;

    delete[] array;
    array = nullptr;
    cout << "memory delete completed. let's check!" << endl;

    cout << (uintptr_t)array <<" "<< (uintptr_t)(array+1) <<" "<< (uintptr_t)(array+2)<< endl;
    
    
    if (array != nullptr)
    {
        cout << *array <<" "<< *(array+1) <<" "<< *(array+2)<< endl;
        cout << array[0] <<" "<< array[1] <<" "<< array[2]<< endl;
    }
    else if (array==nullptr)
    {
        cout <<"Finally, array is deleted to NULL!" << endl;
    }

    return 0;
}