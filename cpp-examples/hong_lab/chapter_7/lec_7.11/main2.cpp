#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // int *v_ptr = new int[3] {1,2,3} ;
    std::vector<int> v{1,2,3};

    cout <<"vector Stack object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;


    cout << "first resize(size : 3-> 10)" << endl;

    v.resize(10);

    // vector : 1. size , 2. capacity 
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 3 0 0 0 0 0 0 0 
    }cout << endl;

    cout <<"vector Stack object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 10 10 


    cout << "second resize(size : 10-> 2)" << endl;


    v.resize(2);

    // vector : 1. size , 2. capacity 
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 3 0 0 0 0 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;

    cout << v.size() << " " <<v.capacity() << endl;  // 2 10 

    cout <<v[5] << endl;
    //cout <<v.at(5) << endl; // terminate called after throwing an instance of 'std::out_of_range' what():  vector::_M_range_check: __n (which is 5) >= this->size() (which is 2) Aborted (core dumped)

    int *ptr = v.data();
    cout << &v[0] << endl;
    cout << ptr << endl;
    //cout << v << endl; Compile error
    cout << &v << endl;

    cout <<v[2] << endl;


    cout << "second resize(size : 2-> 20)" << endl;
    v.resize(20);
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 20 20 

    cout << "second resize(size : 20-> 5)" << endl;
    v.resize(5);
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 5 20 

    cout << "second resize(size : 5-> 10)" << endl;
    v.resize(10);
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 5 20 


    cout << "second resize(size : 10-> 15)" << endl;
    v.resize(15);
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 5 20 

    cout << "second resize(size : 15-> 25)" << endl;
    v.resize(25);
    for (auto &element : v)
    {
        cout << element<<" " ; // 1 2 0 0 0 
    }cout << endl;
    cout <<"vector object address of v : " << &v << endl;
    cout <<"vector Heap first element address of v : " << (uintptr_t)v.data() << endl;
    cout << v.size() << " " <<v.capacity() << endl;  // 5 20 



    // int arr[] = { 1,2,3};
    // cout << arr << " " << &arr[0] << " " << &arr << endl;

    return 0;
}