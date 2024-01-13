#include <iostream>

using namespace std;


enum StudentName
{
    JACKJACK,   //0
    DASH,       // 1
    VIOLET,     // 2
    NUM_STUDENTS // 3
};





int main()
{
    //1.  int my_array[5] = {1,2,3,4,5}; // array initialization
    //2.  int my_array[5] = {2,1,}; // array initialization
    //3.  int my_array[] = {1,2,3,4,5}; // automatically assign the size of array by using right 
    int my_array[] {1,2,3,4,5}; // it is similiar with uniform initialization




    cout << my_array[JACKJACK] << endl;
    cout << my_array[DASH] << endl;
    cout << my_array[VIOLET] << endl;



    int students_scores[NUM_STUDENTS];
    students_scores[JACKJACK] = 0 ;
    students_scores[DASH] = 100;
    students_scores[VIOLET] = 90;


    const int num_students = 5;
    int student_scores[num_students];

    

    return 0;
}