#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string my_str("abcdefg");
    cout << my_str[0]<<endl;
    cout <<my_str[3]<<endl;
    my_str[3]='Z';
    cout <<my_str<<endl;

    try
    {
        // my_str[100]='X';    // 런타임 에러 발생 안 하네? 아주 소름돋는 경우
        my_str[100]='X';    // 런타임 에러 발생 안 하네? 아주 소름돋는 경우
        my_str.at(100)='X';    // 런타임 에러 발생 예외처리가 있는버전 , 예외처리가 있어서 안전할 수 있겠지만, 속도는 느려짐

    }
    catch(std::exception &e)
    {
        cout<<"예외처리"<<endl;
        cout <<e.what() <<endl;
    }

    cout <<my_str<<endl;

    return 0;
}