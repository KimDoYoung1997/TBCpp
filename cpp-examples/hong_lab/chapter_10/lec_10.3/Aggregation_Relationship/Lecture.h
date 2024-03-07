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

    // 포인터를 사용함으로서 구성 관계 돌입. Lecture 클래스의 instance가 사라지더라도 teacher 포인터가 가르키고 있는 값은 남아있음
    Teacher* m_teacher;
    // 포인터를 사용함으로서 구성 관계 돌입. Lecture 클래스의 instance가 사라지더라도 아래 벡터 각 원소값이 가르키는 값은 남아있음
    std::vector<Student*> students;
public:
    Lecture(const std::string& name_in):m_name(name_in)
    {}

    ~Lecture()
    {
        //do NOT delete teacher even if Lecture is deleted.
        //do NOT delete student even if Lecture is deleted.
    }


    void assignTeacher(Teacher* const teacher_in)       //teacher_in 의 주소값을 안 바꾸기 위해 const를 붙임
    {
        m_teacher = teacher_in;
    }

    void registerStudent(Student* const student_in)     //student_in 학생 원소값은 바꾸지 않기 위해서 const를 붙임
    {
        students.push_back(student_in);              //벡터의 각 원소에 각 학생의 주소값을 복사(copy)한다.        
    }

    void study()
    {
        for(auto& student:students)
        {
            //registerStudent 메소드에 의해서 students 벡터로 학생들의 주소값을 벡터에 복사해놨다.
            // * 역참조를 이용해 각 학생의 instance 를 통해 setIntel함수를 호출한다.
            
            // 방법 1 : 
            //(*student).setIntel((*student).getIntel()+1);       
            
            // 방법 2 :
            student->setIntel(student->getIntel()+1);
        }
    }

    friend std::ostream& operator <<(std::ostream& out,Lecture lecture)
    {
        out <<"Lecture name: "<< lecture.m_name << std::endl; // 강의 이름
        out <<*(lecture.m_teacher) << std::endl;
        for(auto& student : lecture.students)
        {
            out << *student<< std::endl;
        }
        return out;
    }


};