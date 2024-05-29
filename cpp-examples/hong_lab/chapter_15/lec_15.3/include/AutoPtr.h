#pragma once
#include <iostream>
// Move semantics and Smart pointer

template<typename T>
class AutoPtr 
{
private:
    T* m_ptr;
public:
    AutoPtr(T *ptr=nullptr):m_ptr(ptr)
    {
        std::cout<<"AutoPtr default constructor"<<std::endl;
    }

    AutoPtr(const AutoPtr& copy)
    {
        std::cout<<"AutoPtr copy constructor"<<std::endl;
    // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
        // 메모리를 하나 새로 할당해서
        m_ptr = new T;       // 여기서 Resource 클래스의 default constructor 가 호출된다.
        // 값을 부여함
        std::cout<<"2222222222222222222"<<std::endl;
        *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
        std::cout <<"AutoPtr copy constructor end"<<std::endl;
    }

    AutoPtr& operator=(const AutoPtr& copy)
    {
        std::cout<<"AutoPtr copy assignment"<<std::endl;

        // prevent self-assignment
        if(&copy == this) return *this;

        // 기존 m_ptr에 있던 데이터값 지우고 초기화
        if(m_ptr!=nullptr)
        {
            std::cout<<"11111111111"<<std::endl;
            delete m_ptr;
            // m_ptr = nullptr;        
        }
        std::cout <<"AutoPtr copy assignment end1"<<std::endl;

    // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
        // 메모리를 하나 새로 할당해서
        m_ptr = new T;       // 여기서 Resource 클래스의 default constructor 가 호출된다.
        std::cout <<"AutoPtr copy assignment end2"<<std::endl;

        // 값을 부여함
        *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
        std::cout <<"AutoPtr copy assignment end3"<<std::endl;

    }
    ~AutoPtr()
    {
        std::cout<<"AutoPtr destructor"<<std::endl;
        if(m_ptr!=nullptr)
        {
            delete m_ptr;
            // m_ptr = nullptr;
        }
    }
};
