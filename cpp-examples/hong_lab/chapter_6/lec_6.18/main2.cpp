#include <cstdint>
#include <iostream>

using namespace std;


// void pointer, generic pointer
enum Type
{
    INT,
    FLOAT,
    CHAR,
};



int main()
{
    int i = 5;
    float f = 3.0;
    char c = 'a';

    void *ptr = nullptr;

    ptr = &i ;
    ptr = &f ;
    //ptr = &c ;    



    Type type = FLOAT ;


    cout << &f <<" " << ptr << endl;

    if (type == FLOAT)
    {
        cout <<"Welcome float pointer" << endl;
        cout << *static_cast<float*>(ptr) << endl;
    }
    else if (type == INT)
    {
        cout <<"Welcome int pointer" << endl;
        cout << *static_cast<int*>(ptr) << endl;

    }


    return 0;
}