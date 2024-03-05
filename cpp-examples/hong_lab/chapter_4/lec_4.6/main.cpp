#include <iostream>
#include <string>
#include <limits>                   // std::numeric_limits<std::streamsize>::max() 를 사용하기위해 include함
int main()
{
    using namespace std;

    cout << "Your age? : ";
    int age ;
    cin >> age;

    //std::cin.ignore(32767, '\n'); // 2바이트 int signed value중 가장 큰 32767
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // std::numeric_limits<std::streamsize>::max() 는 32767을 의미한다. streamsize 는 버퍼크기를 말함

    cout << "Your name ? : ";
    string name ;
    std::getline(std::cin,name);    // 엔터 치기전까지 쭉 라인의 입력을 받도록

    cout << name << " " << age << endl;


    string a("Hello, World");
    string b("Good bye World");
    cout << a.length() << endl;     // null 제외 12
    cout << b.length() << endl;     // null 제외 14

    string c(a+b);
    cout << c.length() << endl;

    return 0;
}