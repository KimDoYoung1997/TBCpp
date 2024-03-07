
#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"
#include "Student.h"
#include "Teacher.h"



int main()
{
    // Composition Relationship 
    Teacher teach1("Prof. Hong");
    Teacher teach2("Prof. Good");
    Student std1("Jack Jack",0);
    Student std2("Dash",1);
    Student std3("Violet",2);
    // Lecture class을 바탕으로 lec1 object 생성
    Lecture lec1("Introduction to Computer Programming");

    // 이렇게 주소값을 인자로 전달하면, lec1 객체가 소멸되더라도, teach1의 주소값은 존재함
    lec1.assignTeacher(&teach1);
    lec1.registerStudent(&std1); 
    lec1.registerStudent(&std2);
    lec1.registerStudent(&std3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(&teach2);
    lec2.registerStudent(&std1);   


    {
        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;
    
        lec2.study();

        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;    
    }


    return 0;
}