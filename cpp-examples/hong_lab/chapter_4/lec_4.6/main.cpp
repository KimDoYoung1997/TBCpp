#include <iostream>
#include <string>
#include <limits>
int main()
{
    using namespace std;

    cout << "Your age? : ";
    int age ;
    cin >> age;

    std::cin.ignore(32767, '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Your name ? : ";
    string name ;
    std::getline(std::cin,name);

    cout << name << " " << age << endl;


    string a("Hello, World");
    string b("Good bye World");
    cout << a.length() << endl;

    string c(a+b);
    cout << c.length() << endl;

    return 0;
}