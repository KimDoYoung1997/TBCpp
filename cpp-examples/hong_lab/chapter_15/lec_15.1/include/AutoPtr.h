#pragma once
#include <iostream>
using namespace std;

// Move semantics and Smart pointer
template<class T>
class AutoPtr 
{
public:
    T *m_ptr = nullptr;

public:
    //기본 생성자
    AutoPtr(T *ptr=nullptr):m_ptr(ptr)          // Resource 타입의 ptr(주소값)이 m_ptr 로 얕은복사
    {
        std::cout <<"AutoPtr Constructor" <<std::endl;
    }
    //복사 생성자
    AutoPtr(const AutoPtr& copy)               
    {
        m_ptr = copy.m_ptr;                      // copy의 주소값을 m_ptr 로 얕은 복사 후
        copy.m_ptr = nullptr;                    // 기존 copy.m_ptr 소유권을 해제 (move semantic)
                                                 // 이는 메모리가 두번 지워지는걸 방지하기 위함.
    }
    ~AutoPtr()
    {
        if(m_ptr != nullptr)
        {
            std::cout<<"member ptr destructed"<<std::endl;
            delete m_ptr;
        }
        std::cout <<"AutoPtr finally destructed" <<std::endl;


    }

    T& operator*() const
    {
        return *m_ptr;
    }

    T& operator->() const
    {
        return m_ptr;
    }
    AutoPtr & operator=( AutoPtr& copy)
    {
        std::cout <<"대입 연산자" << endl;

        if(this == &copy)
        {
            return *this;
        }
        delete m_ptr;
        m_ptr = copy.m_ptr ;
        copy.m_ptr = nullptr;                 // 기존 copy.m_ptr 소유권을 해제 (move semantic) 
        // delete copy.m_ptr ;                // 이는 메모리가 두번 지워지는걸 방지하기 위함.

    }
    bool isNull() const 
    {
        return m_ptr == nullptr;
    }

};
