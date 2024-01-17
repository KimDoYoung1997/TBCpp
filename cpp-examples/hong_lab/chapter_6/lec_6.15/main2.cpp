#include <cstdint>
#include <iostream>
using namespace std;


void doSomething(const int x)
{
    cout<<"doSomething in"<< endl;
    cout << x << endl;
    cout <<(uintptr_t)&x<<endl;
}

void doAnother(const int& x)
{
    cout<<"doAnother in"<< endl;
    cout << x << endl;
    cout <<(uintptr_t)&x<<endl;}

void doOther(int x)
{
    cout<<"doOther in"<< endl;

    cout << x << endl;
    cout <<(uintptr_t)&x<<endl;}

void doLast(int&x)
{
    cout<<"doLast in"<< endl;
    cout << x << endl;
    cout <<(uintptr_t)&x<<endl;}
int main()
{
    int x = 5;
    int &ref_x = x;

    cout << (uintptr_t)&x << endl;


    //doSomething(5);
    doSomething(ref_x);
    doAnother(ref_x);
    doAnother(3+5);
    //doAnother(100);
    //doOther(5);
    //doLast(11);
    cout <<"------------main end-----------" << endl;
    cout << x << endl;

    return 0;
}