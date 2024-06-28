#include <iostream>
#include <string>
using namespace std;
int main()
{
    // assignment
    string str1("one");
    string str2;
    str2 = str1;    //copy assignment
    str2 = "two";
    // append
    str2.assign("three").append(" ").append("four ");
    cout <<str2<<endl;
    str2+="five ";
    cout <<str2<<endl;

    // swap
    string str_a("A") ;
    string str_b("B") ;
    cout <<str_a <<" " <<str_b <<endl;
    std::swap(str_a,str_b);
    cout <<str_a <<" " <<str_b <<endl;
    str_a.swap(str_b);
    cout <<str_a <<" " <<str_b <<endl;

    // insert
    string str("aaaa");
    str.insert(2, ("bbb"));
    cout <<str<<endl;
    return 0;
}