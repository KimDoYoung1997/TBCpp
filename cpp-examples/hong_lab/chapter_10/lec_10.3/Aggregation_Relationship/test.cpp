#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> nums{0,1,2,3,4};
    //std::cout <<nums.size() << std::endl;
    std::cout <<(uintptr_t)&(nums[0]) << " ";
    std::cout <<(uintptr_t)&(nums[1]) << " ";
    std::cout <<(uintptr_t)&(nums[2]) << " ";
    std::cout <<(uintptr_t)&(nums[3]) << " ";
    std::cout <<(uintptr_t)&(nums[4]) << endl;

    //nums.emplace_back(5);
    //std::cout <<(uintptr_t)&(nums[5]) << endl;

    for(auto& i:nums)
    {
        cout <<(uintptr_t)&i<< " ";
    }cout <<endl;
    return 0;
    cout << endl;


}