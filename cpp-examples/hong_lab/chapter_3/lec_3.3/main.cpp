#include <iostream>

int add(int a , int b)
{
    return a+b;
}

int main()
{
    using namespace std;

    int x=1 , y =2;
    int v = add(x,y++);
    cout <<"x: "<<x<<" y: "<<y<<endl;
    cout <<v<<endl;

    int z = 0;
    z++;
    cout <<z<<endl;
    cout <<z<<endl;


    return 0;
}