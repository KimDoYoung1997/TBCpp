#include <iostream>
using namespace std;

template<typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x=0,T y=0);
    void ShowPosition() const;
};

template<typename T>
Point<T>::Point(T x, T y):xpos(x),ypos(y)
{}

template<typename T>
void Point<T>::ShowPosition() const
{
    cout <<"["<<xpos <<", "<<ypos <<"]"<<endl;
}

int main()
{
    Point<int> pos_int(3,5);
    pos_int.ShowPosition();

    Point<double> pos_double(3.3,5.5);
    pos_double.ShowPosition();
    
    return 0;
}

