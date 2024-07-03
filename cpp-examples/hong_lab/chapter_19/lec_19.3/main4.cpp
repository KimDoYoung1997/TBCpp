#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
std::mutex mtx; // mutual exclusion

// main3는 동기처리, main4 는 비동기 처리. 여기에 추가로 vector 와 for 를 이용해서 구조화 해봄
int main()
{
    const int num_pro = std::thread::hardware_concurrency();
/* 
    auto work_func = [](const std::string& name)
    {
        for(int i=0;i<5;++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout<<name<<" "<<std::this_thread::get_id()<<" is working "<<i<<std::endl;
        }
    };
    work_func("JackJack");
    work_func("Dash");
*/
    std::vector<std::thread> my_threads;
    my_threads.resize(num_pro);
    for(auto &e:my_threads)
    {
        e = std::thread([](const std::string& name)
        {
        for(int i=0;i<5;++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            mtx.lock();
            std::cout<<name<<" "<<std::this_thread::get_id()<<" is working "<<std::endl;
            mtx.unlock();

        }
        },"JackJack");
    }
    for(auto &e:my_threads)
    {
        e.join();
    }

    return 0;
}
