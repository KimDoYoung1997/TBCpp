#include <iostream>

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