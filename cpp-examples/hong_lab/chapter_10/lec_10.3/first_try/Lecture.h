#pragma once

//Lecture.h 헤더파일에서 다른 나머지 헤더파일도 include한다.
#include "Teacher.h"
#include "Student.h"
#include <iostream>
#include <vector>
class Lecture
{
private:
    std::string m_lec_name;
    // 멤버변수로 동적할당변수가 있다면, 대입 연산자 오버로딩과, 복사생성자에 주의해야함
    std::vector<Student> m_lec_student;
public:
    Lecture(const std::string lec_name):m_lec_name(lec_name)
    {
        //std::cout<<"생성" << m_lec_student <<std::endl;
    }

    void assignTeacher(const Teacher& teacher)
    {
        //ToDo
    }    

    void registerStudent(const Student& student)
    {
        // if (m_lec_student != nullptr) 
        // {
        //     //std::cout<<"직접 제거"<<m_lec_student<<std::endl;
        //     delete m_lec_student;
        // }
        m_lec_student.push_back(student);
        
        //std::cout<<"할당" << m_lec_student <<std::endl;
    }

    void study()
    {
       for (Student& student: m_lec_student)
       {
        student.addIntelligence();
       }
    }

    ~Lecture()
    {
        //std::cout <<"소멸"<< m_lec_student <<std::endl;

        //m_lec_student = nullptr;
    }

    friend std::ostream& operator <<(std::ostream& out, Lecture &lecture)
    {
        out <<"Lecture name : "<< lecture.m_lec_name<<std::endl;
        for(Student& student : lecture.m_lec_student)
        {
            out <<student<<std::endl;
        }
        return out;
    }

};

 