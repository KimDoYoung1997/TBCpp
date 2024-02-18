#include <iostream>
using namespace std;

class Point
{
private:
    int m_xpos,m_ypos;
public:
    Point(int xpos,int ypos):m_xpos(xpos),m_ypos(ypos)
    {}

    void showPoint()
    {
        cout <<"["<<m_xpos<<"," << m_ypos <<"]" << endl;
    }

    //forward increasement
    Point operator++()
    {
        m_xpos +=1;
        m_ypos +=1;
        return *this;
    }


    //backward increasement
    // const Point& operator++(int) 
    // {
    //     static Point back_temp(m_xpos,m_ypos);

    //     m_xpos +=1;
    //     m_ypos +=1;

    //     return back_temp;
    // }






    const Point operator++(int) 
    {
        const Point back_temp(m_xpos,m_ypos);

        m_xpos +=1;
        m_ypos +=1;

        return back_temp;
    }


    //forward decreasement
    friend Point& operator--(Point& ref)
    {
        ref.m_xpos -=1;
        ref.m_ypos -=1;
        return ref;
    }

    //backward decreasement
    const friend Point operator--(Point &ref,int)
    {
        const Point temp(ref);
        ref.m_xpos-=1;
        ref.m_ypos-=1;
        return temp;
    }

    friend std::ostream &operator <<(std::ostream &out,const Point &point)
    {
        out<<point.m_xpos<<" " <<point.m_ypos;
        return out;
    }



    const Point operator+(Point pos2) const 
    {
        return Point(this->m_xpos+pos2.m_xpos, this->m_ypos+pos2.m_ypos);
    }

    const Point operator-(Point pos2) const
    {
        return Point(this->m_xpos-pos2.m_xpos, this->m_ypos-pos2.m_ypos);
    }


    const Point operator+() const 
    {

        return *this;
    }

    const Point operator-() const
    {
        Point pos (-m_xpos,-m_ypos);

        return pos;
    }


};

int main()
{
    Point pos(3,4);
    Point pos2(5,7);
    cout << ++pos << endl;
    cout << pos++ << endl;
    cout << pos << endl;
    cout << --pos << endl;
    cout << pos << endl;
    cout << pos-- << endl;
    cout << pos << endl;

    cout << -(pos + pos2) << endl;
    cout << -pos << endl;
    cout << (pos++)++ << endl;
    c
    return 0;
}