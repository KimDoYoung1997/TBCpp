#include <iostream>
#include "include/Timer.h"
#include "include/Resource.h"
#include "include/AutoPtr.h"

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(1000));
    return res;
}


int main()
{
    using namespace std;
    streambuf* origin_buf = cout.rdbuf();

    Timer timer;
    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }

    cout.rdbuf(origin_buf);
    // cout << << endl;
    std::cout << (timer.elapsed()) << endl;

    return 0;
}