#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main()
{

// // conventio nal expression

    
    vector<int> fibonacci = {0,1,1,2,3,5,8,
                            13,21,34,55,89};


    int max_number = std::numeric_limits<int>::lowest();

    cout <<"type name : " <<typeid(fibonacci).name() << endl;
    cout <<" max_number = std::numeric_limits<int>::lowest() : "<< max_number << endl;

    for (const auto &num : fibonacci)
    {
        max_number = std::max(max_number,num);
        cout << max_number << " " ;
    }cout << endl;

    






    return 0;
}