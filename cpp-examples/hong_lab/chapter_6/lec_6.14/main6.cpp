#include <cstdint>
#include <iostream>

using namespace std;


struct Something
{
    int v1;
    float v2;
};


struct Other
{
    Something st;
};


int main()
{

    Other ot;
    ot.st.v1 = 1; // This expression is somewhat complicated. in place of this, we can use reference also.

    float &v2 = ot.st.v2 ;
    v2 = 3.0;

    cout << ot.st.v1  <<" " << v2 << " " <<ot.st.v2<<endl;



    return 0;
}