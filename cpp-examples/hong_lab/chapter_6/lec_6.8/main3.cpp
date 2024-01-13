#include <iostream>

using namespace std;


//void printArray(int *array)  // this expression is exactly same with below 
void printArray(int array[])
{
    cout << "Im in print Array Func()" << endl;
    cout << *array <<endl;
    cout << sizeof(array) << endl;

    *array = 100;
    cout << "Im out print Array Func()" << endl;

}

void printPointer(int* ptr)
{
    cout << sizeof(ptr) << endl; 
}



int main()
{

    int array[5] = {9,7,5,3,1};
    int *ptr = array;

    
    //Although array's first element address means pointer, there is some differences between pointer and array.

    cout <<"============array============"<<endl;
    cout <<(long)array << endl;
    cout << sizeof(array) << endl;
    cout << typeid(array).name() << endl; //A5_i
    
    cout <<"============pointer============"<<endl;
    cout <<(long)ptr << endl;
    cout << sizeof(ptr) << endl;
    cout <<typeid(ptr).name() << endl;

    printArray(array);

    cout << array[0] << " " << *array << endl;
    return 0;
}