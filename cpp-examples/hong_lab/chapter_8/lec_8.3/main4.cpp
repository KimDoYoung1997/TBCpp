#include <iostream>

using namespace std;



class Second
{
    public:
        Second()
        {
            cout <<"class Second constrctor()" << endl;
        }
        void print()
        {
            cout <<"print"<<endl;
        }
};


class First
{


    public:
        First()
        {
            cout <<"class First constrctor()" << endl;
            sec.print();

        }
    Second sec;

};



int main()
{
    First fir;




    return 0;
}