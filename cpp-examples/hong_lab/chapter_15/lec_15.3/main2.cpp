#include <iostream>
#include "include/Timer.h"
#include "include/Resource2.h"
#include "include/AutoPtr2.h"   // move constructor 와 move assignment 구현

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000));
    return res;
}


int main()
{
    using namespace std;
    streambuf* origin_buf = cout.rdbuf();
    // cout.rdbuf(NULL);   // cout 이 timer로 측정하는 시간의 대부분을 잡아먹으니, 잠시 cout log를 끄도록 하자.
    Timer timer;
    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }

    cout.rdbuf(origin_buf);
    // cout << << endl;
    // std::cout << (timer.elapsed()) << endl;
    timer.elapsed();
    return 0;
}
