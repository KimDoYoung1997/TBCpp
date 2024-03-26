#include <iostream>
#include <assert.h> // for assert
#include "MyArray.h"

//생성자
MyArray::MyArray():m_length(0),m_data(nullptr)
{}
//생성자 오버라이딩
MyArray::MyArray(int length):m_length(length)
{
    m_data = new int[length];
}

// 소멸자
MyArray::~MyArray()
{
    reset();
    std::cout <<"Memory delete completed" << std::endl;
}

// reset 함수 정의
void MyArray::reset()
{
    if (m_data != nullptr);
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
}

// [] 연산자 오버로딩 정의
int& MyArray::operator[](int index) // std 안써도 되나?
{
    assert(index >=0 && index < m_length);
    return m_data[index];
}
// getLength 함수 정의
int MyArray::getLength()
{
    return m_length;
}

// print 함수 정의
void MyArray::print()
{
    for (int i=0;i<m_length;i++)
    {
        std::cout <<m_data[i] <<" " << std::endl;
    }
}