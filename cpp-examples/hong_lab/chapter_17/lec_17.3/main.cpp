#include <iostream>
#include <string>
#include <cstring> // strlen 함수를 사용하기 위해 추가

int main()
{
    std::cout<<std::boolalpha;
    std::string my_str("012345678");
    std::cout <<my_str.size()<<std::endl;                // 9 , C-Style과 달리 null을 계산하지 않는게 특징. (클래스로 구현되어 있기때문에 null이 필요없다.)
    
    // C-style
    std::cout << sizeof("012345678") << std::endl;       // C-stayle은 null 까지 추가돼서 10
    
    std::cout <<my_str.empty()<<std::endl;               //   false
    std::cout <<my_str.length()<<std::endl;              //   9
    std::cout <<my_str.capacity()<<std::endl;            //   15 , 컴파일러나 OS에 따라 다름. string도 벡터와 마찬가지로, 새로운 데이터의 유입을 고려함. 가급적 메모리 re-allocation을 하지 않기 위해 여유 capacity를 가짐
    std::cout <<my_str.max_size()<<std::endl;            //   4611686018427387903 , 컴파일러나 OS에 따라 다름. 최대 몇 글자까지 넣을 수 있는지

    my_str.reserve(1000);
    std::cout <<my_str.capacity()<<std::endl;            //   1000 ,  string도 벡터와 마찬가지로, reserve 할 수 있음

    return 0;
}