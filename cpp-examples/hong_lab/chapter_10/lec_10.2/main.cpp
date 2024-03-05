//#include <iostream>
//#include "Position2D.h"
using namespace std;
#include "Monster.h"
int main()
{
    Position2D pos_init(0,0);
    Monster monster1("dragon",pos_init);
    {
        // cout << &pos_init << endl;
        Position2D pos_second(1,3);
        monster1.moveTo(pos_second);
        cout <<monster1 << endl;
    }
    
    return 0;
}