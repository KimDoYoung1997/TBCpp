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


    // dynamic binding (late binding) 
    //function pointer declaration 은  return타입(*포인터변수이름)(입력인자1,입력인자2) 방식으로 선언
    int(*func_ptr)(int,int)=nullptr;  

    // runtime에 func_ptr에 할당될 함수가 결정됨
    switch (op) 
    {
    case 0: func_ptr = add; break;
    case 1: func_ptr = subtract; break;
    case 2: func_ptr = multiply; break;
    }

    cout << func_ptr(x,y)<<endl;
    return 0;
}