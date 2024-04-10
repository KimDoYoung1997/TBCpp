#pragma once
#include <ios>
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

template<>
void Storage<double>::print()
{
    std::cout <<"Double Type ";
    std::cout <<std::scientific << m_value<<'\n';
}