#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

// main.cpp을 vector 로 쫌더 구조화? 있게 바꿨다 생각하면 됨.

int main()
{
    const int num_pro = std::thread::hardware_concurrency();
    std::cout<<"내 PC의 logical processor 수 : "<<num_pro<<std::endl;
    std::cout <<"현재 main 이 실행되고 있는 thread의 ID : "<<std::this_thread::get_id()<<std::endl;


    std::vector<std::thread> my_threads;
    my_threads.resize(num_pro);
    for(auto &e:my_threads)
    {
        e = std::thread([](){
        std::cout <<"현재 thread의 ID : "<<std::this_thread::get_id()<<std::endl;
        while (true){}
        });
    }

    for(auto &e:my_threads)
    {
        e.join();
    }

    std::cout<<"main end"<<std::endl;

    return 0;
}
