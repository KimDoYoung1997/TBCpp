#pragma once 
#include <iostream>
#include <assert.h> // for assert

const int template_array_size = 100;


template<typename T,unsigned int T_SIZE>
class MyArray 
{
private:
    //int m_length;
    T* m_data;
public:
    MyArray();


    // MyArray(int length);
    
    ~MyArray();

    void reset() ;

    T& operator[](int index);

    int getLength() const ;

    void print();
};

