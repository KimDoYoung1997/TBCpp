#include <iostream> 
#include <exception> // 예외처리를 위해
#include <stdexcept>
#include <string>
using namespace std; 

// std::exception 을 상속하여 만든 커스텀 클래스를 예외클래스로 만들 수 있다.
// https://en.cppreference.com/w/cpp/error/exception/what
class CustomException : public std::exception
{
public:
    const char* what() const noexcept override // 적어도 what() 메서드에서는 exception을 throw 하지 않겠다는 의미로 noexcept 키워드를 사용함
    {
        return "Custom exception";
    }
};

int main()
{
    try 
    {
        // std::string s;
        // s.resize(-1);   // string 클래스 내부에서 size가 -1 와 같이 뭔가 이상하면, string 클래스 내부에서 알아서 throw하도록 되어있다.
        
        
        // https://en.cppreference.com/w/cpp/error/runtime_error
        // throw std::runtime_error("Bad thing happened.");    //runtime_error 클래스 또한 exception클래스의 자식 클래스이다.
        throw CustomException();
    } 
    


    catch (CustomException & except) 
    {
        std::cout <<"catch (CustomException & except) "<<endl;
        std::cout<< typeid(except).name()<<endl;;
        std::cerr << except.what() << endl;
    }

    catch (std::exception & except) 
    {
        std::cout <<"catch (std::exception & except)  "<<endl;
        std::cout<< typeid(except).name()<<endl;;
        std::cerr << except.what() << endl;
    }


    return 0;
}