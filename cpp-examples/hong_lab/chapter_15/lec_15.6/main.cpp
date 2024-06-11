#include <iostream>
#include <memory>
#include "include/Resource.h"

/* 

res <- ptr1 <- ptr2 

*/
int main()
{
    Resource* res = new Resource(3);
    res->setAll(1);
    std::shared_ptr<Resource> ptr1(res);    // res <- ptr1
    std::cout <<"res 의 주소값 : "<<(res->m_data)<<", ptr1의 주소값 : " <<(ptr1->m_data)<<std::endl;
   
    std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl; // 1
    ptr1->print();

    {
        std::shared_ptr<Resource> ptr2(ptr1);   // res <- ptr1 <- ptr2 


        ptr2->setAll(3);
        std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl;  // 2
        ptr2->print();
    }// res <- ptr1

    ptr1->print();
    std::cout<<"shared point 개수 : "<<ptr1.use_count()<<std::endl;      // 1

    // delete res; 컴파일 에러
}