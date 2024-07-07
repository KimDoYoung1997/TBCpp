#include <iostream>
#include <thread>

#include <atomic>   // 데이터를 읽어오고 바꾸는 작업을 한번에 처리하여 data race를 방지
                    // atomic(원자적) 연산은 컴퓨터 프로그래밍에서 여러 스레드가 동시에 같은 변수를 읽고 쓰는 경우에도 데이터 일관성을 유지하기 위해 사용됩니다. 원자적 연산은 중단될 수 없는 연산을 의미하며, 
                    // 한 스레드가 해당 연산을 수행하는 동안 다른 스레드는 그 연산의 중간 상태를 볼 수 없습니다.
#include <mutex>
#include <chrono>

// using namespace std;

int main()
{
    // 여러 thread 가 공유하는 자원(변수)를 atomic으로 wrapping
    std::atomic<int> shared_memory(0);


    auto const_func=[&]()
    {
        for(int i=0;i<1000;++i)
        {
            //sleep_for 가 있는 이유는, 실제 코드에서 알고리즘 처리할때 시간이 소요되는 것을 이 예제에서도 가상으로 구현하려 한 것임
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            // shared_memory++;    // 이는 int 의 증감연산자가 아니라, atomic 타입변수의 증감 연산자로 오버로딩이 된 것!
            
            shared_memory.fetch_add(1);    //  증감연산자가 말고 fetch.add(1) 메소드를 사용할 수도 있다.

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
