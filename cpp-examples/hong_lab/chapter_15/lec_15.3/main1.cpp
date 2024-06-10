#include <iostream>
#include "include/Timer.h"
#include "include/Resource.h"
#include "include/AutoPtr.h"   // copy constructor 와 copy assignment 구현


AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000)); //100000 부터는 Segmentation fault (core dumped) 에러 발생
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

