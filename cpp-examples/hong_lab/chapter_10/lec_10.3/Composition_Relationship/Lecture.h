#pragma once

#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <string>
#include <vector>

class Lecture
{
private:
    std::string m_name;

    //Lecture 클래스의 instance가 사라질때, 아래의 teacher, students도 함께 소멸된다. 이는 구성관계의 특징이다.
    Teacher teacher;
    std::vector<Student> students;
public:
    Lecture(const std::string& name_in):m_name(name_in)
    {}

    ~Lecture()
    {
        //do NOT delete teacher even if Lecture is deleted.
        //do NOT delete student even if Lecture is deleted.
    }


    void assignTeacher(const Teacher& teacher_in)
    {
        teacher = teacher_in;
    }

    void registerStudent(const Student& student_in)
    {
        students.push_back(student_in);
    }

    void study()
    {
        for(Student& student:students)
        {
            student.setIntel(student.getIntel()+1);
        }
    }

    friend std::ostream& operator <<(std::ostream& out,Lecture lecture)
    {
        out <<"Lecture name: "<< lecture.m_name << std::endl; // 강의 이름
        out <<lecture.teacher << std::endl;
        for(Student& student : lecture.students)
        {
            out << student<< std::endl;
        }
        return out;
    }


};