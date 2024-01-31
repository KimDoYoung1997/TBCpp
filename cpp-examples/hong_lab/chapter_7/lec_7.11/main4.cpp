#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;


void printStack(const std::vector<int> &stack)
{

    for (auto &element :stack )
    {
        cout << element << " " ;
    }cout << endl;

    cout << "stack.size() : " << stack.size() <<" , stack.capacity() : " << stack.capacity() << " , address of stack :  " << (uintptr_t)stack.data() << endl;



}

int main()
{

    // int *v_ptr = new int[3] {1,2,3} ;
    std::vector<int> stack;


    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(7);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);


    //stack.reserve(1024);


    // int arr[] = { 1,2,3};
    // cout << arr << " " << &arr[0] << " " << &arr << endl;

    return 0;
}