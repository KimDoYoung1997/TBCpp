#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // int *v_ptr = new int[3] {1,2,3} ;
    std::vector<int> v{1,2,3};

    v.reserve(1024);

    for (auto &element :v )
    {
        cout << element << " " ;
    }cout << endl;

    cout << "v.size() : " << v.size() <<" v.capacity() : " << v.capacity() << endl;


    // int arr[] = { 1,2,3};
    // cout << arr << " " << &arr[0] << " " << &arr << endl;

    return 0;
}