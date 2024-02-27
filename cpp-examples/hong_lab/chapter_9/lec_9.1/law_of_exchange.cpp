<<<<<<< HEAD
// https://chat.openai.com/share/26f325f9-881a-4710-b182-1aa91fc8d9ad
#include <iostream>
using namespace std;
=======
#include <iostream>
#include <istream>
using namespace std;

>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559
class Point
{
private:
    int xpos, ypos;
public:
<<<<<<< HEAD
    Point(int x=0, int y=0):xpos(x),ypos(y)
    {}

    void showPosition() const
    {
        cout <<"xpos : " << xpos << " " << "ypos : " << ypos << endl;
    }

    Point operator *(int times) const
=======
    Point(int x=0, int y=0):xpos(x), ypos(y)
    {}

    void showPosition()
    {
        cout <<"[" <<xpos<<", " <<ypos<<"]"<<endl;
    }

    Point operator*(int times)
>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559
    {
        Point temp(xpos*times,ypos*times);
        return temp;
    }
<<<<<<< HEAD
    friend Point operator*(int times, const Point &ref);
    // friend Point operator*(const Point &ref,int times);

=======

    friend Point operator*(int times, Point pos1);
>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559


};

<<<<<<< HEAD
Point operator*(int times, const Point &ref)
{
    Point temp(ref.xpos*times, ref.ypos*times);
=======
Point operator*(int times, Point pos1)
{
    Point temp(times*(pos1.xpos),times*(pos1.ypos));
>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559

    return temp;
}

<<<<<<< HEAD
// Point operator*(const Point &ref,int times)
// {
//     Point temp(ref.xpos*times, ref.ypos*times);

//     return temp;
// }
=======
>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559
int main()
{
    Point pos(1,2);
    pos.showPosition();
<<<<<<< HEAD
    ((pos*3)*4).showPosition();
    (4*pos).showPosition();
=======
    Point cpy;
    (pos*3*2).showPosition();

    
>>>>>>> 00a0ad9a60b3ed94182e1ad88004cf75cf515559
    return 0;
}