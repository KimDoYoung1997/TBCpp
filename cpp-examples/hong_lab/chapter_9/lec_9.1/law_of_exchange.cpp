// https://chat.openai.com/share/26f325f9-881a-4710-b182-1aa91fc8d9ad
#include <iostream>
using namespace std;
class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0):xpos(x),ypos(y)
    {}

    void showPosition() const
    {
        cout <<"xpos : " << xpos << " " << "ypos : " << ypos << endl;
    }

    Point operator *(int times) const
    {
        Point temp(xpos*times,ypos*times);
        return temp;
    }
    friend Point operator*(int times, const Point &ref);
    // friend Point operator*(const Point &ref,int times);



};

Point operator*(int times, const Point &ref)
{
    Point temp(ref.xpos*times, ref.ypos*times);

    return temp;
}

// Point operator*(const Point &ref,int times)
// {
//     Point temp(ref.xpos*times, ref.ypos*times);

//     return temp;
// }
int main()
{
    Point pos(1,2);
    pos.showPosition();
    ((pos*3)*4).showPosition();
    (4*pos).showPosition();
    return 0;
}