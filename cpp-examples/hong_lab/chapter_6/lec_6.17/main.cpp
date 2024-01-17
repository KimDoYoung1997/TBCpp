#include <iostream>

using namespace std;

int main()
{

// // conventional expression

int fibonacci[] = {0,1,1,2,3,5,8,
                          13,21,34,55,89};

    cout << (uintptr_t)fibonacci << endl;
//   int len = sizeof(fibonacci) / sizeof(int);

//     for (int i=0 ; i<len ; i++)
//     {
//         cout << fibonacci[i] << endl;
//     }





    // change array values
    for ( int& number : fibonacci)
    {
        number *= 10;
        cout << number<<" " ;
        //cout << (uintptr_t)&number << endl;
        
    }cout << endl;
    

    // for ( auto& number : fibonacci)
    // {
    //     number = 10;
    //     //cout << (uintptr_t)&number << endl;
        
    // }


   // output
    for (const auto &number : fibonacci)
    {
        cout << number << " " ;
    }
    cout << endl; 





 

// // conventional expression

//    char fibonacci_str[] = "fibonacci";
//     int len_char = sizeof(fibonacci_str) / sizeof(char);

//     for (int i=0 ; i<len_char ; i++)
//     {
//         cout << fibonacci_str[i] ;
//     }    
//     cout << endl;


    // for (char number : "fibonacci")
    // {
    //     cout << number << " " ;
    // }
    // cout << endl; 


    return 0;
}