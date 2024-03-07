#pragma once
#include <ostream>
#include <string>
#include <iostream>

class Student
{
private:
    std::string m_name;
    int m_intel;
public:
    Student(const std::string& name_in="No Name", const int& intel_in=0):m_name(name_in), m_intel(intel_in)
    {}

    void setName(const std::string& name_in)
    {
        m_name = name_in;
    }

    int getIntel()
    {
        return m_intel;
    }

    void setIntel(const int& num_in)
    {
        m_intel = num_in;
    }

    friend std::ostream& operator << (std::ostream& out, Student student)
    {
        out <<student.m_name <<" "<< student.m_intel;
        return out;
    }
};