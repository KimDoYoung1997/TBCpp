#include <iostream>
#include <memory>
#include "include/Resource.h"

/* 
주어진 코드에서 Resource 객체는 new 키워드를 통해 생성된 후, 두 개의 std::shared_ptr가 동일한 원시 포인터 res를 소유하게 됩니다. 이는 다음과 같은 문제를 일으킵니다:

중복 소유권: 동일한 원시 포인터를 두 개의 shared_ptr가 소유하게 되면, 두 shared_ptr가 독립적으로 참조 카운트를 관리하게 됩니다. 
결과적으로, 첫 번째 shared_ptr가 소멸할 때 객체가 해제되지 않고, 두 번째 shared_ptr가 소멸할 때 
이미 해제된 객체를 다시 해제하려고 시도하여 이중 해제(double delete) 오류가 발생할 수 있습니다.

res <- ptr1 
    <- ptr2 
    
결론 : 동일한 원시 포인터를 두 개의 shared_ptr가 소유하게 하면 안 된다.
*/
int main()
{
    Resource* res = new Resource(3);    // 보통 이렇게 사용하지 않는다.
    res->setAll(1);
    std::shared_ptr<Resource> ptr1(res);    // res <- ptr1
    std::cout <<"res 의 주소값 : "<<(res->m_data)<<", ptr1의 주소값 : " <<(ptr1->m_data)<<std::endl;
   
    std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl;     // 1
    // ptr1->print();

    {
        std::shared_ptr<Resource> ptr2(res);   // res <- ptr1 
                                                //     <- ptr2 


        ptr2->setAll(3);
        std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl; // 1
        // ptr2->print();
    }// res <- ptr1

    // ptr1->print();
    std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl;     // 1

    // delete res; 컴파일 에러
}