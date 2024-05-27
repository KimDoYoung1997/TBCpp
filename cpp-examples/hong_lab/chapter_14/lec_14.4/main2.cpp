#include <iostream> 
#include <exception> // 예외처리를 위해
#include <stdexcept>
#include <string>
using namespace std; 


int main()
{
    try 
    {
        // std::string s;
        // s.resize(-1);   // string 클래스 내부에서 size가 -1 와 같이 뭔가 이상하면, string 클래스 내부에서 알아서 throw하도록 되어있다.
        
        
        // https://en.cppreference.com/w/cpp/error/runtime_error
        throw std::runtime_error("Bad thing happened.");    //runtime_error 클래스 또한 exception클래스의 자식 클래스이다.
    } 
    


    catch (std::exception & except) 
    {
        std::cout <<"catch (std::exception & except) "<<endl;
        std::cout<< typeid(except).name()<<endl;;
        std::cerr << except.what() << endl;
    }


    return 0;
}