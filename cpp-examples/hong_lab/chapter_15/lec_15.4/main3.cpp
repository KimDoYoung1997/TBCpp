#include <iostream>
#include "include/AutoPtr.h"
#include "include/Resource.h"
#include "include/MySwap.h"
#include <vector>
#include <string>
int main()
{
    using namespace std;
    vector<string> v;
    string str = "hello";
    string str2 = "bye";

    v.push_back(str);

    cout <<"str : "<<str << endl;
    cout <<v[0]<< endl;

    v.push_back(std::move(str));
    cout <<"str : "<<str << endl;
    cout <<v[0]<<" "<<v[1]<< endl;

    v.emplace_back(std::move(str2));
    cout <<"str2 : "<<str2 << endl;
    cout <<v[0]<<" "<<v[1]<<" "<<v[2]<< endl;

    return 0;
}
