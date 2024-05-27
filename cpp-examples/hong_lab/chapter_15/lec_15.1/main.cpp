#include <iostream>
#include "include/Resource.h"
#include "include/AutoPtr.h"
using namespace std;

// Move semantics and Smart pointer
// RAII : Resource Acuisition is Initialization : new한 곳에서 delete 해줘야 한다.

void doSomething()
{
    try
    {
        AutoPtr<Resource> auto_res(new Resource);

        // work with res
        if (true)
        {
            std::cout<<"throw" <<std::endl;
            throw -1;
        }

    }



    catch(...)
    {
        std::cout<<"catch exception" <<std::endl;
    }
    // delete res;

    std::cout <<"hhh" << std::endl;

    // if work done, exit
    return ;
}

int main()
{
    std::cout <<"main start" <<std::endl;
    doSomething();


    return 0;
}