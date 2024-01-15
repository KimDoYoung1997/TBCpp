#include <cstdint>
#include <iostream>

using namespace std;


void doSomething(int &n)
{
    n=10;
    cout << "3. In doSomething, n: " << n << endl;
        cout <<"4. In doSomething, address of n: "<< (uintptr_t)&n << endl;

}

void doOther(const int &n)
{
    //n=10;
    cout << "If you want variable n is not changed after doOther func, make argument to 'const int &n' " <<endl;
    cout << "7. In doOther, n: " << n << endl;
    cout <<"8. In doOther, address of n: "<< (uintptr_t)&n << endl;

}

int main()
{

    int n = 5;
    cout <<"1. In main, n: "<< n << endl;
    cout <<"2. In main, address of n: "<< (uintptr_t)&n << endl;


    doSomething(n);

    cout <<"5. In main, n: "<< n << endl;
    cout <<"6. In main, address of n: "<< (uintptr_t)&n << endl;

    doOther(n);

    return 0;
}