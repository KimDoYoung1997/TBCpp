#pragma once
#include <iostream>
// Move semantics and Smart pointer

template<typename T>
class AutoPtr 
{
private:
    T* m_ptr;       // Resource * m_ptr;
public:
    AutoPtr(T *ptr=nullptr):m_ptr(ptr)
    {
        std::cout<<"AutoPtr default constructor"<<std::endl;
    }

    // AutoPtr(const AutoPtr& copy)
    // {
    //     std::cout<<"AutoPtr copy constructor"<<std::endl;
    // // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
    //     // 메모리를 하나 새로 할당해서
    //     m_ptr = new T;       // 여기서 Resource 클래스의 default constructor 가 호출된다.
    //     // 값을 부여함
    //     std::cout<<"2222222222222222222"<<std::endl;
    //     *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
    //     std::cout <<"AutoPtr copy constructor end"<<std::endl;
    // }

    AutoPtr(AutoPtr&& a):m_ptr(a.m_ptr)
    {
        std::cout<<"AutoPtr move constructor"<<std::endl;
        a.m_ptr = nullptr;  // 소유권 이전하므로 deep-copy 수행하지 않음
    }

    // AutoPtr& operator=(const AutoPtr& copy)
    // {
    //     std::cout<<"AutoPtr copy assignment 1"<<std::endl;

    //     // prevent self-assignment
    //     if(&copy == this) return *this;

    //     // 기존 m_ptr에 있던 데이터값 지우고 초기화
    //     if(m_ptr!=nullptr)
    //     {
    //         std::cout<<"delete existing Resource class in AutoPtr"<<std::endl;
    //         delete m_ptr;
    //         // m_ptr = nullptr;        
    //     }
    //     std::cout <<"AutoPtr copy assignment 2"<<std::endl;

    //     // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
    //     // 메모리를 하나 새로 할당해서
    //     m_ptr = new T;       // 여기서 Resource 클래스의 default constructor 가 호출된다.
    //     std::cout <<"AutoPtr copy assignment 3"<<std::endl;

    //     // 값을 부여함
    //     *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
    //     std::cout <<"AutoPtr copy assignment 4 end"<<std::endl;

    //     return *this;   // 여길 깜빡했네.. return값을 안 주다니..
    // }
    AutoPtr& operator=(AutoPtr&& a)
    {
        std::cout <<"AutoPtr move assignment" << std::endl;
        if(this == &a)
        {
            return *this;
        }
        if(this->m_ptr!=nullptr)
        {
            std::cout<<"delete existing Resource class in AutoPtr"<<std::endl;
            delete m_ptr;
        }

        //shallow copy
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
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
