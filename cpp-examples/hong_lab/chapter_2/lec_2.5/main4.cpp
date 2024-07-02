#include <iostream>
#include <iomanip>
#include <limits> // lecture 2.2
#include <cmath> // lecture 2.2

int main()
{
    using namespace std;

    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = - 5.0 / zero;
    double nan = zero / zero ;

    cout << zero << endl;
    cout<<setprecision(17)<<endl;      
    cout << zero << endl;

    cout << "----------isnan------------ from cmath" << endl;

    cout << posinf <<" " << isnan(posinf) << endl;
    cout << neginf<<" " << isnan(neginf) << endl;
    cout << nan <<" " << isnan(nan) << endl;


    cout << "----------isinf------------ from cmath" << endl;

    cout << posinf <<" " << isinf(posinf) << endl;
    cout << neginf<<" " << isinf(neginf) << endl;
    cout << nan <<" " << isinf(nan) << endl;

    return 0;
}