#include <iostream>

using namespace std;

typedef int my_int;

void print(int x)
{
    cout <<"1. "<< x << endl;
}

void print(char x)
{
    cout <<"2. "<< x << endl;
}
// //Redefinition of print
// void print(my_int x)
// {

// }

void print(const char* x)
{
    cout <<"3. "<< x << endl;
}

void print(char x[])
{
    cout <<"4. "<< x << endl;
}

int main()
{

    int x = 4;
    print(x);

    int x_ = 'a';
    print(x_);


    char x__ = 'a';
    print(x__);

    const char* x___ = "a";
    print(x___);


    char x____[] = "a";
    print(x____);


    return 0;
}