#include <iostream>
#include <memory>
#include "include/Resource.h"

int main() {
    auto ptr1 = std::make_shared<Resource>(3);  // 원시 포인터 선언보다는, make_shared 를 사용한 직접적인 선언방법을 주로 사용한다. 이게 더 안전함
    std::cout << "ptr1의 주소값 : " << (ptr1->m_data) << std::endl;
    std::cout << "1. shared point 개수 : " << ptr1.use_count() << std::endl;

    std::shared_ptr<Resource> ptr2 (ptr1);      // ptr1 <- ptr2
    std::cout << "ptr2의 주소값 : " << (ptr2->m_data) << std::endl;
    std::cout << "2. shared point 개수 : " << ptr1.use_count() << std::endl;
    ptr1->setAll(1);

    {
        std::shared_ptr<Resource> ptr3 = ptr1;  // ptr1 <- ptr2
                                                // ptr1 <- ptr3
        std::cout << "ptr3의 주소값 : " << (ptr3->m_data) << std::endl;
        std::cout << "3. shared point 개수 : " << ptr1.use_count() << std::endl;
        ptr3->setAll(3);

    }  // res <- ptr1

    std::cout << "4. shared point 개수 : " << ptr1.use_count() << std::endl;
}
