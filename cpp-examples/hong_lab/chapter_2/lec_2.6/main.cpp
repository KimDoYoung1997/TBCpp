#include <iostream>

bool isEqual(int a , int b)
{
    bool result =  (a == b);
    return result;
}


int main()
{
    using namespace std;

    bool b1 = true ; // Copy Initialization
    bool b2(false) ; // Direct Initialization
    bool b3{ true } ; // Uniform Initialization
    b3 = false ; 

    cout << b3 << endl; //  0 = false
    cout << b1 << endl;  // 1 = true

// std::boolalpha
    cout << std::boolalpha;
    cout << b3 << endl; // false
    cout << b1 << endl;  // true

// std::noboolalpha
    cout << std::noboolalpha;
    cout << b3 << endl; //  0
    cout << b1 << endl;  // 1

// Not operator
    cout << !b3 << endl; // 1
    cout << !b1 << endl;  // 0 

// And operator &&
    cout << (true && true) << endl; // 1
    cout << (true && false) << endl; // 0
    cout << (false && true) << endl; // 0
    cout << (false && false) << endl;  // 0

// Or operator ||
    cout << (true || true) << endl; // 1
    cout << (true || false) << endl; // 1
    cout << (false || true) << endl; // 1
    cout << (false || false) << endl;  // 0

// If
    if(true)
    {
        cout<<"This is true"<<endl;
        cout << std::boolalpha;
        cout << isEqual(3,4) << endl;
    }
    if(false)
    {
        cout<<"This is Not true"<<endl;
    }
    else
    {
        cout << "This is false" <<endl;
    }


    bool d ;


    cin >> d;
    //cout << std::boolalpha ;
    cout << "Your input : " << d << endl;



    return 0;
}