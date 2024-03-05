#pragma once
#include <ostream>
#include <string>
#include <iostream>
class Teacher
{
private:
    std::string m_name;
    //TODO: more members like home address, salary, age, evaluation, etc
public:
    Teacher(const std::string& name_in="No Name"):m_name(name_in)
    {}

    void setName(const std::string& name_in)
    {
        m_name = name_in;
    }
    std::string getName()
    {
        return m_name;
    }

    friend std::ostream& operator <<(std::ostream& out,Teacher teacher)
    {
        out << teacher.m_name ;
        return out;
    }

};