#include <iostream>


void doSomething()
{
    using namespace std;
#ifdef LIKE_APPLE
    cout <<"APPLE" <<endl;
#else
    cout<<"ORANGE"<<endl;
#endif
}
