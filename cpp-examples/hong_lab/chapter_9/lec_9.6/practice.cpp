#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;

public:
    BoundCheckIntArray(int len): arrlen(len)
    {
        cout <<"Constructor"<< endl;
        arr = new  int[len];
    }

    int & operator[](int index) // 반환형이 & 참조형
    {
        if( (index<0) || (index>arrlen) ) // 참고로 이렇게 if로 배열의 범위를 벗어난 원소 접근에 대한 방지보단, assert를  사용하는것이 더 효율적이다. 이는 main3.cpp를 참고하면 된다.
        {
            cout <<"Array index out of bound exception" << endl;
            exit(1);
        } 
        return arr[index]; // int& temp= arr[index] 

    }


    ~BoundCheckIntArray()
    {
        cout <<"Destructor"<< endl;
        delete[] arr;
    }

};

int main()
{
    BoundCheckIntArray arr(5);
    for (unsigned int i=0;i<5;i++)
    {
        arr[i]=(i+1)*11; // operator[] 함수의 반환형이 참조형이라 역참조 및 값 변경이 가능하다.
        cout << arr[i]<<" ";
    }cout << endl;

    arr[2] = 100; // operator[] 함수의 반환형이 참조형이라 역참조 및 값 변경이 가능하다.

    for(int i=0; i<5;i++)
    {
        cout <<arr[i]<<" " ; 
    }cout << endl;
    return 0;
}