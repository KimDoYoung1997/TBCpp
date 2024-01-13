#include <iostream>
#include <typeinfo>

/* int computeDamage(int weapon_id)
{
    if (weapon_id ==0) // sword
    {
        return 1 ;
    }

    if (weapon_id==1) // hammer
    {
        return 2;
    }
} 
*/


enum Color
{
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,

};

enum Feeling
{
    HAPPY,
    JOY ,
    BLUE ,
};


int main()
{
    using namespace std;

    int color_id =COLOR_RED ;
    Color my_color = static_cast<Color>(3) ;

    int in_number;
    // cin >> in_number;

    if (in_number==COLOR_BLACK) my_color = COLOR_BLACK ;

    cout << static_cast<Color>(3) << endl;
    cout << COLOR_GREEN << endl;
    return 0;
}