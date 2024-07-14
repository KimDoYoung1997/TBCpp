/* 
main.cpp 에서 1억개가 되는 vector element 를 push_back /* 
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
std::mutex mtx; //4개의 thread가 모두 접근할 수 있게 전역변수로 설정함

void dotProductNaive(const std::vector<int>&v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end,
                     unsigned long long& sum)
{
    for(unsigned i=i_start;i<i_end;++i)
    {
        // std::lock_guard<std::mutex> lock(mtx);
        sum+=v0[i]*v1[i];       // 4개의 thread에서 하나의 sum이라는 변수를 공유하므로, lock_guard를 사용해줘야 한다. 이에 따른 병목현상으로 delay가 되는점을 주의깊게 살펴보자.
    }

}
void dotProductLock(const std::vector<int>&v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end,
                     unsigned long long& sum)
{
    // std::scoped_lock<std::mutex> lock(mtx);     // 병렬 처리의 의의가 없음. 단일 스레딩이랑 같음
    // std::cout<<"Thread start"<<std::endl;

    for(unsigned i=i_start;i<i_end;++i)
    {
        std::scoped_lock<std::mutex> lock(mtx);     // 너~~무 느려~!
        sum+=v0[i]*v1[i];       // 4개의 thread에서 하나의 sum이라는 변수를 공유하므로, lock_guard를 사용해줘야 한다. 이에 따른 병목현상으로 delay가 되는점을 주의깊게 살펴보자.
    }
    // std::cout<<"Thread end"<<std::endl;

}
void dotProductAtomic(const std::vector<int>&v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end,
                     std::atomic<unsigned long long>& sum)
{

    for(unsigned i=i_start;i<i_end;++i)
    {
        sum+=v0[i]*v1[i];       
    }

}
int dotProductFuture(const std::vector<int>&v0,
                     const std::vector<int>& v1, 
                     const unsigned i_start,
                     const unsigned i_end)
{
    int sum=0;  // local sum
    for(unsigned i=i_start;i<i_end;++i)
    {
        sum+=v0[i]*v1[i];       
    }
    return sum;
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

/* 
    std::cout<<"Naive"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        unsigned long long sum = 0;
        std::vector<std::thread> threads;
        threads.resize(n_threads);  // n_threads == 4

        const unsigned n_per_thread = n_data / n_threads; // 100'000'000 / 4 == 2500만, assumes remainder = 0
        for(unsigned t=0; t<n_threads;++t)
        {
            // threads[t]=std::thread(dotProductNaive);
            threads[t]=std::thread(dotProductNaive,std::ref(v0),std::ref(v1),t*n_per_thread,(t+1)*n_per_thread,std::ref(sum));  // std::thread를 사용할 때 함수 인자를 참조로 전달하려면 std::ref를 사용해야 합니다. 그렇지 않으면 인자가 복사됩니다


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

 */

 
    std::cout<<"LockGuard"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        unsigned long long sum = 0;
        std::vector<std::thread> threads;
        threads.resize(n_threads);  // n_threads == 4

        const unsigned n_per_thread = n_data / n_threads; // 100'000'000 / 4 == 2500만, assumes remainder = 0
        for(unsigned t=0; t<n_threads;++t)
        {
            // threads[t]=std::thread(dotProductNaive);
            threads[t]=std::thread(dotProductLock,std::ref(v0),std::ref(v1),t*n_per_thread,(t+1)*n_per_thread,std::ref(sum));  // std::thread를 사용할 때 함수 인자를 참조로 전달하려면 std::ref를 사용해야 합니다. 그렇지 않으면 인자가 복사됩니다


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

    std::cout<<"Atomic"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        std::atomic<unsigned long long> sum = 0;
        std::vector<std::thread> threads;
        threads.resize(n_threads);

        const unsigned n_per_thread = n_data / n_threads;
        for(unsigned t=0;t<n_threads;++t)
        {
            threads[t] = std::thread(dotProductAtomic,std::ref(v0),std::ref(v1),t*n_per_thread,(t+1)*n_per_thread,std::ref(sum));

        }
        for(unsigned t=0;t<n_threads;++t)
        {
            threads[t].join();
        }
        std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout <<dur.count() <<std::endl;
        std::cout <<sum <<std::endl;
        std::cout <<std::endl;

    }

    std::cout <<"Future"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        unsigned long long sum = 0;
        std::vector<std::future<int>> futures;
        futures.resize(n_threads);
        const unsigned n_per_thread = n_data / n_threads;
        for(unsigned t=0;t<n_threads;++t)
        {
            futures[t] = std::async(dotProductFuture,std::ref(v0),std::ref(v1),t*n_per_thread,(t+1)*n_per_thread);
        }
        for(unsigned t=0;t<n_threads;++t)
        {
            sum +=futures[t].get();
        }
        std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout <<dur.count() <<std::endl;
        std::cout <<sum <<std::endl;
        std::cout <<std::endl;

    }

    std::cout <<"std::transform_reduce"<<std::endl;
    {
        const auto sta = std::chrono::steady_clock::now();
        // const auto sum = std::transform_reduce(std::execution::seq, v0.begin(),v0.end(),v1.begin(),0ull);   //std::inner_product 와 사용방법은 같다. seq의 경우 직렬처리
 
        const auto sum = std::transform_reduce(std::execution::par, v0.begin(),v0.end(),v1.begin(),0ull,std::plus<>(),
            [](int x, int y) { return x * y; });   //std::inner_product 와 사용방법은 같다. par의 경우 병렬처리
        std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
        std::cout <<dur.count() <<std::endl;
        std::cout <<sum <<std::endl;
        std::cout <<std::endl;

    }

    return 0;
}