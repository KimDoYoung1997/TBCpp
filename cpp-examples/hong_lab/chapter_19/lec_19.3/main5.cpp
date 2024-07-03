#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

std::mutex mtx; // mutual exclusion

int main()
{
    const int num_pro = std::thread::hardware_concurrency();
    auto work_func = [](const std::string& name)
    {
        for(int i=0;i<100;++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            mtx.lock();
            std::cout<<name<<" "<<std::this_thread::get_id()<<" is working "<<i<<std::endl;
            mtx.unlock();

        
        }
    };


    // work_func("JackJack");
    // work_func("Dash");

    std::thread t1 = std::thread(work_func,"JackJack");
    std::thread t2 = std::thread(work_func,"Dash");

    t1.join();
    t2.join();

    return 0;
}
