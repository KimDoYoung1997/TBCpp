#pragma once
// #include "Monster.h"
#include <iostream>

/*
Position2D class의 특성은 다음과 같다.
<멤버변수>
    1. 몬스터의 x위치
    2. 몬스터의 y위치
<멤버함수>
    1. set 오버로딩함수 2개
    2. get 함수
<오버로딩>
    1. operator<<
*/
class Position2D
{
private:
    int m_x;    //location x
    int m_y;    //location y
public:
    Position2D(const int& x_in=0,const int& y_in=0)
    :m_x(x_in),m_y(y_in)
    {}

    void set(const Position2D pos_target)
    {
        set(pos_target.m_x,pos_target.m_y);
    }


    void set(const int& x_target , const int& y_target)
    {   
        m_x = x_target;
        m_y = y_target;
    }

    void get()
    {
        std::cout<<m_x <<" " << m_y << std::endl;
    }

    friend std::ostream& operator <<(std::ostream &out,Position2D &pos2d)
    {
        out << pos2d.m_x <<" "<< pos2d.m_y;
        return out;
    }

};

