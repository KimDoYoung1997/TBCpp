#pragma once
#include "Teacher.h"
#include "Student.h"
#include <iostream>

class Lecture
{
private:
    std::string m_lec_name;
    Student* m_lec_student;
public:
    Lecture(const std::string lec_name):m_lec_name(lec_name),m_lec_student(nullptr)
    {
        std::cout<<"생성" << m_lec_student <<std::endl;
    }

    void assignTeacher(const Teacher& teacher)
    {
        
    }    

    void registerStudent(const Student& student)
    {
        if (m_lec_student != nullptr) 
        {
            std::cout<<"직접 제거"<<m_lec_student<<std::endl;
            delete m_lec_student;
        }
        m_lec_student = new Student(student);
        std::cout<<"할당" << m_lec_student <<std::endl;
    }

    void study()
    {
        m_lec_student->addIntelligence();
    }

    ~Lecture()
    {
        std::cout <<"소멸"<< m_lec_student <<std::endl;

        delete m_lec_student;
        m_lec_student = nullptr;
    }

    friend std::ostream& operator <<(std::ostream& out, Lecture &lecture)
    {
        out << lecture.m_lec_name<<std::endl;
        
        return out;
    }

};
