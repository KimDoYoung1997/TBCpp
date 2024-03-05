#pragma once

#include <ostream>
#include <string>

class Teacher
{
private:
    std::string m_name;
public:
    Teacher(std::string name):m_name(name)
    {}

    void setTeacher(int& intelligence)
    {
        m_name=intelligence;
    }

    friend std::ostream& operator <<(std::ostream& out, Teacher& teacher)
    {
        out << teacher.m_name ;
        return out;
    }

};