#include <iostream>
#include "include/Resource.h"
using namespace std;


Resource::Resource()
{
    std::cout <<"============= Resource default constructor =============" << std::endl;
}

Resource::Resource(unsigned length)
{
    std::cout <<"============= Resource(unsigned length) constructor =============" << std::endl;
    this->m_length = length;
    this->m_data= new int(length);
    std::cout <<"Resource m_data addr :" <<this->m_data << endl;
    std::cout <<"Resource length :" <<this->m_length << endl;

    std::cout <<"============= Resource(unsigned length) constructor end =============" << std::endl;

}
// 복사 생성자
Resource::Resource(const Resource& copy)
{
    std::cout <<"============= Resource(const Resource& copy) copy constructor =============" << std::endl;
    // Resource(copy.m_length);
    std::cout <<"m_length" << m_length << std::endl;
    for (unsigned i = 0;i<this->m_length ; i++)
    {
        this->m_data[i] = copy.m_data[i];   // 복사생성자를 통해, 기존에 있는 데이터값을 다 옮긴다.
    }

    // // this->m_length = copy.m_length;

    // // deep-copy
    // this->m_data= new int(copy.m_length);   // 새로운 메모리주소를 할당하고
    // for (unsigned i = 0;i<this->m_length ; i++)
    // {
    //     this->m_data[i] = copy.m_data[i];   // 복사생성자를 통해, 기존에 있는 데이터값을 다 옮긴다.
    // }
    // std::cout <<"copy_cstr addr :" <<this->m_data << endl;
}

Resource::~Resource()
{
    std::cout <<"============= Resource destructed start =============" << std::endl;
    if(this->m_data != nullptr)
    {
        std::cout <<"Resource Memory de-allocated! "<<this->m_data<<std::endl;
        delete[] this->m_data;
        // m_data = nullptr;
        // std::cout <<"Memory de-allocated finished! "<<this->m_data<<std::endl;

    }
    std::cout <<"============= Resource destructed end =============" << std::endl;

}

void Resource::setAll(const int& v)
{
    for(unsigned i=0;i<m_length;i++)
    {
        m_data[i] = v;
    }
}