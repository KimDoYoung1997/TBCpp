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
        //students 벡터의 0번째 원소의 주소값인 &students[0] 과 student_in 의 주소값은 서로 다르다. vector가 push back을 하면 복사하기 때문. 
        //students.push_back(student_in);
        /*
        push_back 메서드는 벡터의 끝에 새 요소를 추가합니다. 만약 추가하는 요소(student_in 인스턴스)가 L-value라면, push_back은 해당 요소의 복사본을 만들어 벡터의 끝에 저장합니다. 
        따라서, 원본 객체(student_in)와 벡터 내에 저장된 객체의 메모리 주소는 서로 다릅니다.
        */
        
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