/*
여러가지 자료형에 대해 거의 비슷한 코드를 반복해서 작성하는 것을 방지해준다.

두 수의 대소비교를 해주는 코드
*/

#include <iostream>

using namespace std;

int getMax(int x, int y)
{
    return (x > y)? x : y;
}

double getMax(double x, double y)
{
    return (x > y)? x : y;
}

float getMax(float x, float y)
{
    return (x > y)? x : y;
}



int main()
{
    return 0;
}