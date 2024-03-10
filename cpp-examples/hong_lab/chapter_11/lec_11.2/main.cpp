#include "Student.h"
#include "Teacher.h"
//include "Person.h"
int main()
{
    Student std1("Jack Jack ");
    std1.setName("DY Kim ");
    std::cout << std1.getName()<< std::endl;
    Teacher teacher1("Dr. H ");

    std1.doNothing();
    teacher1.doNothing();
    return 0;
}