#pragma once 
#include <iostream>
#include <assert.h> // for assert

template<typename T>
class MyArray 
{
private:
    int m_length;
    T* m_data;
public:
    MyArray();
    
    MyArray(int length);
    
    ~MyArray();

    void reset() ;

    T& operator[](int index);

    int getLength() const ;

    void print();
};

