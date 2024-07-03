#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>


int main()
{
    const int num_pro = std::thread::hardware_concurrency();
    std::cout<<"내 PC의 logical processor 수 : "<<num_pro<<std::endl;
    std::cout <<"현재 main 이 실행되고 있는 thread의 ID : "<<std::this_thread::get_id()<<std::endl;

    std::thread t1 = std::thread([](){
        std::cout <<"현재 thread t1 이 실행되고 있는 thread의 ID : "<<std::this_thread::get_id()<<std::endl;
        while(true)
        {}
        std::cout<<"thread t1 end"<<std::endl;
    });
    std::thread t2 = std::thread([](){
        std::cout <<"현재 thread t2 이 실행되고 있는 thread의 ID : "<<std::this_thread::get_id()<<std::endl;
        while(true)
        {}
        std::cout<<"thread t2 end"<<std::endl;
    });
    std::thread t3 = std::thread([](){
        std::cout <<"현재 thread t3 이 실행되고 있는 thread의 ID : "<<std::this_thread::get_id()<<std::endl;
        while(true)
        {}
        std::cout<<"thread t3 end"<<std::endl;
    });
    t1.join();
    t2.join();
    t3.join();
    std::cout<<"main end"<<std::endl;
    return 0;
}
