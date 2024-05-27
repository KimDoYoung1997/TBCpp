#include <iostream>
using namespace std; 

class MyArray 
{
private:
    int m_data[5];
public:
    int &operator[] (const int& index)
    {
        if(index<0 || index >=5) throw index;  //멤버 함수 안에서도 throw를 할 수 있다는걸 보여주기 위한 예제
        return m_data[index];
    }
};


int main()
{
    try 
    {
        MyArray my_arr;
        my_arr[-2];
    }
    catch(const int&x)  //멤버 함수 안에서도 throw 한 것을 main loop에서 catch
    {
        cerr <<"array out or range! " <<x<< endl;
    }
    return 0;
}