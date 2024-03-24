/*
동적 바인딩과 정적 바인딩
*/

#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x+y;
}

int subtract(int x, int y)
{
    return x-y;
}


int multiply(int x, int y)
{
    return x*y;
}




int main()
{
    int x, y;

    cin>> x >> y;

    int op;
    cout <<"0 : add, 1 : subract, 2 : multiply" << endl;

    cin >>op;

    // static binding (early binding) : 모든 변수명이나 함수 이르들이 깔끔하게 빌드 타임에 정리가 되어 있는 것을 static binding 이라고 합니다.
    int result;
    switch(op)
    {
    case 0: result = add(x,y) ;break;
    case 1: result = subtract(x,y); break;
    case 2: result = multiply(x,y); break;
    }

    cout << result << endl;

    return 0;
}