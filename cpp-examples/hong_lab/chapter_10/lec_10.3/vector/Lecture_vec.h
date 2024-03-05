/*
 이 클래스는 강의 이름(m_lec_name)을 멤버 변수로 가지며, std::vector<Student>를 사용하여 여러 Student 객체를 관리합니다. 
 생성자에서는 강의 이름을 설정하고, registerStudent 함수를 통해 학생을 등록합니다. 
 study 함수는 등록된 모든 학생의 지능을 증가시키는 기능을 수행합니다. 
 소멸자에서는 객체의 소멸을 알리는 메시지를 출력합니다. 
 마지막으로, operator<< 함수는 강의의 이름을 출력하는 기능을 제공하여 Lecture 객체의 정보를 쉽게 로깅하거나 디버깅할 수 있도록 합니다.
*/
#pragma once // 중복 include 방지
#include "Teacher.h" // Teacher 클래스 포함
#include "Student.h" // Student 클래스 포함
#include <iostream> // 표준 입출력을 위한 헤더
#include <vector> // std::vector 컨테이너 사용을 위한 헤더

// Lecture 클래스 정의
class Lecture 
{
private:
    std::string m_lec_name; // 강의 이름
    std::vector<Student> m_lec_students; // Student 객체들을 저장하는 벡터
    Teacher* teacher_ptr;
public:
    // 생성자: 강의 이름을 인자로 받아 초기화
    Lecture(const std::string lec_name) : m_lec_name(lec_name) , teacher_ptr(nullptr)
    {
        //std::cout << "Lecture 생성" << std::endl; // 생성자 호출 시 메시지 출력
    }

    // 선생님 할당 함수 (현재는 빈 구현)
    void assignTeacher(const Teacher& teacher) 
    {
        // 여기에 선생님 할당 로직 구현
        if (teacher_ptr!=nullptr)
        {
            std::cout<<"teacher should be 1"<< std::endl;
            exit(1);
        }
        teacher_ptr = new Teacher(teacher);

        

    }

    // 학생 등록 함수: Student 객체를 벡터에 추가
    void registerStudent(const Student& student) 
    {
        m_lec_students.emplace_back(student); // 벡터에 학생 객체 추가
        //std::cout << "Student 할당" << std::endl; // 학생 객체가 할당되었음을 알림
    }

    // 학습 함수: 등록된 모든 학생의 지능을 증가시킴
    void study() 
    {
        std::cout<<m_lec_name<<" Study"<<std::endl;
        for (Student& student : m_lec_students) {
            //student.getStudentName();
            student.addIntelligence(); // 각 학생의 지능 증가 함수 호출
        }
    }

    // 소멸자: 객체 소멸 시 메시지 출력
    ~Lecture() 
    {
        //std::cout << "Lecture 소멸" << std::endl;
        delete teacher_ptr;
    }

    // 출력 연산자 오버로딩: Lecture 객체의 정보를 출력
    friend std::ostream& operator<<(std::ostream& out, Lecture& lecture) {
        out <<"Lecture name: "<< lecture.m_lec_name << std::endl; // 강의 이름 출력
        out << *(lecture.teacher_ptr)<<std::endl;
        for(Student& student : lecture.m_lec_students)
        {
            out <<student<<std::endl;
        }
        return out;
    }
};
