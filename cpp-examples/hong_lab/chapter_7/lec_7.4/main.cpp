#include  <iostream>

using namespace std;

void foo(int *ptr)
{
    cout << "Im in foo()"<<endl;

    cout << ptr <<" " << *ptr << " " << &ptr << endl;

    cout << "foo() : & ptr = " << &ptr << endl;

    cout << "Im out foo()"<<endl;

}


int main()
{

    int value = 5;

    cout << value << " " << &value << endl;

    int *ptr = &value;

    cout <<"main() : &ptr = "<< &ptr << endl;


    foo(ptr);
    //foo(&value);








    return 0;
}