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
    AutoPtr(T *ptr=nullptr):m_ptr(ptr)
    {
        std::cout <<"AutoPtr Constructor" <<std::endl;
    }
    AutoPtr( AutoPtr& copy)
    {
        m_ptr = copy.m_ptr;
        copy.m_ptr = nullptr;
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
        copy.m_ptr = nullptr;
        // delete copy.m_ptr ;

    }
    bool isNull() const 
    {
        return m_ptr == nullptr;
    }

};
