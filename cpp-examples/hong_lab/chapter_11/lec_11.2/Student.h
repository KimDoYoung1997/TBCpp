#pragma once
#include "Person.h"
//#include <iostream>
//#include <ostream>
// #include <string>  자식클래스는 부모클래스를 include하기떄문에 없어도 됨

class Student : public Person
{
private:
    // std::string m_name;
    int m_intel;    // Student 클래스만 가지고 있는 고유의 특성

public:
    Student(const std::string& name_in="No Name" , const int& intel_in=0):Person(name_in),m_intel(intel_in)
    {
        std::cout <<"Student Constructor" << std::endl;
        this->getName();
    }
    // void setName(const std::string &name_in)
    // {
    //     m_name= name_in;
    // }
    // std::string getName() const
    // {
    //     return m_name;
    // }

    void setIntel(const int& intel_in) // Student 클래스만 가지고 있는 고유의 특성
    {
        m_intel = intel_in;
    }

    int getIntel() const    // Student 클래스만 가지고 있는 고유의 특성
    {
        return m_intel;
    }

    friend std::ostream &operator<<(std::ostream& out, const Student& student)
    {
        // out << Student.m_name << " " << Student.m_intel << std::endl;
        out << student.getName() << " " << student.m_intel << std::endl;

        return out;
    }   

};