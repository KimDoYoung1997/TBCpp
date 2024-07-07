#include <iostream>
#include <thread>

#include <atomic>   // 데이터를 읽어오고 바꾸는 작업을 한번에 처리하여 data race를 방지
#include <mutex>    // lock, unlock
#include <chrono>

// using namespace std;
std::mutex mtx;
int main()
{
    // 여러 thread 가 공유하는 자원(변수)를 atomic으로 wrapping
    int shared_memory(0);


    auto const_func=[&]()
    {
        for(int i=0;i<1000;++i)
        {
            //sleep_for 가 있는 이유는, 실제 코드에서 알고리즘 처리할때 시간이 소요되는 것을 이 예제에서도 가상으로 구현하려 한 것임
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            // mtx.lock(); //lock을 하면 반드시 unlock을 해줘야함
            // RAII 원칙처럼 자동으로 lock과 unlock을 도와주는 lock_guard를 사용해도 좋다.
            // std::lock_guard<std::mutex> lock(mtx); // 임계 구역 잠금 , lock이라는 변수가 존재하는 범위내에서만 mtx관리
            std::scoped_lock lock(mtx); // lock_guard보다 조금 더 진보됨. lock_guard보다 사용하는 것을 권장함 , 다중 잠금 지원하여 여러 개의 mutex를 동시에 잠금 가능

            shared_memory++;   
            // mtx.unlock();

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
std::lock_guard와 std::scoped_lock 둘 다 RAII(Resource Acquisition Is Initialization) 원칙을 따르며, 스코프가 종료될 때 자동으로 잠금을 해제합니다. 하지만 이 둘 사이에는 몇 가지 중요한 차이점이 있습니다.

공통점
RAII 원칙: 두 클래스 모두 생성자에서 잠금을 걸고, 소멸자에서 잠금을 해제합니다.
단일 mutex 잠금: 둘 다 단일 mutex를 잠그는 데 사용할 수 있습니다.
차이점
다중 mutex 잠금

std::lock_guard: 단일 mutex만 잠글 수 있습니다. 여러 mutex를 잠그고자 할 때는 별도로 잠금 순서를 관리해야 합니다.
std::scoped_lock: 여러 mutex를 동시에 잠글 수 있습니다. 이를 통해 교착 상태(deadlock)를 방지할 수 있습니다.
교착 상태 방지

std::lock_guard: 여러 mutex를 잠글 때, 사용자가 올바른 잠금 순서를 보장해야 합니다.
std::scoped_lock: 여러 mutex를 안전하게 잠글 수 있는 메커니즘을 제공하여, 잠금 순서 문제로 인한 교착 상태를 방지합니다.
 */