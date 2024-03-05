
#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"
#include "Student.h"
#include "Teacher.h"



int main()
{
    // Composition Relationship 
    Teacher teach1("hong");

    // Lecture class을 바탕으로 lec1 object 생성
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(Teacher("Prof. Hong"));
    lec1.registerStudent(  Student("Jack Jack",0)); //19번째 Jacj Jack이랑 25번째줄 Jack Jack이랑 서로 주소가 다르다(다른 객체이다.)
    lec1.registerStudent(  Student("Dash",1));
    lec1.registerStudent(  Student("Violet",2));

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(Teacher("Prof. Good"));
    lec2.registerStudent(Student("Jack Jack",0));   //19번째 Jacj Jack이랑 25번째줄 Jack Jack이랑 서로 주소가 다르다(다른 객체이다.)


    {
        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;
    
        lec2.study();

        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;    
    }


    return 0;
}