#include <iostream>
#include <assert.h> // for assert
#include "MyArray.h"

template<typename T>
MyArray<T>::MyArray(): m_length(0), m_data(nullptr) {}

template<typename T>
MyArray<T>::MyArray(int length): m_length(length), m_data(new T[length]) {}


template<typename T>
MyArray<T>::~MyArray() 
{
    reset();
    std::cout << "Memory delete completed" << std::endl;
}

template<typename T>
void MyArray<T>::reset()
{
    if (m_data != nullptr) 
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
}


template<typename T>
T& MyArray<T>::operator[](int index) 
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

template<typename T>
int MyArray<T>::getLength() const 
{
    return m_length; 
}

template<typename T>
void MyArray<T>::print() 
{
    for (int i = 0; i < m_length; i++) {
        std::cout << m_data[i] << " " << std::endl;
    }
}

//template void MyArray<int>::print();

template class MyArray<int>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
template class MyArray<double>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
template class MyArray<char>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
