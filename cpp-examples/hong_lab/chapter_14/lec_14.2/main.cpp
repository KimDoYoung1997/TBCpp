#include <iostream>

using namespace std;

//forward declaration
void second();
void third();
void last();


void first()
{
    cout <<"first"<<endl;
    try 
    {
        second();
    }
    catch(int)
    {
        cerr<<"first caught int exception"<<endl;
    }
    cout <<"first End"<<endl;   // 여기선 에러를 잡았으므로 실행이 됨!
}

void second()
{
    cout <<"second"<<endl;

    try 
    {
        third();
    }
    // catch (int)
    // {
    //     cerr <<"second caught int exception"<<endl;
    // }
    catch (double) //throw에서 던진 int 타입과 double타입이 달라서, second 함수의 catch가 호출되지 않는다.
    {
        cerr <<"second caught int exception"<<endl;
    }
    cout <<"second End"<<endl;  // 여기가 실행이 안 됨!
}

void third()
{
    cout <<"third"<<endl;

    last();

    cout <<"third End"<<endl;   // 여기가 실행이 안 됨!

}

void last()
{
    cout <<"last"<<endl;

    cout <<"Throw exception"<<endl;
    throw -1;

    cout <<"last End"<<endl;    // 여기가 실행이 안 됨!

}


int main()
{
    cout <<"main loop Start" << endl;
    try
    {
        first();
    }
    catch (int)
    {
        cerr<<"main caught int exception"<<endl;
    }

    cout <<"main loop End" << endl;

    return 0;
}