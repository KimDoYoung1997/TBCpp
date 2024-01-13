#include <iostream>

using namespace std;


//void printArray(int *array)  // this expression is exactly same with below 
struct MyStruct
{
    int array[5] = {9,7,5,3,1};

};

void doSomething(MyStruct ms)
{
    cout <<"Im in doSomething" << endl;
    cout << sizeof(ms.array) <<endl;
    cout <<"Im out doSomething" << endl;

}

void doAnother(MyStruct *ms)
{
    cout <<"Im in doAnother" << endl;

    cout << sizeof((*ms).array) <<endl;
    cout <<"Im out doAnother" << endl;

}

int main()
{

    MyStruct ms;
    cout << ms.array[0] << endl;

    cout << sizeof(ms.array) << endl;
    doSomething(ms);    
    doAnother(&ms);

    return 0;
}