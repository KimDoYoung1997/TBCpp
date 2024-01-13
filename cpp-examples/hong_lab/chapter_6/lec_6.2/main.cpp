#include <iostream>
#include <cstdint>

using namespace std;



int main()
{
    const int num_students = 20;
    int students_scores[num_students];

    cout << sizeof(students_scores) << endl;
/*  
    cout << &students_scores << endl;
    cout << (int)&(students_scores[0]) << endl;
    cout << (int)&(students_scores[1]) << endl;
    cout << (int)&(students_scores[2]) << endl;
    cout << (int)&(students_scores[3]) << endl;
    cout << (int)&(students_scores[4]) << endl;

    cout << sizeof(students_scores) << endl;

 */

    cout << reinterpret_cast<uintptr_t>(&students_scores) << endl; // 140725731554592
    cout << reinterpret_cast<uintptr_t>(&students_scores[0]) << endl; // 140725731554592
    cout << reinterpret_cast<uintptr_t>(&students_scores[1]) << endl; //140725731554596
    cout << reinterpret_cast<uintptr_t>(&students_scores[2]) << endl; //140725731554600
    cout << reinterpret_cast<uintptr_t>(&students_scores[3]) << endl; //140725731554604

     
    cout << reinterpret_cast<uintptr_t>(&students_scores[19]) << endl; //140725731554604
    cout << reinterpret_cast<uintptr_t>(&students_scores[2000000000000]) << endl; //140725731554604


    return 0;
}
