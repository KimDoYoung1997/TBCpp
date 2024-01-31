#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // Print initial size and capacity
    std::cout << "Initial size: " << vec.size() << std::endl;
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    // Add 5 elements to the vector
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
        std::cout << "After adding element " << i << " - ";
        std::cout << "Size: " << vec.size() << ", ";
        std::cout << "Capacity: " << vec.capacity() << std::endl;
    }

    // Observe how capacity grows, potentially surpassing size
    std::cout << "Final size: " << vec.size() << std::endl;
    std::cout << "Final capacity: " << vec.capacity() << std::endl;

    return 0;
}
