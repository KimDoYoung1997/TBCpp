#include <iostream>
#include <string>
using namespace std;

void print(std::string str){cout <<"1" << endl;}
void print(char ch =' '){cout <<"2" << endl;}


void print2(int x, int y=20)
{
    cout << x <<" " << y << endl;   
}

void print2(int x)
{
    cout << x << endl;   

}


int main()
{
    print();
    //default value can affect function overloading!
    print2(10); // call to 'print2; is ambiguous 

    return 0;
}