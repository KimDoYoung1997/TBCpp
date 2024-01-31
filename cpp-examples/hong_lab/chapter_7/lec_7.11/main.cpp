#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // int *v_ptr = new int[3] {1,2,3} ;
    std::vector<int> v{1,2,3};

    // vector : 1. size , 2. capacity 
    for (auto &element : v)
    {
        cout << element<<" " ;
    }cout << endl;

    cout << v.size() << endl;  // 3
    return 0;
}