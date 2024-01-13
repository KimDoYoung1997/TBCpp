#include <iostream>
#include <cstdint>

using namespace std;



struct Something
{
    int a,b,c,d;
    char alpha;
};

int main()
{

    Something ss ;
    Something *ptr_s = &ss ;

    
    cout << sizeof(Something) << endl; // 4*4 =16
    cout << sizeof(ptr_s) << endl;

    int* ptr_x ;
    cout << *ptr_x << endl; // trash value

    return 0;
}