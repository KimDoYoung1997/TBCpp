#include <iostream>

using namespace std;


void print(int x =0)
{
    cout << x << endl;
}

void print2(int x = 1024, int y=109, int z =73 )
{
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

void print3(int x = 1024, int y=109, int z =73 );

void print3(int x, int y ,int z)
{
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}


void print4(int x, int y ,int z);
void print4(int x = 1024, int y=109, int z =73)
{
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

void print5(int x , int y, int z );

void print5(int x, int y ,int z)
{
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}


int main()
{

    print(10);
    print();

    print2(100);
    print2(100,200);

    return 0;
}