/*
순수(pure) 가상 함수, 추상(abstract) 기본 클래스, 인터페이스(interface) 클래스

지금까지는 다형성에서 Virtual Function을 구현할 때 자식 클래스에서 조금 더 자기에게 적합한 함수를 오버라이딩 하는 관점을 공부했다.
이번 시간에는 설계라는 관점에서 기본 클래스를 만들 때, 자식 클래스에게 이러이러한 걸 반드시 해야 된다라는 제약을 걸어두고, 기본 클래스가 만들어질때
이러 이러한 이유로 만들어 졌다 라는 것을 지킬 수 있도록 강제하는 방법에 대해서 배워볼 것이다.

"순수(pure) 가상 함수"는 body가 없음. 따라서 자식 클래스에서 반드시 override 해줘야하는 강제성이 존재함
이러한 순수 가상 함수가 포함이 된 클래스를 "추상 클래스"라 부른다. 보통은 기본(base) 클래스 를 추상 클래스로 만든다.
또한, 순수 가상 함수로만 이루어진 클래스를 "인터페이스 클래스" 라고 부른다.

*/

#include <iostream>
#include <string>
using namespace std;


// 인터페이스 클래스 : 순수 가상 함수로만 이루어진 클래스 , 추상 클래스로서 순수 가상 함수가 쓰였으므로 인스턴스화가 불가능함.
class IErrorLog
{
public:
    // 순수 가상 함수
    virtual bool reportError(const char* errorMessage)=0;
    
    virtual ~IErrorLog(){}
};

class FileErrorLog : public IErrorLog
{
public:
    virtual bool reportError(const char* errorMessage) override
    {
        cout <<errorMessage<< " Writing error to a file " << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    virtual bool reportError(const char* errorMessage) override
    {
        cout <<errorMessage<<" Printing error to a console " << endl;
        return true;
    }
};

void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}



int main()
{
    FileErrorLog file_error_log;
    ConsoleErrorLog console_error_log;
    doSomething(file_error_log);
    doSomething(console_error_log);

    // const char* errorMessage = "File_not_found!";
    // file_error_log.reportError(errorMessage);
    
    
    return 0;
}