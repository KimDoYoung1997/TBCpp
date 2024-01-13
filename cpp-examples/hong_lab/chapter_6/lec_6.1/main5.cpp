#include <iostream>

using namespace std;


int main()
{
    int num_students = 0;
    cin >> num_students ;

    int student_scores[num_students];

    // Intentional overflow. 
    cout << student_scores[3] << endl;

    //const int num_students = 5;
    //int student_scores[num_students];

    

    return 0;
}