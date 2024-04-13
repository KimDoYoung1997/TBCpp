#pragma once
#include <iostream>
template<typename T>
class Storage
{
private:
    T m_value;
public:
    Storage(T value):m_value(value)
    {

    }

    ~Storage()
    {

    }

    void print()
    {
        std::cout <<m_value <<'\n';
    }

};

//double 타입에 대한 템플릿 멤버함수의 특수화
// template<>
// void Storage<double>::print()
// {
//     std::cout <<"Double Type ";
//     std::cout <<std::scientific << m_value<<'\n';
// }