#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string my_str("abcdefg");
    cout <<"my_str "<<(int)my_str[6] <<" " << (int)my_str[7] <<endl;

    cout <<my_str.c_str()<<endl;

    const char* c_str = my_str.c_str();
    cout <<"c_str "<<(int)c_str[6] <<" " << (int)c_str[7] <<endl;

    const char* c_str2 = my_str.data();
    cout <<"c_str2 "<<(int)c_str2[6] <<" " << (int)c_str2[7] <<endl;

    return 0;
}