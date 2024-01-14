#include <cstdint>
#include <iostream>

using namespace std;

int main()
{

    char name[] = "Jack jack";
    char *ptr = name;

    const int num_name = sizeof(name)/sizeof(name[0]);

    for (int i=0;i<num_name;i++)
    {

        //cout << name + i << endl;
        // cout << *(char*)(static_cast<void*>(name + i));
        // cout << *(char*)(name + i) ;

        // cout << *(name + i) ;
        cout << *(ptr+i) ;


    }
    cout << endl;
    return 0;
}