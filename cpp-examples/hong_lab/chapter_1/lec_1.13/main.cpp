#include <iostream>

using namespace std;

namespace MySpace1
{
    namespace Innerspace
    {
        int doSomething(int a, int b)
        {
        return a+b;
        }    

    }
    int doSomething(int a, int b)
    {
        return a+b;
    }    
}

//int doSomething(int a, int b)
//{
//    return a*b;
//}


int main()
{
    using namespace MySpace1::Innerspace;
    cout <<"Hello,World"<<endl;
    cout <<doSomething(3,4)<<endl;
//    cout <<MySpace1::doSomething(3,4)<<endl;
//    cout <<MySpace1::Innerspace::doSomething(3,4)<<endl;

    return 0;
    
}
