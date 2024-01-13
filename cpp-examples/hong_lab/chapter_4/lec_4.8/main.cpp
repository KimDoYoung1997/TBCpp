#include <iostream>


int main()
{
    using namespace std;

    enum class Color
    {
        RED,
        BLUE,
    };

    enum class Fruit
    {
        BANANA,
        APPLE,
    };

    enum Grade
    {
        A,
        B,
    };

    Color color = Color::RED;
    Fruit fruit = Fruit::BANANA;
    Grade grade = A;
    cout << grade << endl;

/*     if (color == fruit)
    {
        cout << "Color is Fruit?" << endl;
    } */

    Color color1 = Color::BLUE;
    Color color2 = Color::BLUE;

    if (color1 == color2)
    {
        cout <<"Same color " << endl;
    }

    return 0;
}