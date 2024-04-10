#include <iostream>
#include <cstring>
using namespace std;


template<typename T>
T Max(T a, T b)
{
    return a > b ? a : b ;
}

template<>
// char* Max<char*>(char* a, char* b) 이 문법도 가능
char* Max(char* a, char* b)
{
    cout <<"char* Max(char* a, char* b)"<< endl;
    return strlen(a) > strlen(b) ?  a : b;
}

template<>
// const char* Max<const char*>(const char* a , const char* b) 이 문법도 가능
const char* Max(const char* a , const char* b)
{
    cout <<"const char* Max(const char* a , const char* b)"<< endl;
    return strcmp(a, b) >0 ? a : b ;
}
int main()
{
    cout <<Max("simple","Best")<<endl;
    
    char str1[] = "Simple";  // const char 타입이 아닌 일반 char 타입임  
    char str2[] = "Best" ;   // const char 타입이 아닌 일반 char 타입임

    cout <<Max(str1 , str2);


    return 0;
}