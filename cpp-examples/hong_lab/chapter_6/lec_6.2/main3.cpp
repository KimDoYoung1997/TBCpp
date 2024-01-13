#include <iostream>
#include <cstdint>

using namespace std;

void doSomething (int num_students)
{

    cout << sizeof(num_students) << endl; 
    cout <<reinterpret_cast<uintptr_t>(&num_students) << endl;


}


int main()
{
    int num_students = 20;

    cout << sizeof(num_students) << endl; 
    cout <<reinterpret_cast<uintptr_t>(&num_students)<<endl;

    doSomething(num_students);


    return 0;
}
