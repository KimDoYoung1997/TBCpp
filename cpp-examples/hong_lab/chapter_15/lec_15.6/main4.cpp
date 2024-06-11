#include <iostream>
#include <memory>
#include "include/Resource.h"


int main() {
    auto ptr1 = std::make_shared<Resource>(3);  // 원시 포인터 선언보다는, make_shared 를 사용한 직접적인 선언방법을 주로 사용한다. 이게 더 안전함
    ptr1->setAll(1);
    ptr1->print();

        std::cout << "Going to get inside the block , ptr1 count : " << ptr1.use_count() << std::endl;
    {
        auto ptr2(ptr1);      // ptr1 <- ptr2
        ptr1->setAll(3);
        ptr2->print();
        std::cout << "Going to out of the block , ptr1 count : " << ptr1.use_count() << std::endl;

    }  // res <- ptr1
        std::cout << "out of the block , ptr1 count : " << ptr1.use_count() << std::endl;
}
