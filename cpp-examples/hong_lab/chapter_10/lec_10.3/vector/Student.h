#pragma once

#include <iostream>
#include <string>

class Student
{
private:
    std::string m_name;
    int m_intelligence;
public:
    Student( std::string name, const int& intelligence):m_name(name),m_intelligence(intelligence)
    {}

    void setStudent(int& intelligence)
    {
        m_intelligence=intelligence;
    }
    void getStudentName(void)
    {
        std::cout << m_name <<std::endl;
    }
    void addIntelligence()
    {
        m_intelligence+=1;
    }

    friend std::ostream& operator <<(std::ostream& out, Student& student)
    {
        out << student.m_name <<" " << student.m_intelligence ;
        return out;
    }

};