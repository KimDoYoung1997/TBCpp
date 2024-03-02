/*
https://chat.openai.com/share/a4c8cf4b-61b8-4d2e-9603-232ec6ba964f
Composition(구성 요소) 클래스
- 전체 / 부품의 관계
- 다른 클래스에는 속할 수 없음
- 멤버의 존재를 클래스가 관리함
- 단방향 방향성을 가짐
*/
#pragma once
#include <string>
#include "Position2D.h"


class Monster
{
private:
    std::string m_name;
    Position2D m_location;
public:
    Monster(const std::string name_in,const Position2D& pos_in)
    :m_name(name_in), m_location(pos_in)
    {}

    void moveTo(const Position2D &pos_target)
    {
        m_location.set(pos_target);   
    }

    friend std::ostream& operator<<(std::ostream& out, Monster &monster)
    {
        out <<monster.m_name<<" "<<monster.m_location;
        
        return out;
    }

};