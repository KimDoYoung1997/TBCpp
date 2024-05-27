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
    catch(double)   // 실패
    {
        cerr<<"first caught int exception"<<endl;
    }
    cout <<"first End"<<endl;   // 여기가 실행이 안 됨!
}

void second()
{
    cout <<"second"<<endl;

    try 
    {
        third();
    }

    catch (double)   // 실패
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
    throw 'a';          //이번엔 의도적으로 아무 곳에서도 catch가 안 되도록 의도적으로 char 타입 변수를 throw 해보고, 어떤 결과가 일어나는지 봐보자.  => 런타임 에러 발생 => ellipses 사용해서 기타 모든 타입을 예외처리 하도록 수정.

    cout <<"last End"<<endl;    // 여기가 실행이 안 됨!

}


int main()
{
    cout <<"main loop Start" << endl;
    try
    {
        first();
    }
    catch (int) // 실패
    {
        cerr<<"main caught int exception"<<endl; 
    }
    catch(...)
    {
        cerr<<"main caught ellipses exception"<<endl;   //ellipses 기호인 ... 을 이용하여 기타 모든 예외를 한꺼번에 처리할 수 있다.

    }
    cout <<"main loop End" << endl; // 여기가 실행이 안 됨!


    return 0;
}