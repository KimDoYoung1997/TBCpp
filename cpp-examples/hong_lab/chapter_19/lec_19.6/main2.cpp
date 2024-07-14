
/* 
main.cpp 에서 1억개가 되는 vector element 를 push_back 하는데 꽤 시간이 많이 걸리는것을 확인함. 
- 1개의 thread에서 push_back 하고, 4개의 thread에서  dotProductNaive 계산하면,
    thread의 data race를 막기위해 도입한 lock_guard 가 오히려 병목현상을 초래하여 시간을 지연시킴
    LG gram 기준 push_back에 약 20~25초 , dotProductNaive 에 15~20초 소요됨

- 1개의 thread에서 push_back 하고, 1개의 thread에서  dotProductNaive 계산하면, 오히려 속도가 향상됨
    LG gram 기준 push_back에 약 20~25초 , dotProductNaive 에 3.21초 소요됨. 즉 dotProductNaive 성능이 명확히 개선됨
    => mutex가 능사는 아니다. 오히려 병목을 불러올 수 있는 여지가 다분하다. 
 */

/*

main2.cpp 코드는 main.cpp 코드에서 vector 의 push_back기능을 parallel 처리하는 기능을 parallelPushBack 함수를 통해 추가함.
main.cpp는 **1**개의 thread에서 push_back 하고, **4**개의 thread에서  dotProductNaive 계산하는 반면

main2.cpp는 **4**개의 thread서 push_back하고, **4**개의 thread에서  dotProductNaive 계산하여 push_back 속도를 높이고자함
- 4개의 thread에서 push_back 하고, 4개의 thread에서  dotProductNaive 계산하면,
    LG gram 기준 push_back에 약 10초 , dotProductNaive 에 15~20초 소요됨
    => 여기서도 dotProductNaive 의 시간이 너무 지연된다. dotProductNaive 에 사용되믄 thread의 개수를 4에서 1로 줄여보면 성능이 개선될 것이다

 */
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <vector>
#include <mutex>
#include <numeric>
#include <execution>
#include <future>

std::mutex mtx;

void dotProductNaive(const std::vector<int>& v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end,
                     unsigned long long& sum)
{
    for(unsigned i = i_start; i < i_end; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx); 
        sum += v0[i] * v1[i];
    }
}

void parallelPushBack(std::vector<int>& vec, int start, int end, unsigned seed) {
    std::mt19937 engine(seed); // 각 스레드마다 고유의 seed를 사용한 엔진 생성
    std::uniform_real_distribution<> uniformDist(1, 10);
    vec.reserve(end - start); // 벡터 크기를 미리 예약
    for (int i = start; i < end; ++i) {
        vec.push_back(static_cast<int>(uniformDist(engine)));
    }
}

int main()
{
    const long long n_data = 100'000'000;
    const unsigned n_threads = 4;
    const long long range = n_data / n_threads;

    // initialize vectors
    std::vector<int> v0, v1;
    v0.reserve(n_data); // v0 원소가 1억개 reserve
    v1.reserve(n_data); // v1 원소가 1억개 reserve

    std::random_device seed;
    std::vector<std::thread> threads;

    std::cout << "parallel push_back start" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        // 각 스레드가 데이터를 추가할 별도의 벡터 생성
        std::vector<std::vector<int>> temp_vectors_v0(n_threads);
        std::vector<std::vector<int>> temp_vectors_v1(n_threads);

        // 스레드를 생성하고 데이터 추가 작업 시작
        for (unsigned i = 0; i < n_threads; ++i) {
            unsigned thread_seed = seed() + i; // 각 스레드에 고유한 seed 할당
            threads.emplace_back(parallelPushBack, std::ref(temp_vectors_v0[i]), i * range, (i + 1) * range, thread_seed);
            threads.emplace_back(parallelPushBack, std::ref(temp_vectors_v1[i]), i * range, (i + 1) * range, thread_seed + n_threads);
        }

        // 모든 스레드가 작업을 완료할 때까지 기다림
        for (auto& thread : threads) {
            thread.join();
        }

        // 최종 벡터에 데이터를 병합
        for (const auto& vec : temp_vectors_v0) {
            v0.insert(v0.end(), vec.begin(), vec.end());
        }
        for (const auto& vec : temp_vectors_v1) {
            v1.insert(v1.end(), vec.begin(), vec.end());
        }

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout << dur.count() << std::endl;
        std::cout << "parallel push_back end" << std::endl;
    }

    std::cout << "std::inner_product" << std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout << dur.count() << std::endl;
        std::cout << sum << std::endl;
    }

    std::cout<<"Naive"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        unsigned long long sum = 0;
        std::vector<std::thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads; // 100'000'000 / 4 ,assumes remainder = 0
        for(unsigned t=0; t<n_threads;++t)
        {
            // threads[t]=std::thread(dotProductNaive);
            threads[t]=std::thread(dotProductNaive,std::ref(v0),std::ref(v1),t*n_per_thread,(t+1)*n_per_thread,std::ref(sum));


        }

        for(unsigned t=0; t<n_threads;t++)
        {
            threads[t].join();
        }

        std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout <<dur.count() <<std::endl;
        std::cout <<sum <<std::endl;
        std::cout <<std::endl;
    }    

    return 0;
}
