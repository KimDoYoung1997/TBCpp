#include <iostream>
#include "MY_CONSTANT.h"
using namespace std;


int main()
{
    double radius ;
    cin >> radius ;
    double circumference = 2.0 * radius * constants::pi;
    cout<<circumference<<endl;
}



// int main()
// {
//     const int price_per_item = 3;

//     int num_item = 123;
//     int price = num_item * price_per_item;



// }