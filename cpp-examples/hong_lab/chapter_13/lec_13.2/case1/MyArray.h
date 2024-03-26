#pragma once 
#include <iostream>
#include <assert.h> // for assert

class MyArray 
{
private:
    int m_length;
    int *m_data;
public:
    MyArray();

    MyArray(int length);

    ~MyArray();

    void reset();

    int& operator[](int index); 

    int getLength();

    void print();

};
