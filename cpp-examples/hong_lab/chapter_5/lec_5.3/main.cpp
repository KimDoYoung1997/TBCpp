#include <iostream>

using namespace std;

enum class Colors
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE
};
/* 
void printColorName(Colors color)
{
    if(color == Colors::BLACK)
        cout << "Black" << endl;
    else if (color == Colors::WHITE)
        cout << "White" << endl;
    else if (color == Colors::RED)
        cout << "Red" << endl;
    else if (color == Colors::GREEN)
        cout << "Green" << endl;
    else if (color == Colors::BLUE)
        cout << "Blue" << endl;
}
 */

void printColorName(Colors color)
{
    switch(color)
    {
        case (Colors::BLACK):
            cout << "Black" << endl;
            break;
        case (Colors::WHITE):
            cout << "White" << endl;
            break;
        case (Colors::RED):
            cout << "Red" << endl;
            break;
        case (Colors::GREEN):
            cout << "Green" << endl;
            break;
        case (Colors::BLUE):
            cout << "Blue" << endl;
            break;
    }
}


int main()
{
/*     int x;
    cin >> x;

    switch(x)
    {
        case 0:
            cout <<"Zero"<< endl;
            break;
        case 1:
            cout <<"One"<<endl;
            //break;
        case 2:
            cout <<"Two"<<endl;
            break;
    } */

    printColorName(Colors::BLACK);

    return 0;
}