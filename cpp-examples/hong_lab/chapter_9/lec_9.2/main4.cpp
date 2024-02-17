#include <iostream>
#include <fstream>
using namespace std;

class Point {
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
    : m_x(x), m_y(y), m_z(z) {}

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    // friend 함수 선언
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
};

// friend 함수 정의 (클래스 밖)
std::ostream& operator<<(std::ostream &out, const Point &point) {
    out << point.m_x << " " << point.m_y << " " << point.m_z;
    return out;
}

int main() {

    ofstream of("out.txt");

    Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
    cout << p1 << " " << p2 << endl;
    of << p1 << " " << p2 << endl;

    of.close();
    
    return 0;
}
