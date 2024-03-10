#include <iostream>

using namespace std;

class USBDevice
{
private:
    long m_id;
public:
    USBDevice(long id):m_id(id)
    {}

    long getID()
    {
        return m_id;
    }

    void plugAndPlay()
    {

    }
};

class NetworkDevice
{
private:
    long m_id;
public:
    NetworkDevice(long id):m_id(id)
    {}

    long getID()
    {
        return m_id;
    }

    void netWorking()
    {}

};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id): USBDevice(usb_id) , NetworkDevice(net_id)
    {}


};


/*
(발생할 수 있는 문제) : 
상속받는 두 클래스간에 중복되는 이름의 함수가 있다면 문제가 생길 여지가 있다.

*/

int main()
{
    USBNetworkDevice und(1,2);
    und.netWorking();
    und.plugAndPlay();
    
    //und.getID();    // USBDevice 와 NetworkDevice 사이에 getID 라는 메소드 이름이 중복된다.
    
    //이럴땐, 어떤 클래스에서 메소드를 가져오는지 명확히 해주면 된다.
    und.USBDevice::getID();
    und.NetworkDevice::getID();


    return 0;
}