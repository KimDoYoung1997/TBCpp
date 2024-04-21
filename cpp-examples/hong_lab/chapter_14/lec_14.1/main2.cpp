#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;



int main()
{
    // try, catch , throw
    double x ; 
    cin >> x;

    // 문제가 생길 여지가 있는 부분을 try부분으로 감싸준다.
    try
    {
        if (x<0.0) 
        {
            throw std::string("Negative input");
        }
        cout << std::sqrt(x) << endl;
    }

    catch (std::string error_message)
    {
        cout <<"catch! "<< error_message << endl;
    }
   
    return 0;
}