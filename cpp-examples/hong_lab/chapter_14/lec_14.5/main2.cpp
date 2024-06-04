#include <iostream>
/*
상속관계는 아래와 같다. 
       A
       |
       B
*/
class A 
{
public:
    A(int x):m_x(x)
    {
        if (x <= 0)
        {
            throw -1;
        }
    }
private:
    int m_x;

};

class B : public A 
{
public:
    // 생성자에서 바로 catch를 할 수 있다.
    B(int x) try :A(x)
    {}
    catch (int) 
    {
        std::cout <<"[ERROR] class B : x is negative" << std::endl; 
        // throw -1;
        // throw ; 실제로 Re-throw가 없지만 있는것처럼 작동한다.
        
        /*
        여기서 중요한 점은 catch 블록 안에 throw 구문이 없습니다. 
        그러나, 생성자에서 예외를 처리하고 나면 자동으로 다시 예외를 던지게 됩니다. 
        이는 C++의 생성자 예외 처리 규칙 때문입니다.
        */
        
    }
};


int main()
{
    try 
    {
        B b(-1);
    }
    catch (int) 
    {
        std::cout <<"[ERROR] main() : x is negative" << std::endl;
    }

    return 0;
}