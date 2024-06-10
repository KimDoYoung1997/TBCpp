#pragma once

#include <iostream>
#include <chrono>
#include <ratio>
#include <random> // random numbere generation을 위해
#include <vector> // sort할 데이터 타입은 vector


class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double,std::ratio<1>>;
    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        // 현재 시간(타이머 종료 시간)을 측정
        std::chrono::time_point<clock_t> end_time = clock_t::now();

        // 시작 시간과 종료 시간의 차이를 초 단위로 변환 후 출력
        std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
    }

};