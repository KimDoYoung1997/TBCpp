#pragma once
#include <iostream>
// Move semantics and Smart pointer
class Resource 
{
public:
    int *m_data=nullptr;
    unsigned m_length = 0;
public:
    Resource();
    Resource(unsigned length);
    Resource(const Resource&copy);
    Resource & operator=(Resource & copy)
    {
        std::cout<<"********** 3. Resource copy assignment **********"<<std::endl;
        if(&copy == this)
        {
            return *this;
        }
        // std::cout<<"********** debug1 **********"<<std::endl;

        if(m_data !=nullptr) delete[] m_data;
        // std::cout<<"********** debug2 **********"<<std::endl;
        // std::cout <<m_length<<std::endl;
        std::cout <<"Resource &copy의 주소값 : "<<&copy<<std::endl;
        if (static_cast<void*>(&copy) == 0)
        {
            std::cout <<"Resource 의 기본생성자에 아무 인수가 들어가지 않았습니다. 따라서 deep copy가 불가능합니다."<<std::endl;
        }

        m_length = copy.m_length;
        // std::cout<<"********** debug3 **********"<<std::endl;

        m_data = new int(m_length);

        for (unsigned i=0;i<m_length;++i)
        {
            m_data[i] = copy.m_data[i];
        }
        std::cout<<"********** 3. Resource copy assignment end **********"<<std::endl;

        return *this ;
    }

    void print()
    {
        for(unsigned i;i<m_length;++i)
        {
            std::cout << m_data[i] <<" " ;     
        }
        std::cout <<std::endl;
    }

    ~Resource();


};
