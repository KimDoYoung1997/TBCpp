#include <iostream>



namespace work1::work11::work111 // declaration and definition of work1::dosomething
{
    int a = 1;
    void doSomething()
    {
        a += 3;
        std::cout << a << std::endl;
    }
}


namespace work2  // declaration of work2::doSomething
{
    void doSomethng();
}



int main()
{
    std::cout<<work1::work11::work111::a++<<std::endl;
    std::cout<<work1::work11::work111::a<<std::endl;
    work1::work11::work111::doSomething(); // call of work1::doSomething 
    work2::doSomethng(); // call of work2::doSomething
    return 0;
}



namespace work2 // only definition of work2::dosomething
{
    int a = 1;
    void doSomethng()
    {
        a +=5;
        std::cout << a << std::endl;
    }

}