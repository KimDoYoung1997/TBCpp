#pragma once
#include "Timer.h"


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