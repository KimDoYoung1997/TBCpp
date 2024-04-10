#include <iostream>
#include <assert.h> // for assert
#include "MyArray.h"

template<typename T, unsigned int T_SIZE>
MyArray<T,T_SIZE>::MyArray()
{
    m_data = new T[T_SIZE];
}

// MyArray<T>::MyArray(): m_length(0), m_data(nullptr) {}


// template<typename T>
// MyArray<T>::MyArray(int length): m_length(length), m_data(new T[length]) {}


template<typename T,unsigned int T_SIZE>
MyArray<T,T_SIZE>::~MyArray() 
{
    reset();
    std::cout << "Memory delete completed" << std::endl;
}

template<typename T, unsigned int T_SIZE>
void MyArray<T,T_SIZE>::reset()
{
    if (m_data != nullptr) 
    {
        delete[] m_data;
        m_data = nullptr;
        // T_SIZE = 0;
        // m_length = 0;
    }
}


template<typename T, unsigned int T_SIZE>
T& MyArray<T,T_SIZE>::operator[](int index) 
{
    assert(index >= 0 && index < T_SIZE);
    return m_data[index];
}

template<typename T , unsigned int T_SIZE>
int MyArray<T,T_SIZE>::getLength() const 
{
    return T_SIZE; 
}

template<typename T , unsigned int T_SIZE>
void MyArray<T,T_SIZE>::print() 
{
    for (int i = 0; i < T_SIZE; i++) {
        std::cout << m_data[i] << " " << std::endl;
    }
}

//template void MyArray<int>::print();

template class MyArray<int,template_array_size>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
template class MyArray<double,template_array_size>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
template class MyArray<char,template_array_size>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
