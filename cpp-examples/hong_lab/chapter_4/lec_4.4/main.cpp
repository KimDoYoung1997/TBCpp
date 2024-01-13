#include <iostream>


/* int add(int x , int y)
{
    return x+y ;
} */

auto add(auto x , auto y) -> int
{
    return x+y ;
}

int main()
{
    using namespace std;
/* 
    auto a = 123;
    auto b = 123.0;
    auto c = 1+2 ; */
    auto result = add(1.6,22);
    cout << result << endl;
    return 0;
}