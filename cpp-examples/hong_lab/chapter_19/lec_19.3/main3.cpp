#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

// 비동기 처리가 아닌, 동기 처리 예제. main5와 비교해보기 위해 만듬

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
