#include "PointTemplate.h"
// #include "PointTemplate.cpp" // 템플릿 클래스에서, header와 definition파일을 나눌때 문제가 생긴다. 이때 그냥 definition의 cpp파일을 include하면 문제가 해결됨
int main()
{
    Point<int> pos_int(3,5);
    pos_int.ShowPosition();

    Point<double> pos_double(3.3,5.5);
    pos_double.ShowPosition();
    
    return 0;
}

