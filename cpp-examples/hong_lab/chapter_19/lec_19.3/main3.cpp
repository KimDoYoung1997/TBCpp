#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>


int main()
{
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

    return 0;
}
