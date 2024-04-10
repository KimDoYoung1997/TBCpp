#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
    T xpos , ypos;
public:
    Point(T x=0, T y=0): xpos(x),ypos(y)
    {}
    void ShowPosition() const 
    {
        cout <<"["<<xpos <<", "<<ypos <<"]"<<endl;
    }
};

int main()
{
    Point<int> pos_int(3,5);
    pos_int.ShowPosition();

    Point<double> pos_double(3.2,5.0);
    pos_double.ShowPosition();

    Point<char> pos_char('P','F');
    pos_char.ShowPosition();
    return 0;
}