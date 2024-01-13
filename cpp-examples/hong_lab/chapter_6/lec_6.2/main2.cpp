#include <iostream>
#include <cstdint>

using namespace std;

void doSomething (int students_scores[20]) // pointer 
{


    cout <<"----------doSomething() -------------------------------"<<endl;
    cout << reinterpret_cast<uintptr_t>(students_scores) << endl; //140728825718608
    cout << reinterpret_cast<uintptr_t>(&students_scores) << endl; //140728825718568 // pointer
    cout << reinterpret_cast<uintptr_t>(&students_scores[0]) << endl; //140728825718608
    cout << reinterpret_cast<uintptr_t>(&students_scores[1]) << endl; //140728825718612
    cout << reinterpret_cast<uintptr_t>(&students_scores[2]) << endl; //140728825718616

    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

    cout <<"Size of in doSomething : " << (int)sizeof(students_scores) << endl;
    cout <<"----------doSomething() -------------------------------"<<endl;




}


int main()
{
    const int num_students = 20;
    int students_scores[num_students] = {1,2,3,4,5,};

    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;

    cout <<"----------main() -------------------------------"<<endl;
    cout <<"Size of in main : " << sizeof(students_scores) << endl;

    cout << reinterpret_cast<uintptr_t>(students_scores) << endl; //140728825718608
    cout << reinterpret_cast<uintptr_t>(&students_scores) << endl; //140728825718608
    cout << reinterpret_cast<uintptr_t>(&students_scores[0]) << endl; //140728825718608
    cout << reinterpret_cast<uintptr_t>(&students_scores[1]) << endl; //140728825718612
    cout << reinterpret_cast<uintptr_t>(&students_scores[2]) << endl; //140728825718616
    cout << "Size in main" << (int)(sizeof(students_scores)) << endl;
    cout <<"----------main() -------------------------------"<<endl;


    doSomething(students_scores);


    return 0;
}
