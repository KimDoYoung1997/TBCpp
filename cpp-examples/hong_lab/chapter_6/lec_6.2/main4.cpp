#include <iostream>
#include <cstdint>

using namespace std;

void doSomething(int students_scores[]) // pointer 
{
    cout << "----------doSomething() -------------------------------" << endl;
    cout << "Address of students_scores (in doSomething): " << reinterpret_cast<uintptr_t>(students_scores) << endl;
    // ... (other code)
}

int main()
{
    const int num_students = 20;
    int students_scores[num_students] = {1, 2, 3, 4, 5};

    cout << "----------main() -------------------------------" << endl;
    cout << "Address of students_scores (in main): " << reinterpret_cast<uintptr_t>(students_scores) << endl;
    // ... (other code)

    doSomething(students_scores);

    return 0;
}
