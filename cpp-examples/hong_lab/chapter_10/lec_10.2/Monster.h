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


/*
Monster class의 특성은 다음과 같다.
<멤버변수>
    1. 몬스터의 이름
    2. 몬스터의 위치(이 또한 class이다)
<멤버함수>
    1. moveTo
<오버로딩>
    1. operator<<
*/
class Monster
{
private:
    std::string m_name;
    // Position2D 클래스의 초기화를 Monster 클래스의 생성자 발동시 멤버 이니셜라이저를 통해 같이 진행할 수 있다.
    Position2D m_location;  //초기화 없는 declaration
public:
    Monster(const std::string name_in,const Position2D& pos_in) // Position2D 클래스의 초기화를 Monster 클래스의 생성자에서 진행
    :m_name(name_in), m_location(pos_in)
    {
        // std:: cout <<&pos_in << std::endl;
        // std:: cout <<&m_location << std::endl;
    }

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