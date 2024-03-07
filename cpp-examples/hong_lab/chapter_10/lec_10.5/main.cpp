/*
앞서 배운 구성관계(Composition : monter, position), 집합관계(Aggregation : lec,teacher,student), 연계관계(Association : doctor, patient) 보다
연결 강도가 더 약한 의존관계(Dependency)에 대해서 알아보자.

의존관계는 굉장히 많이 쓰이므로 더 주의깊게 보자.
*/

#include <bits/types/clock_t.h>
#include <bits/types/timer_t.h>
#include <iostream>
#include <chrono>
#include <ratio>

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double,std::ratio<1>>;
    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
        
    }

};

class Worker
{
public:
    void doSomething()
    {
        Timer timer;    //timer 가 선언된 순간 private 멤버변수에서 start_time이 고정됨

        // do work here and check elapsed time

        timer.elapsed();    //timer.elapsed가 호출된 순간 end_time이 고정되고 이에따라 (end_time - start_time)이 계산됨
    }
};

int main()
{
    Worker().doSomething();
    return 0;
}