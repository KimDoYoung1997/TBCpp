/*
가상 기본 클래스(Virtual base classes)와 다이아몬드 상속 문제

다중 상속에 대해 공부할때 다이아몬드 상속 문제가 있다는 것을 사전에 인지했다.
다이아몬드 상속이 뭔지 알아보고, 이를 해결할 가상 상속(Virtual Inheritance) 또한 알아보자.

*/


// 아래 코드에서 가상 상속 (virtual public 키워드)없이 실행하면 기본 클래스인 PoweredDevice 클래스의 생성자가 두번 호출된다. 이는 개발자의 의도와 반대된다.
// 따라서 Scanner 클래스와 Printer 클래스에서 virtual public 의 가상 상속 클래스를 사용하여 다이아몬드 상속 구조를 만들어서, PoweredDevice 의 생성자가 두 번 호출되는것을 방지해주었다.
#include <iostream>
using namespace std;

class PoweredDevice
{
public:
    int m_i;
    PoweredDevice(int power):m_i(power)
    {
        cout <<"Powered Device: " << power << '\n';
    }

};

class Scanner : virtual public PoweredDevice 
{
public:
    int m_scan;    
    Scanner(int power, int scan):PoweredDevice(power),m_scan(scan)
    {
        cout <<"Scanner : " << m_scan << '\n'; 
    }
};

class Printer : virtual public PoweredDevice
{
public:
    int m_printer;
    Printer(int power, int printer):PoweredDevice(power),m_printer(printer)
    {
        cout <<"Printer : " << m_printer << '\n';
    }
};

class Copier : public Scanner, public Printer 
{
public:
    int m_copier=0;
    Copier(int power, int scan, int printer):Scanner(power, scan) ,Printer(power, printer)
    // 여기서 추가로 주의할 점 : PoweredDevice의 생성자를 Scanner, Printer 클래스에 의해 호출하지 않고, 아래와 같이 별도로 호출한다.
    ,PoweredDevice(power)
    {
        cout <<"Copier : " << m_copier << '\n';
    }
};

int main()
{
    Copier copier(10,1,2);
    cout << &copier.Scanner::PoweredDevice::m_i << endl;
    cout << &copier.Printer::PoweredDevice::m_i << endl;

    return 0;
}