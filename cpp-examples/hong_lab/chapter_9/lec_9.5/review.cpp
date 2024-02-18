#include <iostream>
using namespace std;

class Point
{
private:
    const int m_xpos, m_ypos;
public:
    Point(int xpos=0,int ypos=0):m_xpos(xpos), m_ypos(ypos)
    {}
    void showpoint() const
    {
        cout <<" m_xpos : " << m_xpos << " " << "y_pos : " << m_ypos << endl;
    }

    const Point  operator+(const Point &ref) const
    {

        return Point(this->m_xpos + ref.m_xpos , this->m_ypos + ref.m_ypos);
    }

};

int main()
{

    const Point a(3,4);
    const Point b(5,6);
    const Point c = a.operator+(b);
    c.showpoint();
    const Point d = a+b;
    d.showpoint();

    return 0;
}