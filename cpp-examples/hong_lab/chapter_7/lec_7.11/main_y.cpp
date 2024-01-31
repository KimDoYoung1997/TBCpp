#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5}; // std::vector 인스턴스 생성
    std::vector<int>* ptr = &myVector; // myVector의 주소를 ptr 포인터에 할당

    cout << &myVector << endl;

    cout << myVector.data() << endl;

    cout <<"--------------------------------------" << endl;
    // 포인터를 사용하여 벡터의 요소에 접근
    for(size_t i = 0; i < ptr->size(); ++i) {
        std::cout << (*ptr)[i] << " "; // ptr을 역참조하여 벡터의 요소에 접근
    }
    std::cout << std::endl;

    return 0;
}
