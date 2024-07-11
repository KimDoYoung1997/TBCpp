#include <iostream>
#include <thread>

#include <atomic>   // 데이터를 읽어오고 바꾸는 작업을 한번에 처리하여 data race를 방지
#include <mutex>    // lock, unlock
#include <chrono>

// using namespace std;
std::mutex mtx;
int main()
{
    // 이번엔 mutex를 써보자
    int shared_memory(0);


    auto const_func=[&]()
    {
        for(int i=0;i<1000;++i)
        {
            //sleep_for 가 있는 이유는, 실제 코드에서 알고리즘 처리할때 시간이 소요되는 것을 이 예제에서도 가상으로 구현하려 한 것임
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            mtx.lock(); //lock을 하면 반드시 unlock을 해줘야함
            shared_memory++;   
            mtx.unlock();

        }
    };

    std::thread t1= std::thread(const_func);
    std::thread t2= std::thread(const_func);

    t1.join();
    t2.join();

    std::cout<<"After"<<std::endl;

    // t1이 shared memory값이 "11"임을 읽고 계산 하려는(sleep_for) 찰나에 t2가 중간에 12로 값을 증가시킨다. 
    // t1은 계산(sleep_for) 을 마친후 1을 더해 주고, 12로 반환한다.
    // 이러한 상황에서 data race가 발생한다. 이를 std::atomic으로 방지할 수 있다.
    std::cout <<shared_memory<<std::endl;

    return 0;
}


/* 
mutex와 atomic 모두 병렬 처리에서 데이터 레이스를 방지하기 위해 사용됩니다. 그러나 이 두 가지는 작동 방식과 사용 시나리오에서 차이가 있습니다. 다음은 mutex와 atomic의 공통점, 차이점, 장단점을 비교한 내용입니다.

공통점
데이터 레이스 방지: 둘 다 여러 스레드가 공유 자원에 동시에 접근할 때 발생하는 데이터 레이스를 방지하기 위해 사용됩니다.
스레드 안전성 제공: 둘 다 스레드 간의 데이터 일관성을 보장합니다.
차이점
작동 방식

mutex (Mutual Exclusion): mutex는 임계 구역(critical section)을 설정하여 한 번에 하나의 스레드만 해당 구역에 접근하도록 합니다. 스레드가 임계 구역에 들어가려면 mutex를 잠금(lock)하고, 임계 구역을 벗어날 때 잠금을 해제(unlock)합니다.
atomic: atomic은 특정 변수에 대해 원자적 연산을 제공합니다. 이 원자적 연산은 중단되지 않으며, 다른 스레드가 연산의 중간 상태를 볼 수 없습니다. 기본적으로 하드웨어 수준에서 원자적으로 처리됩니다.
사용 방법

mutex: std::mutex, std::lock_guard 등을 사용하여 임계 구역을 보호합니다.
atomic: std::atomic 템플릿을 사용하여 변수를 선언하고, 기본적인 연산(증가, 감소, 비교 및 교환 등)을 수행합니다.
장단점
mutex

장점
유연성: 복잡한 연산과 임계 구역을 설정할 수 있어 다양한 상황에 대응 가능합니다.
범용성: 어떤 종류의 데이터든 보호할 수 있습니다.
단점
오버헤드: 잠금과 해제에 대한 오버헤드가 있으며, 컨텍스트 스위칭이 발생할 수 있습니다.
교착 상태: 잘못된 사용으로 인해 교착 상태(deadlock)가 발생할 수 있습니다.
atomic

장점
성능: 간단한 연산에 대해 매우 빠른 원자적 연산을 제공합니다. 잠금이 필요 없으므로 오버헤드가 낮습니다.
사용 용이성: 단일 변수에 대한 원자적 연산을 쉽게 수행할 수 있습니다.
단점
제한된 기능: 복잡한 연산이나 여러 변수 간의 동기화는 처리할 수 없습니다.
제한된 데이터 타입: 기본적인 데이터 타입에 대해서만 원자적 연산을 제공합니다.
 */