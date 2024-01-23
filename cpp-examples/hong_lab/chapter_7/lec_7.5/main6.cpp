#include <iostream>
#include <array>
using namespace std;

struct Student{
    int a,b,c,d;
};

 Student getStruct()
{
    Student my_s{1,2,3,4};
    return my_s;
}


int main()
{
    struct Student my_s = getStruct(); // deep copy. copy all values
    my_s.a = 0;

    cout << my_s.a << endl;

    return 0;
}