#pragma once

#include <iostream>
#include <string>

class Teacher
{
private:
    std::string m_name;
public:
    Teacher(std::string name):m_name(name)
    {}

    void setTeacher(std::string name)
    {
        m_name=name;
    }


    friend std::ostream& operator <<(std::ostream& out, Teacher& teacher)
    {
        out << teacher.m_name ;
        return out;
    }

};