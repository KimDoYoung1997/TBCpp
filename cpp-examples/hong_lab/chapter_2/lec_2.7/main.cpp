#include <iostream>
#include <limits>

int main()
{
    using namespace std;

    char c1(65); //Direct Initialization
    char c2('A'); // "Hello, World" // std::string

//    cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;


// // c-style casting
// //    cout << (char)65 << endl;
// //    cout << (int)'A' << endl;
//     cout << "--------------------------" << endl;


//     cout << c1 << endl;
//     cout << (int)c1 << endl;
//     cout << c1 << endl;

//     cout << "--------------------------" << endl;


// // cpp -style casting
    //cout << char(65) << endl;
    //cout << int('A') << endl;
    //cout << char(c1) << endl;

    // cout << "--------------------------" << endl;

    // cout << static_cast<char>(65) << endl;
    // cout << static_cast<char>('A') << endl;
    // cout << static_cast<int>('A') << endl;

    // cout << "--------------------------" << endl;

    // char ch(97);
    // cout << ch << endl;
    // cout << static_cast<int>(ch) <<endl;
    // cout << ch << endl;

    // cout << "--------------------------" << endl;

    char a1(65) ;

    // cout <<"Byte of char type : "<<sizeof(a1)<<endl;

    // cout <<(int)std::numeric_limits<char>::max() << endl;
    // cout <<(int)std::numeric_limits<char>::lowest() << endl;


    cin >> a1;
    cout << a1 << " " << static_cast<int>(a1) << endl;

    cin >> a1;
    cout << a1 << " " << static_cast<int>(a1) << endl;


    // cout << "This is first line \nsecond line" << endl;
    // cout << "--------------------------" << endl;
    // cout << "This is first line"<< endl;
    // cout << "second line"<<endl;

    // cout << int('\n') << endl;

    //cout << "This is first line \tsecond line" << endl;

    // cout << "\"This is first line \tsecond line\"" << endl;


    return 0;

}