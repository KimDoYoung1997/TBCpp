#include <iostream>

using namespace std;


int getValue(int x)
{

    int value = x * 2 ;

    return value;
}

int* getValue2(int x)
{

    int value = x * 2 ;
    int * ptr = &value;

    return ptr;
}


int main()
{

    int value = getValue(3);


    //this below two method is not recommended to use.. please don't use although sometiimes it works..!
    int* value2 = getValue2(3);
    int value3 = *getValue2(3);

    cout <<"int value : " << getValue(3) << endl;
    cout <<"pointer value2 : " << getValue2(3) << endl;
    cout <<"int value3 : " << *getValue2(3) << endl;










    return 0;
}