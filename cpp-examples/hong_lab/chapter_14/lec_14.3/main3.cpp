#include <iostream>
using namespace std; 


class Exception
{
public:
    virtual void report() 
    {
        cerr << "Exception report"<< endl;
    }
};

class ArrayException : public Exception 
{
public:
    void report() override
    {
        cerr << "Array Exception report"<< endl;
    }
};

class MyArray 
{
private:
    int m_data[5];
public:
    int &operator[] (const int& index)
    {
        if(index<0 || index >=5) throw ArrayException();  //기본 자료형 뿐만 아니라, 예외 클래스의 인스턴스 또한 throw할 수 있다. //멤버 함수 안에서도 throw를 할 수 있다는걸 보여주기 위한 예제
        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;
    try
    {
        my_array[100];
    }
    catch(const int &x)
    {
        std::cerr<<"Exception"<<endl;
    }

    catch( Exception &e)
    {
        std::cout<<"doSomething() catch( Exception &e)"<<endl;
        e.report();

        // catch한걸 의도적으로 다시 throw 하기
        throw ArrayException();
    }
    catch( ArrayException &e)   
    {
        std::cout<<"doSomething() catch( ArrayException &e)"<<endl;
        e.report();
    }
}

int main()
{
    try{
    doSomething();
    }

    catch( ArrayException &e)   // 다시 throw한걸 main에서 catch 한다.
    {
        std::cout<<"main() catch( ArrayException &e)"<<endl;
        e.report();
    } 
    return 0;
}