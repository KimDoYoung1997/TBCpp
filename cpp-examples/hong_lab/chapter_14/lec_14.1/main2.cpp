#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    // try : 코드를 일단 실행. 아무 에러도 발생하지 않는다면 try만 실행되고 catch 와 throw는 실행되지 않음
    // throw :  예외가 발생하는걸 포착
    // catch :  throw를 통해 포착한 예외를 처리하는 로직

    double x ;
    cin >> x ;

    try // 문제가 생길 여지가 있는 부분을 try 부분에 집어넣는다.
    {
        throw -1;
        if (x < 0.0) throw std::string("Negative Input!"); // 문제가 발생하는 특정 부분을 throw로 보낸다.
        cout << std::sqrt(x) << std::endl;
    }
    catch(std::string error_message)
    {
        std::cerr<<error_message << std::endl; // throw로 보낸 문제가 발생하는 특정 부분을 catch에서 처리한다.
    }
    catch(int num)
    {
        std::cerr<<num << std::endl; // throw로 보낸 문제가 발생하는 특정 부분을 catch에서 처리한다.
    }
    return 0;
}