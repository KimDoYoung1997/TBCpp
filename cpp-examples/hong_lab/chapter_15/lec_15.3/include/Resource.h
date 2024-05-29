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
    Resource & operator=(const Resource & copy)
    {
        std::cout<<"********** Resouce copy assignment **********"<<std::endl;
        if(&copy == this)
        {
            return *this;
        }

        if(m_data !=nullptr) delete[] m_data;
        std::cout<<"********** Resouce copy assignment end **********"<<std::endl;

        m_data = new int(copy.m_length);
            std::cout<<"********** Resouce copy assignment end **********"<<std::endl;

        m_length = copy.m_length;

        for (unsigned i=0;i<m_length;i++)
        {
            m_data[i] = copy.m_data[i];
        }
        std::cout<<"********** Resouce copy assignment end **********"<<std::endl;

        return *this ;
    }

    void print()
    {
        for(unsigned i;i<m_length;i++)
        {
            std::cout << m_data[i] <<" " ;     
        }
        std::cout <<std::endl;
    }

    ~Resource();


};
