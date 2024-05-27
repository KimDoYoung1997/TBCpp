#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

/*
std::exception
       |
CustomException
       |
MyRuntimeError
*/

class CustomException : public std::exception
{
public:
    const char* what() const noexcept override // 적어도 what() 메서드에서는 exception을 throw 하지 않겠다는 의미로 noexcept 키워드를 사용함
    {
        return "Custom exception";
    }
};

class MyRuntimeError : public CustomException
{
private:
    std::string m_message;
public:
    MyRuntimeError(const std::string& message) : m_message(message) {}

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

int main()
{
    try 
    {
        // 사용자 정의 예외를 던짐
        throw MyRuntimeError("Bad thing happened.");
    } 
    catch (CustomException & except) 
    {
        std::cout <<"catch (CustomException & except) "<<endl;
        std::cout << typeid(except).name() << endl;
        std::cerr << except.what() << endl;
    }

    return 0;
}
