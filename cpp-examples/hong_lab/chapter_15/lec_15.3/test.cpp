// 실행 시간 측정하기
// 내가 만든 프로그램, 코드가 얼마나 빨리 작동하는지 , 실행시간을 확인하는 방법에 대해 알아보자.
// sorting 하는 시간을 재려는 예제코드임.

#include <iostream>
#include <vector> // sort할 데이터 타입은 vector
#include <algorithm>  // sort할 알고리즘을 include하기 위해
#include <random> // random numbere generation을 위해
#include <chrono> // 시간을 측정하기 위해
#include "include/Timer.h"
using namespace std;

// /*
// clock_t: std::chrono::high_resolution_clock을 clock_t라는 별칭으로 정의합니다. 
// 이는 가능한 가장 정밀한 시계를 사용하여 시간 측정을 수행하고자 할 때 사용됩니다. 
// high_resolution_clock은 시스템에서 제공하는 가장 정밀한 시계입니다.

// second_t: 초 단위로 시간 간격을 나타내는 타입을 정의합니다. 
// std::chrono::duration<double, std::ratio<1>>는 기본적으로 시간 간격을 double 타입의 초 단위로 표현하기 위한 타입입니다. 
// std::ratio<1>은 1초를 나타냅니다.

// start_time: 타이머의 시작 시간을 저장합니다. Timer 클래스의 객체가 생성될 때 clock_t::now()를 호출하여 
// 현재 시간을 start_time에 할당함으로써 초기화됩니다.

// elapsed() 함수: 타이머의 시작 시간부터 현재까지 경과한 시간을 초 단위로 계산하여 출력합니다. 
// end_time - start_time은 시작 시간과 종료 시간 사이의 시간 간격을 나타내며, 
// std::chrono::duration_cast<second_t>(...)을 사용하여 이를 초 단위로 변환합니다. 
// .count() 메서드는 변환된 시간 간격을 double 값으로 반환합니다.
// */


// class Timer
// {
//     // 고해상도 시계 타입 정의. 최대한 정밀한 시간 측정을 위해 사용
//     using clock_t = std::chrono::high_resolution_clock;
    
//     // 초 단위로 시간 간격을 표현하기 위한 타입 정의. double 타입의 초 단위.
//     using second_t = std::chrono::duration<double, std::ratio<1>>;

//     // 타이머 시작 시간을 저장하기 위한 변수. 객체 생성 시 현재 시간으로 초기화됨.
//     std::chrono::time_point<clock_t> start_time = clock_t::now();
// public:
//     void elapsed()
//     {
//         // 현재 시간(타이머 종료 시간)을 측정
//         std::chrono::time_point<clock_t> end_time = clock_t::now();

//         // 시작 시간과 종료 시간의 차이를 초 단위로 변환 후 출력
//         cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
//     }    
// };
 



int main()
{
    random_device rnd_device; // 난수 생성기 인스턴스화
    //cout << rnd_device() << endl; // rnd_device() 를 호출하면 난수가 생성됨.

    mt19937 mersenne_engine{rnd_device()}; // // 생성된 난수로 mt19937 엔진을 초기화합니다.
    //cout <<  mersenne_engine()<< endl;
    
    vector<int> vec(1000); // 크기가 1000인 정수 벡터 생성

    // for (unsigned int i=0; i<vec.size(); ++i)
    // {
    //     vec[i]=i ;
    //     cout << vec[i] <<" ";
    // }cout <<endl;


     // 벡터에 랜덤한 값을 채움
    for (unsigned int i=0; i<vec.size(); ++i)
    {
        vec[i]=mersenne_engine();
        // cout << vec[i] <<" ";
    }cout <<endl;


    // 벡터를 섞음
    std::shuffle(begin(vec), end(vec), mersenne_engine);
    
    // // 섞은 후의 벡터 출력
    // for (auto &element : vec)
    // {
    //     cout << element <<" " ;
    // }cout << endl;

    Timer time; // 타이머 시작

    std::sort(begin(vec), end(vec)); // 벡터 정렬


    time.elapsed(); // 경과 시간 출력

    // 정렬된 벡터 출력
    // for (auto &element : vec)
    // {
    //     cout << element <<" " ;
    // }cout << endl;

    return 0;
}


