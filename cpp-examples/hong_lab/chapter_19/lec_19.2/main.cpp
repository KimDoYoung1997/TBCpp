#include <iostream>
#include <tuple>
using namespace std;


// [고전적 방식]tuple을 사용하여 여러개의 리턴값 반환
tuple<int,int> my_func()
{
    return tuple<int,int>(123,456);
}


// [현대적 방식] auto 사용하여 여러개의 리턴값 반환
auto my_func2()
{
    return tuple<int,int>(123,456);
}

// [현대적 방식] c++17이후 버전,
auto my_func3()
{
    return tuple(123,456,789,012);
}


int main()
{
    cout <<"Hello, World"<<endl;
    tuple<int,int> result = my_func();
    cout <<std::get<0>(result)<<" " <<get<1>(result)<<endl;
    cout <<std::get<0>(my_func())<<" " <<get<1>(my_func())<<endl;
    cout<<"============== Recent upgraded version =============="<<endl;
    auto result2 = my_func2();
    cout <<std::get<0>(result2)<<" " <<get<1>(result2)<<endl;
    cout <<std::get<0>(my_func2())<<" " <<get<1>(my_func2())<<endl;
    cout<<"============== C++ upgraded version =============="<<endl;
    auto result3 = my_func3();
    cout <<std::get<0>(result3)<<" " <<get<1>(result3)<<endl;
    cout <<std::get<0>(my_func3())<<" " <<get<1>(my_func3())<<endl;
    cout<<"============== various return get method =============="<<endl;
    auto [a,b,c,d] = my_func3();
    cout <<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}
