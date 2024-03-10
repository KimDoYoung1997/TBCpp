#pragma once
#include "Person.h"
// #include <iostream> 자식클래스는 부모클래스를 include하기떄문에 없어도 됨
// #include <string> 자식클래스는 부모클래스를 include하기떄문에 없어도 됨

class Teacher : public Person
{
private:
    // std::string m_name;
public:
    Teacher(const std::string& name_in="No Name"):Person(name_in)
    {
        std::cout <<"Teacher Constructor" << std::endl;
        this->getName();
    }

    // void setName(const std::string name_in)
    // {
    //     m_name=name_in;
    // }

    // std::string getName()
    // {
    //     return m_name;
    // }

    friend std::ostream &operator<<(std::ostream& out, const Teacher& teacher)
    {
        // out << Student.m_name << " " << Student.m_intel << std::endl;
        out << teacher.getName() << std::endl;

        return out;
    }   

};