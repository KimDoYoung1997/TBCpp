#pragma once
#include <iostream>
// Move semantics and Smart pointer

template<typename T>
class AutoPtr 
{
public:
    T* m_ptr;       // Resource * m_ptr;
public:
    AutoPtr(T *ptr=nullptr):m_ptr(ptr)
    {
        std::cout<<"AutoPtr default constructor"<<std::endl;
        // std::cout <<"ptr 값"<<ptr << std::endl;
        // std::cout <<"m_ptr 값"<<m_ptr << std::endl;
    }

    AutoPtr(const AutoPtr& copy)
    {
        std::cout<<"AutoPtr copy constructor"<<std::endl;
        // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
        // 메모리를 하나 새로 할당해서
        m_ptr = new T;          // 여기서 Resource 클래스의 default constructor 가 호출된다.
        // 값을 부여함
        std::cout<<"2222222222222222222"<<std::endl;
        *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
        std::cout <<"AutoPtr copy constructor end"<<std::endl;
    }

    AutoPtr(AutoPtr&& copy):m_ptr(copy.m_ptr)
    {
        std::cout<<"AutoPtr move constructor"<<std::endl;
        copy.m_ptr = nullptr;  // 소유권 이전하므로 deep-copy 수행하지 않음
    }

    AutoPtr& operator=(const AutoPtr& copy)
    {
        std::cout<<"AutoPtr copy assignment 1"<<std::endl;

        // prevent self-assignment
        if(&copy == this) return *this;

        // 기존 m_ptr에 있던 데이터값 지우고 초기화
        if(m_ptr!=nullptr)
        {
            std::cout<<"delete existing Resource class in AutoPtr"<<std::endl;
            delete m_ptr;
            // m_ptr = nullptr;        
        }
        std::cout <<"AutoPtr copy assignment 2"<<std::endl;

        // deep-copy를 수행할 것이라, 시간이 꽤 소요될 것이다.
        // 메모리를 하나 새로 할당해서
        m_ptr = new T;       // 여기서 Resource 클래스의 default constructor 가 호출된다.
        std::cout <<"AutoPtr copy assignment 3"<<std::endl;

        // 값을 부여함
        *m_ptr = *copy.m_ptr;   // 여기서 Resource 클래스의 copy assignment가 호출된다.
        std::cout <<"AutoPtr copy assignment 4 end"<<std::endl;

        return *this;   // 여길 깜빡했네.. return값을 안 주다니..
    }
    AutoPtr& operator=(AutoPtr&& copy)
    {
        std::cout <<"AutoPtr move assignment" << std::endl;
        if(&copy == this) return *this;

        if(m_ptr!=nullptr)
        {
            std::cout<<"delete existing Resource class in AutoPtr"<<std::endl;
            delete m_ptr;
            // m_ptr = nullptr;        
        }

        //shallow copy
        m_ptr = copy.m_ptr;
        copy.m_ptr = nullptr;
        return *this;
    }

    // -> 연산자 오버로딩
    T* operator->() const
    {
        return m_ptr;
    }

    ~AutoPtr()
    {
        std::cout<<"************** AutoPtr destructed start **************"<<std::endl;
        if(m_ptr!=nullptr)
        {
            std::cout<<"AutoPtr의 m_ptr(Resource)이 deleted"<<std::endl;
            delete m_ptr;
            // m_ptr = nullptr;
        }
        std::cout<<"************** AutoPtr destructed end **************"<<std::endl;
    }
};
