#include <iostream>
#include <cmath>
using namespace std;

void getSinCos(const double degree, double &sin_out, double &cos_out)
{
    cout << "--------------------getSinCos() in!----------------------" << endl;

    static const double pi = 3.141592;

    double radians = degree * pi / 180.0 ;
    sin_out = std::sin(radians);
    cos_out = std::cos(radians);

    cout << "--------------------getSinCos() out!----------------------" << endl;

}

int main()
{

    double sin(0.0);
    double cos(0.0);

    cout <<"sin initialization : "<< sin <<" "<< &sin << endl;
    cout <<"cos initialization :"<< cos <<" "<< &cos << endl;

    getSinCos(30.0, sin, cos) ;

    cout <<"In main(), sin out! : "<< sin <<" "<< &sin << endl;
    cout <<"In main(), cos out! :" << cos <<" "<< &cos << endl;


    return 0;
}