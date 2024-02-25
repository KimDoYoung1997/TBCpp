#include <iostream>
#include <istream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0):xpos(x), ypos(y)
    {}

    void showPosition()
    {
        cout <<"[" <<xpos<<", " <<ypos<<"]"<<endl;
    }

    Point operator*(int times)
    {
        Point temp(xpos*times,ypos*times);
        return temp;
    }

    friend Point operator*(int times, Point pos1);


};

Point operator*(int times, Point pos1)
{
    Point temp(times*(pos1.xpos),times*(pos1.ypos));

    return temp;
}

int main()
{
    Point pos(1,2);
    pos.showPosition();
    Point cpy;
    (pos*3*2).showPosition();

    
    return 0;
}