#include <iostream>

namespace a
{
    int my_var(10);
    int count(1231233);
}

namespace b
{
    int my_var(10);
}





int main()
{
    using namespace std;
/*     using std::cout;
    using std::endl; */

    {
        using namespace a;
        cout << my_var << endl;
        cout << count <<endl;
    }

    {
        using namespace b;
        cout << my_var << endl;
    }
    cout <<"Hello World!" ;

    return 0;
}