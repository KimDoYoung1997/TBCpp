#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //std::array<int,5> static_array ; 
    std::vector<int> array ;
    std::vector<int> array2 = {1,2,3,4,5};

    cout << array2.size() << endl;
    std::vector<int> array3 {1,2,3,};
    cout << array3.size() << endl;

    vector<int> arr = {1,2,3,4,5};

    for (auto &element :arr)
    {
        cout << element << " ";
    }cout << endl;

    cout << arr.size() << endl;
    cout << arr[1] << endl;


    cout <<"vector resize! 5->10" << endl;
    arr.resize(10);

    for (auto &element :arr)
    {
        cout << element << " ";
    }cout << endl;

    cout << arr.size() << endl;
    cout << arr[1] << endl;








    return 0;
}