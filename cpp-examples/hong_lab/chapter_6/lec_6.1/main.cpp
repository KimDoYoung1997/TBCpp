#include <iostream>

using namespace std;

int main()
{

    int one_student_score; // 1 variable
    int student_scores[5]; // 5 int


    cout <<"one_student_score memory size : " << sizeof(one_student_score) << endl; // 4 bytes
    cout <<"student_scores memory size : " << sizeof(student_scores) << endl; // 20 bytes = 4 * 5 


    one_student_score = 100;
    student_scores[0] = 100; //1st element
    student_scores[1] = 80; //2nd element
    student_scores[2] = 90; //3rd element
    student_scores[3] = 50; //4th element
    student_scores[4] = 0; //5th element
    //student_scores[5] = 100;


     

    cout << student_scores[5] << endl; //6th element
    cout << "This is over flow of array!"<<endl;
/* 
    int jackjack_score ;
    int dash_score ;
    int violet_score;

 */


    return 0;
}