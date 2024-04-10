#include <iostream>
#include <typeinfo>

using namespace std;

template<class T1 , class T2>
void ShowData(double num)
{
    cout <<"========================================="<<endl;
    cout <<"T1 타입 : "<< typeid((T1)num).name() << endl;
    cout <<"T2 타입 : "<< typeid((T2)num).name() << endl;
    cout << (T1)num << " " << (T2)num <<endl;
}

int main()
{
    ShowData<char,int>(65);
    ShowData<char,double>(65);
    ShowData<short,double>(65);
    ShowData<char,int>(65.2);

    return 0;
}