#include "PointTemplate.h"

template<typename T>
Point<T>::Point(T x, T y):xpos(x),ypos(y)
{}

template<typename T>
void Point<T>::ShowPosition() const
{
    cout <<"["<<xpos <<", "<<ypos <<"]"<<endl;
}


// 특정 타입에 대하
template class Point<int>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
template class Point<double>;	// 해당 부분을 통해 explicit instanciation이  발동되고, 헤더와 cpp변환이 가능해진다.
