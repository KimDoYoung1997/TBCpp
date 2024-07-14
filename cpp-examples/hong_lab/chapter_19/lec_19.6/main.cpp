/* 
main.cpp 에서 1억개가 되는 vector element 를 push_back 하는데 꽤 시간이 많이 걸리는것을 확인함. 
- 1개의 thread에서 push_back 하고, 4개의 thread에서  dotProductNaive 계산하면,
    thread의 data race를 막기위해 도입한 lock_guard 가 오히려 병목현상을 초래하여 시간을 지연시킴
    LG gram 기준 push_back에 약 20~25초 , dotProductNaive 에 15~20초 소요됨

- 1개의 thread에서 push_back 하고, 1개의 thread에서  dotProductNaive 계산하면, 오히려 속도가 향상됨
    LG gram 기준 push_back에 약 20~25초 , dotProductNaive 에 3.21초 소요됨. 즉 dotProductNaive 성능이 명확히 개선됨
    => mutex가 능사는 아니다. 오히려 병목을 불러올 수 있는 여지가 다분하다. 
 */

#include <iostream>
#include <chrono>
#include <mutex>
#include <random>       // std::uniform_real_distribution<> uniformDist(1,10);
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>      // std::inner_product
#include <execution>    // parallel execution

// using namespace std;
std::mutex mtx;

void dotProductNaive(const std::vector<int>&v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end,
                     unsigned long long& sum)
{
    for(unsigned i=i_start;i<i_end;++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        sum+=v0[i]*v1[i];
    }

}


int main()
{
    const long long n_data =100'000'000;
    const unsigned n_threads = 4;
    // const unsigned n_threads = 1;    // 오히려 이게 훨씬 더 빠름

    // initialize vectors
    std::vector<int> v0,v1;
    v0.reserve(n_data);         // v0 원소가 1억개 reserve
    v1.reserve(n_data);         // v1 원소가 1억개 reserve

    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_real_distribution<> uniformDist(1,10); //생성된 객체는 [1, 10) 범위(1 이상 10 미만)의 난수를 생성합니다. 이는 1과 10 사이의 실수 난수를 균등하게 생성한다는 의미입니다.

    std::cout<<"push_back start"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();

        for (long long i = 0;i<n_data;++i)
        {
            v0.push_back(uniformDist(engine));      // v0 원소 1억개 push_back
            v1.push_back(uniformDist(engine));      // v1 원소 1억개 push_back
        }
        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout <<dur.count()<<std::endl;
        std::cout <<"push_back end"<<std::endl;
    }

    std::cout <<"std::inner_product"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;

        std::cout <<dur.count()<<std::endl;
        std::cout<<sum<<std::endl;

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