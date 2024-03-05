/*
https://chat.openai.com/share/dd24ec72-3068-4507-8fb9-e7bf981d09ef
*/

#include <iostream>
#include <vector>
#include <string>
#include "Lecture_vec.h"
#include "Student.h"
#include "Teacher.h"



int main()
{
    // Composition Relationship 
    Teacher teach1("hong");
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(Teacher("Prof. Hong"));
    lec1.registerStudent(  Student("Jack Jack",0));
    lec1.registerStudent(  Student("Dash",1));
    lec1.registerStudent(  Student("Violet",2));

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(Teacher("Prof. Good"));
    lec2.registerStudent(Student("Jack Jack",0));


    {
        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;
    
        lec2.study();

        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;    
    }


    return 0;
}